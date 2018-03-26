#include <unistd.h>
#include <nobyte/NoByte.hpp>
#include <shared/ResponseBuilder.hpp>
#include <shared/RequestBuilder.hpp>
#include "phpCgiModule.hpp"
#include "Executer.hpp"

bool zia::modules::php::PhpCgiModule::config(const zia::api::Conf &conf) {
    try {
        zia::api::ConfObject cgiConfiguration = std::get<zia::api::ConfObject>(conf.at("php_cgi").v);

        _cgiPath = std::get<std::string>(cgiConfiguration.at("cgi_path").v);
        _webPath = std::get<std::string>(cgiConfiguration.at("web_path").v);

        return isValid();
    } catch (const std::exception &e) {
        return false;
    }
}

bool zia::modules::php::PhpCgiModule::perform() {
    std::unordered_map<std::string, std::string> env;
    zia::modules::php::Executer executer;
    zia::shared::ResponseBuilder responseBuilder;

    env["REDIRECT_STATUS"] = "true";
    env["SCRIPT_FILENAME"] = _webPath + getRequestFile();
    env["QUERY_STRING"] = getQuery();
    if (request->method != zia::api::http::Method::get)
        handlePostData(env, request);
    exportHeaders(env, request);
    std::stringstream &result = executer.run(_cgiPath, env, noByte::toString(request->rawBody));
    responseBuilder.fill(result.rdbuf()->str());
    responseBuilder.parse();
    response = std::make_shared<apipp::Response>(responseBuilder.build());
    return false;
}

bool zia::modules::php::PhpCgiModule::isValid() const {
    bool status = true;

    status = status && !_webPath.empty() && !_cgiPath.empty();
    status = status && access(_cgiPath.c_str(), F_OK | X_OK) == 0;
    return status;
}

void zia::modules::php::PhpCgiModule::updateResponse(const zia::api::HttpResponse &response) {
    zia::api::HttpDuplex duplex;

    duplex.resp = response;
    this->response = zia::apipp::Response::fromBasicHttpDuplex(duplex);
}

std::string zia::modules::php::PhpCgiModule::getRequestFile() const {
    auto end = std::find_if(request->uri.begin(), request->uri.end(), [&](const char &c) {
        return c == '?';
    });
    return std::move(std::string(request->uri.begin(), end));
}

std::string zia::modules::php::PhpCgiModule::getQuery() const {
    auto start = std::find_if(request->uri.begin(), request->uri.end(), [&](const char &c) {
        return c == '?';
    });
    if (start != request->uri.end())
        start += 1;
    return std::string(start, request->uri.end());
}

void zia::modules::php::PhpCgiModule::handlePostData(std::unordered_map<std::string, std::string> &env, const zia::apipp::RequestPtr &request) {
    try {
        env["CONTENT_TYPE"] = request->headers.at("Content-Type")[0];
        env["CONTENT_LENGTH"] = request->headers.at("Content-Length")[0];
        env["REQUEST_METHOD"] = "POST";
    } catch (const std::exception &e) {
        std::clog << "[WARNING][PHP] Invalid post request handled" << e.what() << std::endl;
    }
}

void zia::modules::php::PhpCgiModule::exportHeaders(std::unordered_map<std::string, std::string> &env, const zia::apipp::RequestPtr &request) const {
    for (auto &header : request->headers) {
        std::string name("HTTP_" + header.first);
        std::string value;
        bool first = true;

        for (auto &v : header.second) {
            if (!first)
                value += ", ";
            value += v;
            first = false;
        }
        std::transform(name.begin(), name.end(),name.begin(), ::toupper);
        env[name] = value;
    }
}

zia::api::Module *create() {
    auto *module = new zia::modules::php::PhpCgiModule;

    return module;
}
