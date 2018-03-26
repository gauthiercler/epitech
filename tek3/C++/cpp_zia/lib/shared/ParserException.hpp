//
// Created by valentin on 16/02/18.
//

#ifndef CPP_ZIA_REQUESTLINEEXCEPTION_HPP
#define CPP_ZIA_REQUESTLINEEXCEPTION_HPP

#include <stdexcept>

namespace zia::shared {
    class ParserException : public std::runtime_error
    {
	std::string _what;

    public:
	ParserException(const std::string &msg)
	: std::runtime_error(msg), _what("RequestParser Error in Request Line :\n")
	{
	    _what.append(msg);
	}
	~ParserException() = default;

	const char *what() const noexcept override
	{
	    return _what.c_str();
	}
    };
}

#endif //CPP_ZIA_REQUESTLINEEXCEPTION_HPP
