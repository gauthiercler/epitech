/*
** CursesPicture.cpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/src/libs/ncurses/sources/CursesPicture.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Apr 08 23:21:09 2017 Anas Buyumad
** Last update Sat Apr 08 23:21:09 2017 Anas Buyumad
*/

#include	"CursesPicture.hpp"

Curses::Picture::Picture() : rotation(0), scale_x(1), scale_y(1), size(arcade::pos(0, 0)), color(arcade::rgb(255, 0, 0, 0)) {

}

Curses::Picture::~Picture() {

}

bool Curses::Picture::load(const std::string &path) {
  static_cast<void>(path);
  return true;
}

bool Curses::Picture::rotate(float angle) {
  static_cast<void>(angle);
  return true;
}

bool Curses::Picture::setScale(float scale_x, float scale_y) {
  this->scale_x = scale_x;
  this->scale_y = scale_y;
  return true;
}

bool Curses::Picture::isLoaded() const {
  return true;
}

float Curses::Picture::getRotate() const {
  return 0;
}

float Curses::Picture::getXScale() const {
  return this->scale_x;
}

float Curses::Picture::getYScale() const {
  return this->scale_y;
}

bool Curses::Picture::setInnerPos(const arcade::pos &positions, uint64_t width,
				  uint64_t height) {
  static_cast<void>(positions);
  this->size.x = width;
  this->size.y = height;
  return true;
}

void Curses::Picture::setColor(const arcade::rgb &color) {
  this->color.argb[0] = color.argb[0];
  this->color.argb[1] = color.argb[1];
  this->color.argb[2] = color.argb[2];
  this->color.argb[3] = color.argb[3];
}

const arcade::rgb &Curses::Picture::getColor() const {
  return this->color;
}

const arcade::pos &Curses::Picture::getSize() const {
  return this->size;
}
