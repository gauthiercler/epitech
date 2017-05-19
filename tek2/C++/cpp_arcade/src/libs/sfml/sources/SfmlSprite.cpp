/*
** SfmlSprite.cpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/sfml/sources/SfmlSprite.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Mar 20 09:16:38 2017 Vincent DUSAUTOIR
** Last update Mon Mar 20 09:16:38 2017 Vincent DUSAUTOIR
*/

#include <fstream>
#include <iostream>
#include "Utils.hpp"
#include "SfmlSprite.hpp"

arcade::SfmlSprite::SfmlSprite() : _loaded(false), _size(0, 0) {
  this->_regexes[0] = std::regex("^[\\t *]*\\/?(?:.*\\/*+)?.+\\..+[\\t *]*$");
  this->_regexes[1] = std::regex("^[\\t ]*[0-9]+[\\t ]*=(?:[\\t ]*[0-9]+[\\t ]*:){6}[\\t ]*[0-9]+[\\t ]*$");
}

arcade::SfmlSprite::~SfmlSprite() {

}

bool arcade::SfmlSprite::load(const std::string &name) {
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

const arcade::IPicture &arcade::SfmlSprite::getPicture(uint64_t id) {
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

void arcade::SfmlSprite::setImage(const std::string &path) {
  std::string epur_path;

  epur_path = Utils::trim(path);
  this->_loaded = this->_picture.load(epur_path);
}

void arcade::SfmlSprite::addSprite(std::string &line) {
  std::string noSpaceLine = Utils::removeSpaces(line);
  std::vector<std::string> first = Utils::explode(noSpaceLine, '=');
  std::vector<std::string> second = Utils::explode(first[1], ':');

  this->_sprites.insert({std::stoi(first[0]),
			 sprite(pos(std::stoi(second[0]), std::stoi(second[1])),
				pos(std::stoi(second[2]), std::stoi(second[3])),
				rgb(255, std::stoi(second[4]), std::stoi(second[5]), std::stoi(second[6])))
			});
}

const arcade::pos &arcade::SfmlSprite::getSize(uint64_t id) const {
  auto spriteInfo = this->_sprites.find(id);

  if (spriteInfo != this->_sprites.end())
    return spriteInfo->second.position;
  return this->_size;
}
