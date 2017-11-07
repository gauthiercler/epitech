#ifndef CPP_SPIDER_ERROR_HPP
#define CPP_SPIDER_ERROR_HPP

#include <exception>
#include <string>
#include <utility>

namespace Spider
{
  class Error : public std::exception {
  public:
      explicit Error(std::string message) : _message(std::move(message)) {};

      ~Error() noexcept override = default;;

      const char *what() const noexcept override { return this->_message.c_str(); };

      // TODO :: WindowsErrorMessageRetrievalFunction

  protected:
    std::string _message;
  };
}
#endif //CPP_SPIDER_ERROR_HPP
