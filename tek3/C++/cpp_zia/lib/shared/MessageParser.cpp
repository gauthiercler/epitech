//
// Created by valentin on 22/02/18.
//

#include <sstream>
#include <iostream>
#include "MessageParser.hpp"
#include "ParserException.hpp"

zia::shared::MessageParser::MessageParser(zia::shared::MessageData &data,
					  zia::shared::MessageParser::ParseMode mode)
    : _data(data), _db(_data.raw), _mode(mode)
{
    if (_mode == ParseMode::REQUEST) {
	_state = ParseState::REQUEST_LINE;
	_offset = 1;
    }
    else {
	_state = ParseState::HEADER;
	_offset = 0;
    }
    initModes();
}

void zia::shared::MessageParser::initModes() {
    _modes.insert({
		      {ParseMode::REQUEST, {
					       {ParseState::REQUEST_LINE, std::bind(&MessageParser::parseRequestLine, this)},
					       {ParseState::HEADER, std::bind(&MessageParser::parseHeader, this)},
					       {ParseState::MESSAGE, std::bind(&MessageParser::parseMessage, this)}
					   }
		      },
		      {ParseMode::RESPONSE, {
						{ParseState::HEADER, std::bind(&MessageParser::parseHeader, this)},
						{ParseState::MESSAGE, std::bind(&MessageParser::parseMessage, this)}
					    }
		      }
		  });
}

void zia::shared::MessageParser::settingContext(unsigned int offset) {
    _db.reset(EOL, offset);
}

void zia::shared::MessageParser::parseRequestLine() {
    std::string data;
    std::stringstream dataStream;
    std::string method;
    std::string url;
    std::string version;
    std::string empty;

    settingContext();
    _db.getLine(data);
    if (!_db.ready(data))
	return;
    dataStream.str(data);
    parseData(dataStream, method, url, version);
    dataStream >> empty;
    if (!empty.empty())
	throw ParserException("Request Line badly formated, too long");
    parseMethod(method);
    parseURL(url);
    parseVersion(version);
    _state = ParseState::HEADER;
    parseHeader();
}

void
zia::shared::MessageParser::parseData(std::stringstream &data,
				       std::string &method,
				       std::string &url,
				       std::string &version) {
    data >> method;
    data >> url;
    data >> version;
}

void zia::shared::MessageParser::parseMethod(const std::string &method) {
    static const std::unordered_map<std::string, zia::api::http::Method> _methodMap = {
	{"OPTIONS", zia::api::http::Method::options}, {"GET", zia::api::http::Method::get}, {"HEAD", zia::api::http::Method::head},
	{"POST", zia::api::http::Method::post}, {"PUT", zia::api::http::Method::put}, {"DELETE", zia::api::http::Method::delete_},
	{"TRACE", zia::api::http::Method::trace}, {"CONNECT", zia::api::http::Method::connect}
    };

    const auto &m = _methodMap.find(method);
    if (m == _methodMap.end()) {
	std::string error("Error during the method parsing, unknown method : ");
	error.append(method);
	throw ParserException(error);
    }
    _data.method = m->second;
}

void zia::shared::MessageParser::parseURL(const std::string &url) {
    std::string clean(url);

    if (!cleanURL(clean))
	throw ParserException("Error during the URL parsing bad format");
    const auto &posURI = clean.find_first_of('/');
    if (posURI == std::string::npos)
	_data.host = clean;
    else {
	_data.host = clean.substr(0, posURI);
	_data.uri = clean.substr(posURI);
    }
}

bool zia::shared::MessageParser::cleanURL(std::string &url) {
    const auto &posBase = url.find(URL_BASE);
    const auto &posSSL = url.find(URL_SECURE);
    const std::string urlAllowedChars(URL_ALLOWED_CHARS);

    if (posBase != std::string::npos)
	url = url.substr(URL_BASE_LENGTH);
    if (posSSL != std::string::npos)
	url = url.substr(URL_SECURE_LENGTH);
    for (const auto &c : url) {
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <='Z') || (c >= '0' && c <= '9')))
	    if (urlAllowedChars.find_first_of(c) == std::string::npos)
		return (false);
    }
    return (true);
}

