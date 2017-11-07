/*
** Error.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/parser/Error.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:43:19 2017 Gauthier Cler
** Last update Sun Oct 08 19:43:21 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_ERROR_HPP
#define CPP_SPIDER_ERROR_HPP

#include <stdexcept>

namespace Spider {

  class Error : public std::runtime_error {
  public:
    explicit Error(const char *message) : std::runtime_error(message) {};
    ~Error() noexcept override = default;
  };

  class ParserError : public Error {
  public:
    explicit ParserError(std::string const &message) : Error(std::string("Spider Parser : " + message).c_str()) {};
    ~ParserError() noexcept override = default;
  };

}

#endif //CPP_SPIDER_ERROR_HPP
