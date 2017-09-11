/*
** Errors.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/Errors.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 16 02:05:04 2017 Anthony LECLERC
** Last update ven. juin 16 02:05:04 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_ERRORS_HPP
#define CPP_INDIE_STUDIO_ERRORS_HPP

#include <Error.hpp>

namespace indie {
  class ParserExcept : public Error {
  public:
    ParserExcept(std::string const& str);
    virtual ~ParserExcept() noexcept;
  };

  class ParserMissingMember : public ParserExcept {
  public:
    ParserMissingMember(std::string const& str);
    virtual ~ParserMissingMember() noexcept {}
  };

  class ParserInvalidMember : public ParserExcept {
  public:
    ParserInvalidMember(std::string const& str);
    virtual ~ParserInvalidMember() noexcept {}
  };

  class ParserInvalidValue : public ParserExcept {
  public:
    ParserInvalidValue(std::string const& str);
    virtual ~ParserInvalidValue() noexcept {}
  };


}

#endif //CPP_INDIE_STUDIO_ERRORS_HPP