void zia::shared::MessageParser::parseVersion(const std::string &version) {
    static const std::unordered_map<std::string, zia::api::http::Version> _versionMap = {
	{"HTTP/0.9", zia::api::http::Version::http_0_9}, {"HTTP/1.0", zia::api::http::Version::http_1_0},
	{"HTTP/1.1", zia::api::http::Version::http_1_1}, {"HTTP/2.0", zia::api::http::Version::http_2_0}
    };

    const auto &m = _versionMap.find(version);
    if (m == _versionMap.end()) {
	std::string error("Error during the method parsing, unknown version : ");
	error.append(version);
	throw ParserException(error);
    }
    _data.version = m->second;
}

void zia::shared::MessageParser::parseHeader() {
    if (!checkHeader())
	return;
    fillHeaders();
    try {
	_data.host = _data.headers.at("Host")[0];
    } catch (std::exception &e) {}
    _state = ParseState::MESSAGE;
    parseMessage();
}

bool zia::shared::MessageParser::checkHeader() {
    std::string line;

    settingContext(_offset);
    while (_db.getLine(line)) {
	if (!_db.ready(line))
	    return (false);
	if (line.empty())
	    return (true);
    }
    return (false);
}

void zia::shared::MessageParser::fillHeaders() {
    std::string line;
    std::string key;
    std::string value;
    std::string word;
    DataBuffer buff(value);

    settingContext(_offset); // Offset to avoid getting Request Line
    while (_db.getLine(line) && !line.empty()) {
	const auto &posKey = line.find_first_of(':');
	if (posKey == std::string::npos)
	    throw ParserException("Request header badly formated, no \':\'");
	key = line.substr(0, posKey);
	value = line.substr(posKey + 1); // Offset to avoid the ':' token
	_data.headers.insert({key, split(value, ',')});
    }
}

void zia::shared::MessageParser::parseMessage() {
    std::string line;

    try {
	if (_mode == ParseMode::REQUEST)
	    parseRequestMessage();
	else
	    parseResponseMessage();
    } catch (std::exception &e) {
	_state = ParseState::END;
	return;
    }
}

std::vector<std::string>
zia::shared::MessageParser::split(const std::string &s, char delim) {
    std::stringstream data(s);
    std::string token;
    std::vector<std::string> result;

    while (std::getline(data, token, delim))
	result.emplace_back(clean(token));
    return (result);
}

std::string &zia::shared::MessageParser::clean(std::string &s) {
    size_t i = 0;

    while (s[i] == ' ' || s[i] == '\t')
	i += 1;
    s.erase(0, i);
    while (s.back() == ' ' || s.back() == '\t')
	s.pop_back();
    return (s);
}

bool zia::shared::MessageParser::isEnd() const {
    return (_state == ParseState::END);
}

void zia::shared::MessageParser::parse() {
    if (_state == ParseState::END)
	return;
    _modes[_mode][_state]();
}

void zia::shared::MessageParser::clear() {
    _data.host.clear();
    _data.uri.clear();
    _data.method = zia::api::http::Method::unknown;
    _data.version = zia::api::http::Version::unknown;
    _data.headers.clear();
    _data.raw.clear();
    _state = ParseState::REQUEST_LINE;
    settingContext();
}

void zia::shared::MessageParser::changeMode(
    zia::shared::MessageParser::ParseMode mode) {
    _mode = mode;
    clear();
}

zia::api::http::Status zia::shared::MessageParser::translateStatus(const std::string &data) {
    try {
	const auto &value = std::stol(data);
	return (static_cast<zia::api::http::Status>(value));
    } catch (std::exception &e) {
	throw ParserException("Error couldn't translate a status, bad format");
    }
}

void zia::shared::MessageParser::passHeader() {
    std::string line;

    settingContext(_offset);
    while (_db.getLine(line) && !line.empty()); // Pass all the header of the request
}

void zia::shared::MessageParser::parseRequestMessage() {
    std::string raw;
    std::string line;

    const auto &length = _data.headers.at("Content-Length")[0];
    const auto &size = std::stol(length);
    passHeader();
    while (_db.getLine(line)) {
	if (_db.ready(line))
	    line += "\r\n";
	raw += line;
    }
    if (raw.size() != size)
	return; // Msg isn't totaly send
    else {
	_data.msg = raw;
	_state = ParseState::END;
    }
}

void zia::shared::MessageParser::parseResponseMessage() {
    std::string line;

    passHeader();
    _db.getLine(line);
    _data.msg = line;
    _state = ParseState::END;
}
