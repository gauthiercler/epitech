/*
** Window.cpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/libs/Ncurses/sources/Window.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar 18 19:26:16 2017 Anas Buyumad
** Last update Sat Mar 18 19:26:16 2017 Anas Buyumad
*/

#include <iostream>
#include <unistd.h>
#include <Error.hpp>
#include	"Terminal.hpp"

Curses::Terminal::Window::Window(Terminal *terminal, const arcade::pos &positions, uint64_t width,
		       uint64_t height, uint64_t ratio, uint64_t depth, uint64_t id) : terminal(terminal), width(width), height(height), ratio(ratio), depth(depth), id(id) {
  this->positions.x = positions.x;
  this->positions.y = positions.y;
  if ((this->frame = newwin(height, width, positions.y, positions.x)) == NULL) {
    throw arcade::Error("Failed to create newwin.");
  }
}

Curses::Terminal::Window::~Window() {
    delwin(this->frame);
}

WINDOW *Curses::Terminal::Window::getFrame() const {
  return this->frame;
}

arcade::pos Curses::Terminal::Window::getPos() const {
  return this->positions;
}

uint64_t Curses::Terminal::Window::getWidth() const {
  return this->width;
}

uint64_t Curses::Terminal::Window::getHeight() const {
  return this->height;
}

uint64_t Curses::Terminal::Window::getRatio() const {
  return this->ratio;
}

uint64_t Curses::Terminal::Window::getDepth() const {
  return this->depth;
}

bool Curses::Terminal::Window::refresh() {
  return wrefresh(this->frame) != ERR;
}

uint64_t Curses::Terminal::Window::getBaseX(uint64_t posx) const {
  return posx * this->getRatio();
}

uint64_t Curses::Terminal::Window::getBaseY(uint64_t posy) const {
  return (this->getRatio() == 0 ? posy : posy * (this->getRatio() / 2));
}

void Curses::Terminal::Window::rotatePos(arcade::pos &pos,
					 const arcade::pos &orig,
					 float rotation_angle) const {
  uint64_t 	deltaX;
  uint64_t 	deltaY;

  for (float x = rotation_angle ; x > 0 ; x -= 90) {
    deltaX = pos.x - orig.x;
    deltaY = pos.y - orig.y;
    pos.x = deltaY;
    pos.y = deltaX * -1;
    pos.x = orig.x + pos.x;
    pos.y = orig.y + pos.y;
  }
}

bool
Curses::Terminal::Window::drawCell(const arcade::pos &pos, const arcade::rgb &color) {
  wattron(this->frame, COLOR_PAIR(this->terminal->getColorPair(color)));
  mvwaddch(this->frame, pos.y, this->getBaseX(pos.x), ' ');
  mvwaddch(this->frame, pos.y, this->getBaseX(pos.x) + 1, ' ');
  wattroff(this->frame, COLOR_PAIR(this->terminal->getColorPair(color)));
  return true;
}

bool
Curses::Terminal::Window::draw(const arcade::pos &pos, const arcade::IPicture &picture) {
  return this->draw(pos, arcade::rectangle(arcade::pos(picture.getSize().x, picture.getSize().y), picture.getColor(), picture.getRotate(), true, 1));
}

bool Curses::Terminal::Window::draw(const arcade::pos &pos,
			  const arcade::rectangle &rectangle) {

  arcade::pos		cell;
  arcade::pos		r_cell;
  arcade::pos		cursesPos;
  arcade::pos		cursesSize;

  this->terminal->convertPos(pos, cursesPos);
  this->terminal->convertPos(rectangle.size, cursesSize);
  for (cell.x = cursesPos.x ; cell.x < cursesPos.x + cursesSize.x ; cell.x++) {
    for (cell.y = cursesPos.y ; cell.y < cursesPos.y + cursesSize.y ; cell.y++) {
      r_cell.x = cell.x;
      r_cell.y = cell.y;
      if (rectangle.rotate) {
	this->rotatePos(r_cell, cursesPos, rectangle.rotate);
      }
      if (!rectangle.full) {
	if (cell.x == cursesPos.x || cell.y == cursesPos.y || cell.x == (cursesPos.x + cursesSize.x - 1) || cell.y == (cursesPos.y + cursesSize.y - 1)) {
	  this->drawCell(r_cell, rectangle.color);
	}
      }
      else
	this->drawCell(r_cell, rectangle.color);
    }
  }
  return false;
}

bool
Curses::Terminal::Window::draw(const arcade::pos &pos, const std::string &str,
			       const arcade::text &text) {
  arcade::pos		cursesPos;
  chtype		ch;
  int			pair;
  short int		foreground, background, red, green, blue, attrP;

  static_cast<void>(text);
  ch = getbkgd(this->frame);
  pair = (ch & A_COLOR) >> 8;
  pair_content(pair, &foreground, &background);
  color_content(background, &red, &green, &blue);
  cursesPos.x = pos.x / 10;
  cursesPos.y = pos.y / 20;
  attrP = this->terminal->getTextPair(arcade::rgb(255, red * 0.255, green * 0.255, blue * 0.255));
  wattron(this->frame, COLOR_PAIR(attrP));
  mvwaddstr(this->frame, cursesPos.y, cursesPos.x, str.c_str());
  wattroff(this->frame, COLOR_PAIR(attrP));
  return (true);
}

bool Curses::Terminal::Window::draw(const arcade::pos &pos,
				    const arcade::circle &circle) {
  arcade::pos		origin(pos.x - circle.radius, pos.y - circle.radius);
  arcade::pos		size;

  if (circle.radius * 2 <= 20) {
    size.x = 20;
    size.y = 20;
    origin.x += circle.radius;
    origin.y += circle.radius;
  }
  else {
    size.x = 40;
    size.y = 40;
  }

  return this->draw(origin, arcade::s_rectangle(arcade::s_rectangle(size, circle.color, 0, true, 1)));
}

bool
Curses::Terminal::Window::draw(const arcade::pos &start, const arcade::pos &end,
			       const arcade::rgb &color, uint64_t thickness) {
  arcade::pos		cursesStart;
  arcade::pos		cursesEnd;
  arcade::pos		cell;

  static_cast<void>(thickness);
  this->terminal->convertPos(start, cursesStart);
  this->terminal->convertPos(end, cursesEnd);
  for (cell.x = start.x ; cell.x < end.x ; cell.x++) {
    for (cell.y = start.y ; cell.y < end.y ; cell.y++) {
      this->drawCell(cell, color);
    }
  }
  return false;
}

bool Curses::Terminal::Window::draw(const arcade::rgb &color) {
  wbkgd(this->frame, COLOR_PAIR(this->terminal->getColorPair(color)));
  return true;
}

uint64_t Curses::Terminal::Window::getId() const {
  return this->id;
}
