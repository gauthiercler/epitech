/*
** CursesSprite.cpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/src/libs/ncurses/sources/CursesSprite.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Apr 09 02:16:45 2017 Anas Buyumad
** Last update Sun Apr 09 02:16:45 2017 Anas Buyumad
*/

#include <fstream>
#include <iostream>
#include	"CursesSprite.hpp"
#include "../../common/Utils.hpp"

Curses::CursesSprite::CursesSprite() : _loaded(false), _size(0, 0) {
  this->_regexes[0] = std::regex("^[\\t *]*\\/?(?:.*\\/*+)?.+\\..+[\\t *]*$");
  this->_regexes[1] = std::regex("^[\\t ]*[0-9]+[\\t ]*=(?:[\\t ]*[0-9]+[\\t ]*:){6}[\\t ]*[0-9]+[\\t ]*$");
}

Curses::CursesSprite::~CursesSprite() {

}

bool Curses::CursesSprite::load(const std::string &name) {
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

const arcade::pos &Curses::CursesSprite::getSize(uint64_t id) const {
  auto spriteInfo = this->_sprites.find(id);

  if (spriteInfo != this->_sprites.end())
    return spriteInfo->second.position;
  return this->_size;
}

const arcade::IPicture &Curses::CursesSprite::getPicture(uint64_t id) {
  auto spriteInfo = this->_sprites.find(id);

  if (spriteInfo != this->_sprites.end())
  {
    this->_picture.setInnerPos(spriteInfo->second.position,
			       spriteInfo->second.size.x,
			       spriteInfo->second.size.y);
    if (spriteInfo->second.size.x == 32 && spriteInfo->second.size.y == 32) {
      this->_picture.setInnerPos(spriteInfo->second.position,
				 40,
				 40);
    }
    this->_picture.setColor(spriteInfo->second.color);
  }
  return this->_picture;
}

void Curses::CursesSprite::setImage(const std::string &path) {
  std::string epur_path;

  epur_path = arcade::Utils::trim(path);
  this->_loaded = this->_picture.load(epur_path);
}

void Curses::CursesSprite::addSprite(std::string &line) {
  std::string noSpaceLine = arcade::Utils::removeSpaces(line);
  std::vector<std::string> first = arcade::Utils::explode(noSpaceLine, '=');
  std::vector<std::string> second = arcade::Utils::explode(first[1], ':');

  this->_sprites.insert({std::stoi(first[0]),
			 sprite(arcade::pos(std::stoi(second[0]), std::stoi(second[1])),
				arcade::pos(std::stoi(second[2]), std::stoi(second[3])),
				arcade::rgb(255, std::stoi(second[4]), std::stoi(second[5]), std::stoi(second[6])))
			});
}
