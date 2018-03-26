#ifndef CPP_ZIA_RESPONSESERIALIZER_HPP
#define CPP_ZIA_RESPONSESERIALIZER_HPP

#include "http.h"

namespace zia::modules::net {
  class ResponseSerializer {
  private:
      std::unordered_map<zia::api::http::Version , std::string> _httpVersion{
          {zia::api::http::Version::http_1_1, "HTTP/1.1"},
          {zia::api::http::Version::http_1_0, "HTTP/1.0"},
          {zia::api::http::Version::http_2_0, "HTTP/2.0"},
          {zia::api::http::Version::http_0_9, "HTTP/0.9"}
      };
  public:
      ResponseSerializer() = default;
      ResponseSerializer(const ResponseSerializer &responseSerializer) = default;
      virtual ~ResponseSerializer() = default;

      zia::api::Net::Raw serialize(const zia::api::HttpResponse &response) const;

      ResponseSerializer &operator=(const ResponseSerializer &) = default;

  private:
      void statusLine(std::string &response, const zia::api::HttpResponse &httpResponse) const;
      void data(std::string &response, const zia::api::HttpResponse &httpResponse) const;
      void headers(std::string &response, const zia::api::HttpResponse &httpResponse) const;
  };
}

#endif //CPP_ZIA_RESPONSESERIALIZER_HPP
