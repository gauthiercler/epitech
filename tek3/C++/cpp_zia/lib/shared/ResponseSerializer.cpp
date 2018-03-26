#include <nobyte/NoByte.hpp>
#include "ResponseSerializer.hpp"

zia::api::Net::Raw zia::modules::net::ResponseSerializer::serialize(const zia::api::HttpResponse &httpResponse) const {
    std::string response;

    statusLine(response, httpResponse);
    headers(response, httpResponse);
    response += "\r\n";
    data(response, httpResponse);
    return noByte::toByte(response);
}

void zia::modules::net::ResponseSerializer::statusLine(std::string &response, const zia::api::HttpResponse &httpResponse) const {
    try {
        response = _httpVersion.at(httpResponse.version) + " " + std::to_string(httpResponse.status) + " " + httpResponse.reason + "\r\n";
    } catch (const std::exception &e) {
        response = "HTTP/1.1 500 Internal Server Error\r\n";
    }
}

void zia::modules::net::ResponseSerializer::data(std::string &response, const zia::api::HttpResponse &httpResponse) const {
    response += noByte::toString(httpResponse.body) + "\r\n";
}

void zia::modules::net::ResponseSerializer::headers(std::string &response, const zia::api::HttpResponse &httpResponse) const {
    for (const auto &header : httpResponse.headers) {
        response += header.first + ": " + header.second + "\r\n";
    }
}
