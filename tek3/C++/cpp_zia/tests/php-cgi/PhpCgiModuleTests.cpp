#include <gtest/gtest.h>
#include "php-cgi/phpCgiModule.hpp"
#include "nobyte/NoByte.hpp"

static zia::modules::php::PhpCgiModule setup() {
    zia::modules::php::PhpCgiModule module;
    zia::api::Conf generalConfiguration;
    zia::api::ConfObject phpCgiConfiguration;

    phpCgiConfiguration["web_path"].v = std::string("/var/www/tests");
    phpCgiConfiguration["cgi_path"].v = std::string("/usr/bin/php-cgi");
    generalConfiguration["php_cgi"].v = phpCgiConfiguration;

    module.config(generalConfiguration);
    return module;
}

TEST(phpCgiModule, noConfig) {
    zia::modules::php::PhpCgiModule module;
    zia::api::Conf conf;

    ASSERT_FALSE(module.config(conf));
}

TEST(phpCgiModule, validConfig) {
    zia::modules::php::PhpCgiModule module;
    zia::api::Conf generalConfiguration;
    zia::api::ConfObject phpCgiConfiguration;

    phpCgiConfiguration["web_path"].v = std::string("/var/www/html");
    phpCgiConfiguration["cgi_path"].v = std::string("/usr/bin/php-cgi");
    generalConfiguration["php_cgi"].v = phpCgiConfiguration;

    ASSERT_TRUE(module.config(generalConfiguration));
}

TEST(phpCgiModule, inconsistantConfig) {
    zia::modules::php::PhpCgiModule module;
    zia::api::Conf generalConfiguration;
    zia::api::ConfObject phpCgiConfiguration;

    phpCgiConfiguration["web_path"].v = std::string("/var/www/html");
    phpCgiConfiguration["cgi_path"].v = std::string("/toto");
    generalConfiguration["php_cgi"].v = phpCgiConfiguration;

    ASSERT_FALSE(module.config(generalConfiguration));
}

TEST(phpCgiModule, minimalRequest) {
    zia::modules::php::PhpCgiModule module = setup();
    zia::api::HttpDuplex duplex;
    std::string rawRequest("GET / HTTP/1.1\r\n"
                               "Host: 127.0.0.1\r\n"
                               "User-Agent: gtest\r\n"
                               "Accept: text/html\r\n");

    duplex.info.ip.i = 0; // TODO Put the right number
    duplex.info.ip.str = "127.0.0.1";
    duplex.raw_req = noByte::toByte(rawRequest);
    duplex.req.headers["Host"] = "127.0.0.1";
    duplex.req.headers["User-Agent"] = "gtest";
    duplex.req.headers["Accept"] = "text/html";
    duplex.req.method = zia::api::http::Method::get;
    duplex.req.uri = "/index.php";
    duplex.req.version = zia::api::http::Version::http_1_1;

    ASSERT_FALSE(module.exec(duplex));
    ASSERT_EQ(duplex.resp.status, zia::api::http::common_status::created);
    ASSERT_EQ(duplex.resp.version, zia::api::http::Version::http_1_1);
    ASSERT_EQ(noByte::toString(duplex.resp.body), "It works!");
}

TEST(phpCgiModule, getParameters) {
    zia::modules::php::PhpCgiModule module = setup();
    zia::api::HttpDuplex duplex;
    std::string rawRequest("GET / HTTP/1.1\r\n"
                               "Host: 127.0.0.1\r\n"
                               "User-Agent: gtest\r\n"
                               "Accept: text/html\r\n");

    duplex.info.ip.i = 0; // TODO Put the right number
    duplex.info.ip.str = "127.0.0.1";
    duplex.raw_req = noByte::toByte(rawRequest);
    duplex.req.headers["Host"] = "127.0.0.1";
    duplex.req.headers["User-Agent"] = "gtest";
    duplex.req.headers["Accept"] = "text/html";
    duplex.req.method = zia::api::http::Method::get;
    duplex.req.uri = "/get.php?toto=hey!";
    duplex.req.version = zia::api::http::Version::http_1_1;

    ASSERT_FALSE(module.exec(duplex));
    ASSERT_EQ(duplex.resp.status, zia::api::http::common_status::ok);
    ASSERT_EQ(duplex.resp.version, zia::api::http::Version::http_1_1);
    ASSERT_EQ(noByte::toString(duplex.resp.body), "hey!");
}

TEST(phpCgiModule, postParameters) {
    zia::modules::php::PhpCgiModule module = setup();
    zia::api::HttpDuplex duplex;
    std::string body("----------------------------389474467305630273847871\r\n"
                        "Content-Disposition: form-data; name=\"toto\"\r\n"
                        "\r\n"
                        "titi\r\n"
                        "----------------------------389474467305630273847871--\r\n");
    std::string rawRequest("POST /post.php HTTP/1.1\r\n"
                               "User-Agent: gtest\r\n"
                               "Accept: text/html\r\n"
                               "Host: 127.0.0.1\r\n"
                               "Content-Type: multipart/form-data; boundary=--------------------------389474467305630273847871\r\n"
                               "Content-Length: 163\r\n"
                               "\r\n" +
                               body);

    duplex.info.ip.i = 0; // TODO Put the right number
    duplex.info.ip.str = "127.0.0.1";
    duplex.raw_req = noByte::toByte(rawRequest);
    duplex.req.headers["Host"] = "127.0.0.1";
    duplex.req.headers["User-Agent"] = "gtest";
    duplex.req.headers["Accept"] = "text/html";
    duplex.req.headers["Content-Type"] = "multipart/form-data; boundary=--------------------------389474467305630273847871";
    duplex.req.headers["Content-Length"] = "163";
    duplex.req.method = zia::api::http::Method::post;
    duplex.req.uri = "/post.php";
    duplex.req.body = noByte::toByte(body);
    duplex.req.version = zia::api::http::Version::http_1_1;

    ASSERT_FALSE(module.exec(duplex));
    ASSERT_EQ(duplex.resp.status, zia::api::http::common_status::ok);
    ASSERT_EQ(duplex.resp.version, zia::api::http::Version::http_1_1);
    ASSERT_EQ(noByte::toString(duplex.resp.body), "titi");
}

TEST(phpCgiModule, getHeaders) {
    zia::modules::php::PhpCgiModule module = setup();
    zia::api::HttpDuplex duplex;
    std::string rawRequest("GET / HTTP/1.1\r\n"
                               "Host: 127.0.0.1\r\n"
                               "User-Agent: gtest\r\n"
                               "Accept: text/html\r\n");

    duplex.info.ip.i = 0; // TODO Put the right number
    duplex.info.ip.str = "127.0.0.1";
    duplex.raw_req = noByte::toByte(rawRequest);
    duplex.req.headers["Host"] = "127.0.0.1";
    duplex.req.headers["User-Agent"] = "gtest";
    duplex.req.headers["Accept"] = "text/html";
    duplex.req.headers["toto"] = "ok";
    duplex.req.method = zia::api::http::Method::get;
    duplex.req.uri = "/headers.php";
    duplex.req.version = zia::api::http::Version::http_1_1;

    ASSERT_FALSE(module.exec(duplex));
    ASSERT_EQ(duplex.resp.status, zia::api::http::common_status::ok);
    ASSERT_EQ(duplex.resp.version, zia::api::http::Version::http_1_1);
    ASSERT_EQ(noByte::toString(duplex.resp.body), "ok");
}