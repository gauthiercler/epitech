/*
** AJsonParser.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/AJsonParser.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 16 07:09:47 2017 Anthony LECLERC
** Last update ven. juin 16 07:09:47 2017 Anthony LECLERC
*/

#include <rapidjson/istreamwrapper.h>
#include <fstream>
#include "maps/AJsonParser.hpp"

void indie::AJsonParser::open(std::string const &file) {
  std::ifstream ifs(file);
  if (!ifs)
    throw ParserExcept("Cannot open file '" + file + "'");
  rapidjson::IStreamWrapper stream(ifs);
  clear();

  if (_doc.ParseStream(stream).HasParseError())
    throw ParserExcept(file + ": JSon parser error");

  ifs.close();
}

void indie::AJsonParser::parseMember(char const *s) const {
  if (!_doc.HasMember(s))
    throw ParserMissingMember(std::string("Missing member attribute: ") + s);
}

void indie::AJsonParser::parse() const {
  parseMember("name");
  parseMember("spawn");
  parseMember("height");
  parseMember("playersMax");
  parseMember("wall");
}
