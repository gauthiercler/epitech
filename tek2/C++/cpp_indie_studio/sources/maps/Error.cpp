/*
** Error.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/Error.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 16 02:05:54 2017 Anthony LECLERC
** Last update ven. juin 16 02:05:54 2017 Anthony LECLERC
*/

#include "maps/Errors.hpp"

indie::ParserExcept::~ParserExcept() noexcept {}

indie::ParserExcept::ParserExcept(std::string const &str) :
    Error(str) {}

indie::ParserMissingMember::ParserMissingMember(std::string const &str) :
    ParserExcept(str) {}

indie::ParserInvalidMember::ParserInvalidMember(std::string const &str) :
    ParserExcept(str) {}

indie::ParserInvalidValue::ParserInvalidValue(std::string const &str) :
    ParserExcept(str) {}
