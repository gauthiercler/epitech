/*
** Terminal.cpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/libs/Ncurses/sources/Terminal.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar 18 19:05:13 2017 Anas Buyumad
** Last update Sat Mar 18 19:05:13 2017 Anas Buyumad
*/

#include	<sys/ioctl.h>
#include	<iostream>
#include	<unistd.h>
#include <Error.hpp>
#include <algorithm>
#include	"Terminal.hpp"

Curses::Terminal::Terminal(const std::string &name,
			   uint64_t width,
			   uint64_t height,
			   uint64_t ratio) : name(name), width(width), height(height), ratio(ratio){
  system("reset");
  if (!this->checkTerminalSize()) {
    throw arcade::Error("Terminal isn't big enough.");
  }
  if (!this->setupTerminal()) {
    throw arcade::Error("Couldn't setup Terminal.");
  }
  initscr();
  curs_set(0);
  this->colorHandler = new ColorHandler();
  if (!this->setNonBlockingIO()) {
    throw arcade::Error("Couldn't setup non-blocking read.");
  }
  refresh();
}

Curses::Terminal::~Terminal() {

  if (this->colorHandler) {
    delete this->colorHandler;
    this->colorHandler = NULL;
  }
  for (auto it : this->windows) {
    if (it.second)
      delete it.second;
  }
  endwin();
  if (!this->backupTerminal()) {
    throw arcade::Error("Couldn't restore terminal.");
  }
}

uint64_t Curses::Terminal::getWidth(void) const {
  return this->width;
}

uint64_t Curses::Terminal::getHeight(void) const {
  return this->height;
}

uint64_t Curses::Terminal::getRatio(void) const {
  return this->ratio;
}

void Curses::Terminal::setWidth(uint64_t width) {
  this->width = width;
}

void Curses::Terminal::setHeght(uint64_t height) {
  this->height = height;
}

bool Curses::Terminal::handlesColor(void) const {
  return this->colorHandler->getColorHandle();
}

bool Curses::Terminal::handlesColor256(void) const {
  return this->colorHandler->getColor256Handle();
}

bool Curses::Terminal::checkTerminalSize() {
  struct winsize	terminal_size;

  this->convertPixels(this->width, this->height);
  if (ioctl(0, TIOCGWINSZ, &terminal_size) == -1) {
    throw arcade::Error("Failed getting terminal size with ioctl.");
    return false;
  }
  if (terminal_size.ws_col < this->width * this->getRatio() || terminal_size.ws_row < this->height) {
    throw arcade::Error("Terminal isn't big enough.");
    return false;
  }
  return true;
}

bool Curses::Terminal::setupTerminal() {
  if (ioctl(0, TCGETS, &this->backupConfig) == 1) {
    throw arcade::Error("Couldn't get terminal config ioctl.");
    return false;
  }
  this->config = this->backupConfig;
  this->config.c_lflag &= ~(ICANON | ECHO);
  if (ioctl(0, TCSETS, &this->config) == -1) {
    throw arcade::Error("Couldn't set terminal config ioctl.");
    return false;
  }
  return true;
}

bool Curses::Terminal::setNonBlockingIO() {
  if (ioctl(0, TCGETS, &this->config) == -1) {
    throw arcade::Error("Couldn't get terminal config non blocking IO.");
    return false;
  }
  this->config.c_cc[VTIME] = 1;
  this->config.c_cc[VMIN] = 0;
  if (ioctl(0, TCSETS, &this->config) == -1) {
    throw arcade::Error("Couldn't set terminal config non blocking IO.");
    return false;
  }
  return true;
}

bool Curses::Terminal::backupTerminal() const {
  if (ioctl(0, TCSETS, &this->backupConfig) == -1) {
    throw arcade::Error("Couldn't backup terminal ioctl.");
    return false;
  }
  return true;
}

void
Curses::Terminal::convertPos(const arcade::pos &pixelPos, arcade::pos &cursesPos) const {
  cursesPos.x = pixelPos.x / (10 * this->ratio);
  cursesPos.y = pixelPos.y / (20 * (this->ratio / 2));
}

void Curses::Terminal::convertPixels(uint64_t &width, uint64_t &height) const {
  width /= (10 * this->ratio);
  height /= (20 * (this->ratio / 2));
}

arcade::IFrame &
Curses::Terminal::addWindow(const arcade::pos &positions, uint64_t width,
			    uint64_t height, uint64_t depth) {
  arcade::pos		cursesPositions;
  Curses::Terminal::Window	*window;

  cursesPositions.x = positions.x / 10;
  cursesPositions.y = positions.y / 20;
  width /= 10;
  height /= 20;
  window = new Curses::Terminal::Window(this, cursesPositions, width, height, this->getRatio(), depth, this->windows.size());
  this->windows.push_back({depth, window});
  std::sort(this->windows.begin(), this->windows.end(),
	    [](std::pair<uint64_t, Curses::Terminal::Window *> first, std::pair<uint64_t, Curses::Terminal::Window *> second){ return second.first < first.first; });
  return *window;
}

bool Curses::Terminal::refreshTerminal() const {
  if (refresh() == ERR) {
    return false;
  }
  for (auto it : this->windows) {
    if (wrefresh(it.second->getFrame()) == ERR) {
      return false;
    }
  }
  return true;
}

short int Curses::Terminal::getColorPair(const arcade::rgb &color) const {
  return this->colorHandler->getClosestShade(color, this->colorHandler->pair_palette);
}

short int Curses::Terminal::getTextPair(const arcade::rgb &color) const {
  return this->colorHandler->getClosestShade(color, this->colorHandler->text_palette);
}

void Curses::Terminal::removeWindow(uint64_t id) {
  std::vector<std::pair<uint64_t , Curses::Terminal::Window *>>::iterator it;

  it = this->windows.begin();
  while (it != this->windows.end()) {
    if (it->second->getId() == id) {
      delete it->second;
      it = this->windows.erase(it);
    }
    else
      ++it;
  }
}
