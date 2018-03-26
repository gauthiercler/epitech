#include <sstream>
#include <nobyte/NoByte.hpp>
#include "RequestBuilder.hpp"
#include "ParserException.hpp"

zia::shared::RequestBuilder::RequestBuilder()
: _parser(_data, MessageParser::ParseMode::REQUEST)
{}

void zia::shared::RequestBuilder::fill(const std::string &str) {
    _data.raw += str;
}

bool zia::shared::RequestBuilder::isEnd() const {
    return (_parser.isEnd());
}

void zia::shared::RequestBuilder::parse() {
    if (_parser.isEnd())
	return;
    _parser.parse();
}

void zia::shared::RequestBuilder::clear() {
    _parser.clear();
}

zia::apipp::Request zia::shared::RequestBuilder::build() const {
    std::string uri = _data.uri;
    zia::apipp::Request req(_data.version, _data.method, std::move(uri));
    zia::api::Net::Raw &raw = *const_cast<zia::api::Net::Raw *>(&req.inputRawData);

    raw = noByte::toByte(_data.raw);
    req.headers = _data.headers;
    req.body = _data.msg;
    req.rawBody = noByte::toByte(_data.msg);
    return (std::move(req));
}