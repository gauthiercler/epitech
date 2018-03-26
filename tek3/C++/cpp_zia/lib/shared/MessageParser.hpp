//
// Created by valentin on 22/02/18.
//

#ifndef CPP_ZIA_MESSAGEPARSER_HPP
#define CPP_ZIA_MESSAGEPARSER_HPP

#include <functional>
#include "DataBuffer.hpp"
#include "MessageData.hpp"

namespace zia::shared {

    constexpr char EOL[] = "\r\n";

    constexpr char URL_BASE[] = "http://";
    constexpr int URL_BASE_LENGTH = 7;
    constexpr char URL_SECURE[] = "https://";
    constexpr int URL_SECURE_LENGTH = 8;
    constexpr char URL_ALLOWED_CHARS[] = "!*'();:@&=+$,/?#[]%-_.~";

    class MessageParser {

    public:

	enum class ParseMode {
	    REQUEST,
	    RESPONSE
	};

	enum class ParseState {
	    REQUEST_LINE,
	    HEADER,
	    MESSAGE,
	    END
	};

	using States = std::unordered_map<zia::shared::MessageParser::ParseState,
	    std::function<void ()>>;
	using Modes = std::unordered_map<zia::shared::MessageParser::ParseMode, States>;

    private:

	MessageData			&_data;
	ParseMode 			_mode;
	unsigned int			_offset;
	DataBuffer 			_db;
	ParseState 			_state;
	Modes 				_modes;

	void initModes();
	void settingContext(unsigned int offset = 0);

	void parseRequestLine();
	void parseHeader();
	void parseMessage();

	/* Request Line Parsing */

	void parseData(std::stringstream &data, std::string &method,
		       std::string &url, std::string &version);
	void parseMethod(const std::string &method);
	void parseURL(const std::string &url);
	bool cleanURL(std::string &url);
	void parseVersion(const std::string &version);

	/* Header Parsing */

	bool checkHeader();
	void fillHeaders();

	/* Message parsing */

	void passHeader();
	void parseRequestMessage();
	void parseResponseMessage();

    public:

	MessageParser(MessageData &data, ParseMode mode);
	~MessageParser() = default;

	/**
 	* Parse the data in the RequestBuilder
 	*/

	void parse();

	/**
 	* Check if the parsing of the request is end
 	* @return bool
 	*/

	bool isEnd() const;

	/**
	 * Clear the parser
	 */

	void clear();

	/**
	 * Change the parsing mode
	 * Be care, it will reset the parser
	 * @param mode
	 */

	void changeMode(ParseMode mode);

	/* Common parsing */

	static std::vector<std::string> split(const std::string &s, char delim);
	static std::string &clean(std::string &s);
	static zia::api::http::Status translateStatus(const std::string &data);

    };

}

#endif //CPP_ZIA_MESSAGEPARSER_HPP
