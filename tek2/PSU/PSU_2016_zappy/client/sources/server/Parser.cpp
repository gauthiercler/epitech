/*
** Parser.cpp for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/client/sources/server/Parser.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 18:23:47 2017 Montagne Valentin
** Last update Thu Jun 22 18:23:47 2017 Montagne Valentin
*/

#include 			<sstream>
#include <utils/Utils.hpp>
#include			"server/Parser.hpp"

zappy::Parser::Parser() : _info(ParseType::UNKNOWN) {}

zappy::Parser::~Parser() {}

void zappy::Parser::parse(const std::string &line) {
  for (auto &d : _dico) {
    if (std::regex_match(line, d.second)) {
      this->_info = d.first;
      break;
    }
  }
  this->_list = Utils::explode(line, ' ');
}

void zappy::Parser::reset(void) {
  this->_info = ParseType::UNKNOWN;
  this->_list.clear();
}

const zappy::ParseType &zappy::Parser::getType(void) const {
  return this->_info;
}

const std::vector<std::string> &zappy::Parser::getArgs(void) const {
  return this->_list;
}

std::string &zappy::Parser::operator[](std::size_t idx) {
  return this->_list[idx];
}

const std::string &zappy::Parser::operator[](std::size_t idx) const {
  return this->_list[idx];
}

