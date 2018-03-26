//
// Created by valentin on 22/02/18.
//

#ifndef CPP_ZIA_RESPONSEBUILDER_HPP
#define CPP_ZIA_RESPONSEBUILDER_HPP

#include <pp/http.hpp>
#include <unordered_map>
#include "MessageData.hpp"
#include "MessageParser.hpp"

namespace zia::shared {

    class ResponseBuilder {

    private:

	MessageData			_data;
	MessageParser			_parser;
        const std::string		_noReason = "No Reason Phrase";
        const std::unordered_map<zia::api::http::Status , std::string> _httpMessages = {
	  {zia::api::http::common_status::continue_, "Continue"},
	  {zia::api::http::common_status::switching_protocols, "Switching Protocols"},
	  {zia::api::http::common_status::ok, "OK"},
	  {zia::api::http::common_status::created, "Created"},
	  {zia::api::http::common_status::accepted, "Accepted"},
	  {zia::api::http::common_status::nonauthoritative_information, "Non-Authoritative Information"},
	  {zia::api::http::common_status::no_content, "No Content"},
	  {zia::api::http::common_status::reset_content, "Reset Content"},
	  {zia::api::http::common_status::partial_content, "Partial Content"},
	  {zia::api::http::common_status::multiple_choices, "Multiple Choices"},
	  {zia::api::http::common_status::moved_permanently, "Moved Permanently"},
	  {zia::api::http::common_status::found, "Found"},
	  {zia::api::http::common_status::see_other, "See Other"},
	  {zia::api::http::common_status::not_modified, "Not Modified"},
	  {zia::api::http::common_status::use_proxy, "Use Proxy"},
	  {zia::api::http::common_status::temporary_redirect, "Temporary Redirect"},
	  {zia::api::http::common_status::bad_request, "Bad Request"},
	  {zia::api::http::common_status::unauthorized, "Unauthorized"},
	  {zia::api::http::common_status::payment_required, "Payment Required"},
	  {zia::api::http::common_status::forbidden, "Forbidden"},
	  {zia::api::http::common_status::not_found, "Not Found"},
	  {zia::api::http::common_status::method_not_allowed, "Method Not Allowed"},
	  {zia::api::http::common_status::not_acceptable, "Not Acceptable"},
	  {zia::api::http::common_status::proxy_authentication_required, "Proxy Authentication Required"},
	  {zia::api::http::common_status::request_timeout, "Request Timeout"},
	  {zia::api::http::common_status::conflict, "Conflict"},
	  {zia::api::http::common_status::gone, "Gone"},
	  {zia::api::http::common_status::length_required, "Length Required"},
	  {zia::api::http::common_status::precondition_failed, "Precondition Failed"},
	  {zia::api::http::common_status::request_entity_too_large, "Request Entity Too Large"},
	  {zia::api::http::common_status::request_uri_too_large, "Request-URI Too Long"},
	  {zia::api::http::common_status::unsupported_media_type, "Unsupported Media Type"},
	  {zia::api::http::common_status::requested_range_not_satisfiable, "Requested Range Not Satisfiable"},
	  {zia::api::http::common_status::expectation_failed, "Expectation Failed"},
	  {zia::api::http::common_status::im_a_teapot, "I'm a teapot"},
	  {zia::api::http::common_status::internal_server_error, "Internal Server Error"},
	  {zia::api::http::common_status::not_implemented, "Not Implemented"},
	  {zia::api::http::common_status::bad_gateway, "Bad Gateway"},
	  {zia::api::http::common_status::service_unavailable, "Service Unavailable"},
	  {zia::api::http::common_status::gateway_timeout, "Gateway Timeout"},
	  {zia::api::http::common_status::http_version_not_supported, "HTTP Version Not Supported"}
	};

	zia::api::http::Status getStatus() const;
        const std::string &getReason(zia::api::http::Status status) const;

    public:

	ResponseBuilder();
	ResponseBuilder(const ResponseBuilder &request) = default;
	virtual ~ResponseBuilder() = default;

	/**
	 * Fill the RequestBuilder with data
	 * @param str
	 */

	void fill(const std::string &str);

	/**
	 * Parse the data in the RequestBuilder
	 */

	void parse();

	/**
	 * Check if the parsing of the request is end
	 * @return bool
	 */

	bool isEnd() const;

	zia::apipp::Response build() const;

	/**
	 * Clear all the data that the RequestBuilder get from the data
	 * Ready to handle a new request.
	 */

	void clear();

	ResponseBuilder &operator=(const ResponseBuilder &request) = default;

    };

}

#endif //CPP_ZIA_RESPONSEBUILDER_HPP
