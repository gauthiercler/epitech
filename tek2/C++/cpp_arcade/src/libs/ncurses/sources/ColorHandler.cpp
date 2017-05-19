/*
** ColorHandler.cpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/src/libs/ncurses/sources/ColorHandler.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Mar 21 22:13:51 2017 Anas Buyumad
** Last update Tue Mar 21 22:13:51 2017 Anas Buyumad
*/

#include <Error.hpp>
#include "ColorHandler.hpp"

Curses::ColorHandler::ColorHandler() {

  if (!(this->handles_color = has_colors())) {
    throw arcade::Error("Terminal doesn't support colors.");
  }

  this->handles_color256 = can_change_color();
  start_color();
  use_default_colors();
  this->handles_color256 ? this->fillComplexPalette() : this->fillStandardPalette();
}

Curses::ColorHandler::~ColorHandler() {
}

bool Curses::ColorHandler::getColorHandle(void) const {
  return this->handles_color;
}

bool Curses::ColorHandler::getColor256Handle(void) const {
  return this->handles_color256;
}

void Curses::ColorHandler::fillStandardPalette(void) {
  arcade::rgb		colorRgb(0);
  short int		red, blue, green;

  for (short int i = 0 ; i <= 7 ; i++) {
    color_content(i, &red, &green, &blue);
    colorRgb.argb[0] = 255;
    colorRgb.argb[1] = red * 0.255;
    colorRgb.argb[2] = green * 0.255;
    colorRgb.argb[3] = blue * 0.255;
    this->color_palette.insert({i, colorRgb});

    init_pair(i, i, i);
    this->pair_palette.insert({i, colorRgb});

    if ((colorRgb.argb[1] + colorRgb.argb[2] + colorRgb.argb[3]) / 3 > 255 / 2) {
      init_pair(i + 8, COLOR_BLACK, i);
    }
    else {
      init_pair(i + 8, COLOR_WHITE, i);
    }
    this->text_palette.insert({i + 8, colorRgb});
  }
}

void Curses::ColorHandler::fillComplexPalette(void) {
  arcade::rgb		colorRgb(0);
  short int		red, blue, green;
  short int		index = 2;

  init_color(0, 0, 0, 0);
  init_color(1, 700, 700, 700);

  for (short int red_iterator = 0 ; red_iterator <= 255 ; red_iterator += 52) {
    for (short int green_iterator = 0 ; green_iterator <= 255 ; green_iterator += 52) {
      for (short int blue_iterator = 0 ; blue_iterator <= 255 ; blue_iterator += 52) {
	init_color(index, red_iterator / 0.255, green_iterator / 0.255, blue_iterator / 0.255);
	color_content(index, &red, &green, &blue);
	colorRgb.argb[0] = 255;
	colorRgb.argb[1] = red_iterator;
	colorRgb.argb[2] = green_iterator;
	colorRgb.argb[3] = blue_iterator;
	this->color_palette.insert({index, colorRgb});

	init_pair(index, index, index);
	this->pair_palette.insert({index, colorRgb});

	if ((colorRgb.argb[1] + colorRgb.argb[2] + colorRgb.argb[3]) / 3 > 255 / 2) {
	  init_pair(index + 125, 0, index);
	}
	else {
	  init_pair(index + 125, 1, index);
	}
	this->text_palette.insert({index + 125, colorRgb});

	index += 1;
      }
    }
  }
}

short int Curses::ColorHandler::getClosestShade(const arcade::rgb &color,
						const std::unordered_map<short int, arcade::rgb> &palette) const {
  int		delta = -1, currentDelta;
  short int	pair = -1;

  for (auto it : palette) {
    currentDelta = abs(it.second.argb[1] - color.argb[1]) + abs(it.second.argb[2] - color.argb[2]) + abs(it.second.argb[3] - color.argb[3]);
    if (currentDelta < delta || delta == -1) {
      delta = currentDelta;
      pair = it.first;
    }
  }
  return pair;
}
