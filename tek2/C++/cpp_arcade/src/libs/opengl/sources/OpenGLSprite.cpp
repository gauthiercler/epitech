/*
** OpenGLSprite.cpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/libs/opengl/sources/OpenGLSprite.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Apr 03 23:16:42 2017 Gauthier Cler
** Last update Mon Apr 03 23:16:42 2017 Gauthier Cler
*/

#include <fstream>
#include <iostream>
#include "Utils.hpp"
#include "OpenGLSprite.hpp"

arcade::OpenGLSprite::OpenGLSprite() : _loaded(false), _size(0, 0) {
  this->_regexes[0] = std::regex("^[\\t *]*\\/?(?:.*\\/*+)?.+\\..+[\\t *]*$");
  this->_regexes[1] = std::regex("^[\\t ]*[0-9]+[\\t ]*=(?:[\\t ]*[0-9]+[\\t ]*:){6}[\\t ]*[0-9]+[\\t ]*$");
}

arcade::OpenGLSprite::~OpenGLSprite() {

}

bool arcade::OpenGLSprite::load(const std::string &name) {
  std::ifstream		file(name);
  std::string		line;

  if (!file.is_open())
    return false;
  while (std::getline(file, line))
  {
    if (std::regex_match(line, this->_regexes[0]))
      this->setImage(line);
    else if (std::regex_match(line, this->_regexes[1]))
      this->addSprite(line);
  }
  return this->_loaded;
}

const arcade::IPicture &arcade::OpenGLSprite::getPicture(uint64_t id) {
  auto spriteInfo = this->_sprites.find(id);

  if (spriteInfo != this->_sprites.end())
  {
    this->_picture.setInnerPos(spriteInfo->second.position,
			       spriteInfo->second.size.x,
			       spriteInfo->second.size.y);
    this->_picture.setColor(spriteInfo->second.color);
  }
  return this->_picture;
}

void arcade::OpenGLSprite::setImage(const std::string &path) {
  std::string epur_path;

  epur_path = Utils::trim(path);
  this->_loaded = this->_picture.load(epur_path);
}

void arcade::OpenGLSprite::addSprite(std::string &line) {
  std::string noSpaceLine = Utils::removeSpaces(line);
  std::vector<std::string> first = Utils::explode(noSpaceLine, '=');
  std::vector<std::string> second = Utils::explode(first[1], ':');

  this->_sprites.insert({std::stoi(first[0]),
			 sprite(pos(std::stoi(second[0]), std::stoi(second[1])),
				pos(std::stoi(second[2]), std::stoi(second[3])),
				rgb(255, std::stoi(second[4]), std::stoi(second[5]), std::stoi(second[6])))
			});
}

const arcade::pos &arcade::OpenGLSprite::getSize(uint64_t id) const {
  auto spriteInfo = this->_sprites.find(id);

  if (spriteInfo != this->_sprites.end())
    return spriteInfo->second.position;
  return this->_size;
}
