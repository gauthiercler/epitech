/*
** ConfigMapLoader.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/ConfigMapLoader.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 16 07:04:13 2017 Anthony LECLERC
** Last update ven. juin 16 07:04:13 2017 Anthony LECLERC
*/

#include <iostream>
#include                "maps/ConfigMapLoader.hpp"

void indie::ConfigMapLoader::clear() {
  _filesPath.clear();
  _folder = irr::io::path();
}

void indie::ConfigMapLoader::load(std::string const &string) {
  this->open(string);

  _folder = getMember(_doc, "folder", Parser::IsJsonString).GetString();
  auto files = getMember(_doc, "maps", Parser::IsJsonArray).GetArray();
  for (auto&& file : files)
  {
    _filesPath.emplace_back(getMember(file, Parser::IsJsonString).GetString());
  }
}

void indie::ConfigMapLoader::save(std::string const &) {

}

indie::ConfigMapLoader::ConfigMapLoader() {

}

indie::ConfigMapLoader::~ConfigMapLoader() {

}

std::vector<irr::io::path> const &indie::ConfigMapLoader::getMapFiles() const {
  return _filesPath;
}

irr::io::path const &indie::ConfigMapLoader::getMapsDirectory() const {
  return _folder;
}


