/*
** Parser.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/parser/Parser.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:43:45 2017 Gauthier Cler
** Last update Sun Oct 08 19:43:47 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_PARSER_HPP
#define CPP_SPIDER_PARSER_HPP

#include <map>
#include <functional>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/regex.hpp>

namespace Spider {

  enum class EnumParser {
    PING,
    KEYBOARD,
    MOUSE,
    CLIENT,
    COMMAND_RESPONSE,
    ERROR,
    OTHER
  };

  class Parser {

    std::map<EnumParser, boost::property_tree::ptree> _templates;

  public:
    Parser();
    ~Parser() = default;

    EnumParser	run(const std::string &packet);
  private:
    bool	validation(boost::property_tree::ptree &validation, boost::property_tree::ptree &model);
  };
}

#endif //CPP_SPIDER_PARSER_HPP
