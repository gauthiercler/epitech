/*
** Event.cpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/src/libs/ncurses/sources/Event.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Apr 03 16:55:29 2017 Anas Buyumad
** Last update Mon Apr 03 16:55:29 2017 Anas Buyumad
*/

#include		"Event.hpp"

Curses::Event::Event(arcade::eventType type, arcade::eventValue value) : type(type), value(value) {

}

Curses::Event::~Event() {

}

void Curses::Event::setType(arcade::eventType eventType) {
  this->type = eventType;
}

void Curses::Event::setValue(arcade::eventValue eventValue) {
  this->value = eventValue;
}

arcade::eventType Curses::Event::getType() const {
  return this->type;
}

arcade::eventValue Curses::Event::getValue() const {
  return this->value;
}

arcade::CommandType Curses::Event::get() const {
  return arcade::CommandType::SHOOT;
}
