#ifndef CPP_ZIA_REQUEST_HPP
#define CPP_ZIA_REQUEST_HPP

#include <http.h>
#include <pp/http.hpp>
#include <iostream>
#include <unordered_map>
#include "DataBuffer.hpp"
#include "MessageData.hpp"
#include "MessageParser.hpp"

namespace zia::shared {

    class RequestBuilder {

    private:

	MessageData			_data;
	MessageParser			_parser;

    public:

	RequestBuilder();
	RequestBuilder(const RequestBuilder &request) = default;
	virtual ~RequestBuilder() = default;

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

	zia::apipp::Request build() const;

	/**
	 * Clear all the data that the RequestBuilder get from the data
	 * Ready to handle a new request.
	 */

	void clear();

	RequestBuilder &operator=(const RequestBuilder &request) = default;

    };
}


#endif //CPP_ZIA_REQUEST_HPP
