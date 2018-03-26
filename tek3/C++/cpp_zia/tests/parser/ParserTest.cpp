//
// Created by valentin on 16/02/18.
//

#include <gtest/gtest.h>
#include <shared/ResponseBuilder.hpp>
#include "shared/RequestBuilder.hpp"

TEST(REQUEST_PARSER, DataBuffer) {
    std::string data;
    zia::shared::DataBuffer db(data);
    std::string line;

    db.split("\r\n");
    db.getLine(line);
    ASSERT_EQ(line, "");
    data += "CECI EST UN TEST\r\n";
    db.reset("\r\n");
    db.getLine(line);
    ASSERT_EQ(line, "CECI EST UN TEST");
    data += "Je suis op sur le parsing\r\n";
    db.reset("\r\n");
    db.getLine(line);
    ASSERT_EQ(line, "CECI EST UN TEST");
    db.getLine(line);
    ASSERT_EQ(line, "Je suis op sur le parsing");
    const auto &ret = db.getLine(line);
    ASSERT_EQ(ret, false);
}

TEST(REQUEST_PARSER, DataBuffer_READY) {
    std::string data;
    zia::shared::DataBuffer db(data);
    std::string line;

    data += "CECI EST UN TEST";
    db.split("\r\n");
    db.getLine(line);
    ASSERT_EQ(db.ready(line), false);
    data += "\r\n";
    db.reset("\r\n");
    db.getLine(line);
    ASSERT_EQ(db.ready(line), true);
    data += "Lel la suite";
    db.reset("\r\n");
    db.getLine(line);
    ASSERT_EQ(db.ready(line), true);
    db.getLine(line);
    ASSERT_EQ(db.ready(line), false);
    data += "\r\n";
    db.reset("\r\n");
    db.getLine(line);
    ASSERT_EQ(db.ready(line), true);
    db.getLine(line);
    ASSERT_EQ(db.ready(line), true);
}

TEST(REQUEST_PARSER, Request_Line) {
    zia::shared::RequestBuilder rb;

    rb.fill("GET / HTTP/1.1\r\n"
		"Host: localhost:8080\r\n"
		"Connection: keep-alive\r\n"
		"User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36\r\n"
		"Upgrade-Insecure-Requests: 1\r\n"
		"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n"
		"Accept-Encoding: gzip, deflate, br\r\n"
		"Accept-Language: fr-FR,fr;q=0.9,en-US;q=0.8,en;q=0.7\r\n"
		"\r\n");
    try {
	while (!rb.isEnd())
	    rb.parse();
	const auto &req = rb.build();
	if (req.method == zia::api::http::Method::get)
	    std::cout << std::endl << "GET Method" << std::endl;
	std::cout << "Request body : " << req.body << std::endl;
    } catch (const std::exception &e) {
	std::cout << "[ERROR] " << e.what() << std::endl;
    }
}

TEST(TRANSLATING_PARSER, TranslateStatus) {
    const auto &status = zia::shared::MessageParser::translateStatus("200");
    ASSERT_EQ(status, zia::api::http::common_status::ok);
}

TEST(RESPONSE_PARSER, Basic) {
    zia::shared::ResponseBuilder resp;

    resp.fill("Content-type: text/html; charset=UTF-8\r\n\r\n<p>toto</p>");
    resp.parse();
    ASSERT_EQ(resp.isEnd(), true);
    const auto &res = resp.build();
    ASSERT_EQ(res.statusCode, 200);
    ASSERT_EQ(res.body, "<p>toto</p>");
}

TEST(RESPONSE_PARSER, Medium) {
    zia::shared::RequestBuilder req;

    req.fill("POST / HTTP/1.1\r\n"
		  "cache-control: no-cache\r\n"
		  "Postman-Token: fe62fcbb-83ec-4e34-b128-e31b8e6c2a8b\r\n"
		  "User-Agent: PostmanRuntime/7.1.1\r\n"
		  "Accept: */*\r\n"
		  "Host: localhost:8080\r\n"
		  "accept-encoding: gzip, deflate\r\n"
		  "content-type: multipart/form-data; boundary=--------------------------433264981092360821959741\r\n"
		  "content-length: 163\r\n"
		  "Connection: keep-alive\r\n"
		  "\r\n"
		  "----------------------------433264981092360821959741\r\n"
		  "Content-Disposition: form-data; name=\"toto\"\r\n"
		  "\r\n"
		  "titi\r\n"
		  "----------------------------433264981092360821959741--\r\n");
    req.parse();
    ASSERT_EQ(req.isEnd(), true);
    const auto &res = req.build();
    std::cout << std::endl << "Body : " << res.body << std::endl;
}