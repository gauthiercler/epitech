//
// Created by valentin on 22/02/18.
//

#include <iostream>
#include "ResponseBuilder.hpp"

zia::shared::ResponseBuilder::ResponseBuilder()
    : _parser(_data, MessageParser::ParseMode::RESPONSE)
{}

void zia::shared::ResponseBuilder::fill(const std::string &str) {
    _data.raw += str;
}

bool zia::shared::ResponseBuilder::isEnd() const {
    return (_parser.isEnd());
}

void zia::shared::ResponseBuilder::parse() {
    if (_parser.isEnd())
	return;
    _parser.parse();
}

void zia::shared::ResponseBuilder::clear() {
    _parser.clear();
}

zia::apipp::Response zia::shared::ResponseBuilder::build() const {
    zia::api::HttpDuplex httpDuplex;
    httpDuplex.resp.version = zia::api::http::Version::http_1_1;
    httpDuplex.resp.status = getStatus();
    httpDuplex.resp.reason = getReason(httpDuplex.resp.status);
    zia::apipp::Response res(httpDuplex);

    res.headers = _data.headers;
    res.body = _data.msg;
    return (std::move(res));
}

zia::api::http::Status zia::shared::ResponseBuilder::getStatus() const {
    try {
	const auto &statusStr = _data.headers.at("Status")[0];
	return (zia::shared::MessageParser::translateStatus(statusStr));
    } catch (std::exception &e) {
	return (200);
    }
}

const std::string &zia::shared::ResponseBuilder::getReason(zia::api::http::Status status) const {
  try {
    const std::string &reason = this->_httpMessages.at(status);
    return (reason);
  } catch (std::exception &e) {
    return (this->_noReason);
  }
}
