
#pragma once

#include <memory>
#include <sstream>
#include <utility>
#include <algorithm>
#include <utility>
#include <nobyte/NoByte.hpp>
#include <iostream>
#include "../http.h"

namespace zia::apipp {

    class Request {
    private:
        bool useRawBody = false;

    public:
        const zia::api::http::Version version{};
        std::map<std::string, std::vector<std::string>> headers;
        std::string body{};
        zia::api::Net::Raw rawBody{};
        const zia::api::http::Method method{};
        const std::string uri;
        const zia::api::Net::Raw inputRawData{}; // Shouldn't be modified

        Request(const zia::api::http::Version version, const zia::api::http::Method method, const std::string &uri)
                : version{version}, method{method}, uri(uri) {}

        explicit Request(const zia::api::HttpDuplex &duplex)
                : version{duplex.req.version}, rawBody{duplex.req.body},
                  method{duplex.req.method}, uri{duplex.req.uri},
                  inputRawData{duplex.raw_req} {

            // Transform raw data to standard data
            std::transform(duplex.req.body.begin(), duplex.req.body.end(), std::back_inserter(this->body),
                           [](auto c) { return static_cast<char>(c); });

            // Transform basic map<string, string> to map<string, vector<string>>
            for (const auto &item : duplex.req.headers) {
                std::stringstream ss(item.second);
                std::string res;
                while (std::getline(ss, res, ',')) {
                    this->headers[item.first].push_back(res);
                }
            }
        }

        static std::shared_ptr<Request> fromBasicHttpDuplex(zia::api::HttpDuplex &duplex) {
            return std::make_shared<Request>(duplex);
        }

        zia::api::HttpRequest toBasicHttpRequest() const {
            std::map<std::string, std::string> basicHeaders;

            for (const auto &item : this->headers) {
                for (const auto &value: item.second) {
                    basicHeaders[item.first] += value + ", ";
                }
                auto &tmp = basicHeaders[item.first];
                basicHeaders[item.first] = tmp.substr(0, tmp.length() - 2);
            }

            if (this->useRawBody) {
                return zia::api::HttpRequest{this->version, basicHeaders, this->rawBody, this->method, this->uri};
            } else {
                std::vector<std::byte> basicBody;

                std::transform(this->body.begin(), this->body.end(), std::back_inserter(basicBody),
                               [](auto c) { return static_cast<std::byte>(c); });

                return zia::api::HttpRequest{this->version, basicHeaders, basicBody, this->method, this->uri};
            }
        }
    };

    class Response {
    private:
        bool useRawBody = false;

    public:
        const zia::api::http::Version version{};
        std::map<std::string, std::vector<std::string>> headers;
        std::string body{};
        zia::api::Net::Raw rawBody{};
        int statusCode{0};
        std::string statusReason{};
        const zia::api::Net::Raw outputRawData{}; // Shouldn't be modified

        explicit Response(const Request &request) : version{request.version} {}

        explicit Response(const zia::api::HttpDuplex &duplex)
                : version{duplex.resp.version},
                  headers{},
                  body{},
                  rawBody{duplex.resp.body},
                  statusCode{duplex.resp.status},
                  statusReason{duplex.resp.reason},
                  outputRawData{duplex.raw_resp} {

            // Transform raw data to standard data
            std::transform(duplex.resp.body.begin(), duplex.resp.body.end(), std::back_inserter(this->body),
                           [](auto c) { return static_cast<char>(c); });

            // Transform basic map<string, string> to map<string, vector<string>>
            for (const auto &item : duplex.resp.headers) {
                std::stringstream ss(item.second);
                std::string res;
                while (std::getline(ss, res, ',')) {
                    this->headers[item.first].push_back(res);
                }
            }
        }

        Response *useRawData() {
            this->useRawBody = true;
            return this;
        }

        Response *useStandardData() {
            this->useRawBody = false;
            return this;
        }

        Response *setStandardData(const std::string &data) {
            this->body = data;
            return this;
        }

        Response *appendStandardData(const std::string &data) {
            this->body += data;
            return this;
        }

        Response *prependStandardData(const std::string &data) {
            this->body = data + this->body;
            return this;
        }

        Response *addHeader(const std::string &name, const std::string &value) {
            this->headers[name].push_back(value);
            return this;
        }

        Response *addHeaders(const std::string &name, const std::vector<std::string> &values) {
            for (const auto &item : values) {
                this->headers[name].push_back(item);
            }
            return this;
        }

        Response *removeAllHeadersByName(const std::string &name) {
            this->headers.erase(name);
            return this;
        }

        Response *setStatus(int code, const std::string &reason) {
            this->statusCode = code;
            this->statusReason = reason;
            return this;
        }

        static std::shared_ptr<Response> fromBasicHttpDuplex(zia::api::HttpDuplex &duplex) {
            return std::make_shared<Response>(duplex);
        }

        zia::api::HttpResponse toBasicHttpResponse() const {
            std::map<std::string, std::string> basicHeaders;

            for (const auto &item : this->headers) {
                for (const auto &value: item.second) {
                    basicHeaders[item.first] += value + ", ";
                }
                auto &tmp = basicHeaders[item.first];
                basicHeaders[item.first] = tmp.substr(0, tmp.length() - 2);
            }

            if (this->useRawBody) {
                return zia::api::HttpResponse{this->version, basicHeaders, this->rawBody,
                                              this->statusCode, this->statusReason};
            } else {
                std::vector<std::byte> basicBody;

                std::transform(this->body.begin(), this->body.end(), std::back_inserter(basicBody),
                               [](auto c) { return static_cast<std::byte>(c); });

                return zia::api::HttpResponse{this->version, basicHeaders, basicBody,
                                              this->statusCode, this->statusReason};
            }
        }
    };

    using ResponsePtr = std::shared_ptr<Response>;
    using RequestPtr = std::shared_ptr<Request>;

    static zia::api::HttpDuplex
    createBasicHttpDuplex(const RequestPtr &request, const ResponsePtr &response, const zia::api::NetInfo &net) {
        return zia::api::HttpDuplex{net, request->inputRawData, response->outputRawData,
                                    request->toBasicHttpRequest(), response->toBasicHttpResponse()};
    }

}
