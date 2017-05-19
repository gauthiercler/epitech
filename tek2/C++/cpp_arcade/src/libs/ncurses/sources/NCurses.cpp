/*
** Ncurses.cpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/libs/Ncurses/sources/Ncurses.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar 18 19:08:21 2017 Anas Buyumad
** Last update Sat Mar 18 19:08:21 2017 Anas Buyumad
*/

#include <CursesPicture.hpp>
#include <CursesSprite.hpp>
#include "NCurses.hpp"

arcade::NCurses::NCurses() : terminal(NULL), eventHandler(NULL) {

}

arcade::NCurses::~NCurses() {
  if (this->terminal) {
    delete this->terminal;
    this->terminal = NULL;
  }
  if (this->eventHandler) {
    delete this->eventHandler;
    this->eventHandler = NULL;
  }
}

bool			arcade::NCurses::openWindow(const std::string &name,
						uint64_t width,
						uint64_t height) {
  if (this->terminal) {
    delete this->terminal;
    this->terminal = NULL;
  }
  if (this->eventHandler) {
    delete this->eventHandler;
    this->eventHandler = NULL;
  }
  this->terminal = new Curses::Terminal(name, width, height, 2);
  this->eventHandler = new Curses::EventHandler();
  return true;
}

void			arcade::NCurses::closeWindow() {
  if (this->terminal) {
    delete this->terminal;
    this->terminal = NULL;
  }
  if (this->eventHandler) {
    delete this->eventHandler;
    this->eventHandler = NULL;
  }
}

arcade::IFrame &	arcade::NCurses::addFrame(const arcade::pos &positions,
					  uint64_t width,
					  uint64_t height,
					  uint64_t depth) {
  if (!this->terminal) {
    throw arcade::Error("Tried opening a frame without instantiating a terminal.");
  }
  return this->terminal->addWindow(positions, width, height, depth);
}

arcade::IPicture *	arcade::NCurses::loadPicture(const std::string &path) const {
  arcade::IPicture	*picture = new Curses::Picture();

  static_cast<void>(path);
  return picture;
}

arcade::ISprite *	arcade::NCurses::loadSprite(const std::string &path) const {
  arcade::ISprite	*sprite = new Curses::CursesSprite();

  sprite->load(path);
  return sprite;
}

bool 			arcade::NCurses::display() {
  if (!this->terminal) {
    return false;
  }
  return this->terminal->refreshTerminal();
}

const arcade::IEvent &	arcade::NCurses::getEvent(bool blocking) {
  return this->eventHandler->getEvent(blocking);
}

void
arcade::NCurses::resetStackEvents() {

}

arcade::ISound *arcade::NCurses::loadSound(const std::string &path) const {
  static_cast<void>(path);
  return NULL;
}

void arcade::NCurses::deleteFrame(uint64_t id) {
  if (!this->terminal) {
    return ;
  }
  this->terminal->removeWindow(id);
}

extern "C" arcade::IGraphic *createGraphic() {
  return new arcade::NCurses();
}