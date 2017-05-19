#include <iostream>
#include <unistd.h>
#include <vector>
#include "Screen.hpp"

Screen::Screen(const std::vector<IMonitorModule *> &modules) : ModuleIndex(0), HModuleIndex(0) {
  this->CurrentModule = NULL;
  if (!this->setupTerminal()) {
    std::clog << "[Error] Couldn't set-up terminal" << std::endl;
  }

  if (!this->buildSequences()) {
    std::clog << "[Error] Couldn't build key sequences" << std::endl;
  }
  if (!this->buildWindows()) {
    std::clog << "[Error] Couldn't build windows" << std::endl;
  }
  this->setupNonBlockingIO();
  if (!this->drawModuleBar(modules)) {
    std::clog << "[Error] Couldn't build module bar" << std::endl;
  }
}

Screen::~Screen() {
  this->resetTerminal();
  std::clog << "[Info] Screen Destroyed" << std::endl;
}

bool Screen::setupTerminal() {
  if (ioctl(0, TCGETS, &this->BackupTerm) == -1) {
    std::clog << std::strerror(errno) << std::endl;
    return false;
  }

  this->EngineTerm = this->BackupTerm;
  this->EngineTerm.c_lflag &= ~(ICANON | ECHO);
//  curs_set(0);

  if (ioctl(0, TCSETS, &this->EngineTerm) == -1) {
    std::clog << std::strerror(errno) << std::endl;
    return false;
  }
  std::clog << "[Info] Terminal setup"  << std::endl;
  return true;
}


bool Screen::setupNonBlockingIO() {
  if (ioctl(0, TCGETS, &this->EngineTerm) == -1) {
    std::clog << std::strerror(errno) << std::endl;
    return false;
  }

  this->EngineTerm.c_cc[VTIME] = 1;
  this->EngineTerm.c_cc[VMIN] = 0;

  if (ioctl(0, TCSETS, &this->EngineTerm) == -1) {
    std::clog << std::strerror(errno) << std::endl;
    return false;
  }
  return true;
}


bool Screen::resetTerminal() {
  if (ioctl(0, TCSETS, &this->BackupTerm) == - 1) {
    std::clog << std::strerror(errno) << std::endl;
    return false;
  }
  std::clog << "[Info] Terminal reset" << std::endl;
  return true;
}


bool Screen::buildSequences() {
  int		termReturn;
  char		*keypad;

  setupterm(getenv("TERM"), 1, &termReturn);
  if (termReturn <= 0) {
    std::clog << "[Error] TERM env variable could not be found" << std::endl;
    return false;
  }
  if ((keypad = tigetstr("smkx")) == NULL) {
    std::clog << "[Error] smkx keymap could not be found" << std::endl;
    return false;
  }
  putp(keypad);
  if (!tigetstr("kcub1") || !tigetstr("kcuf1")) {
    std::clog << "[Error] Couldn't load key sequences" << std::endl;
    return false;
  }
  this->tmpleft = tigetstr("kcub1");
  this->keyMapString[0] = tigetstr("kcub1");
  this->keyMapString[1] = tigetstr("kcuf1");
//  this->keyMap.insert( {tigetstr("kcub1"), &Screen::handleLeft });
  return true;
}


bool Screen::buildWindows() {
  int		terminalSize[2];
  int		moduleBarHeight;
  int		moduleBarPadding;

  initscr();
  curs_set(0);
  start_color();

  getmaxyx(stdscr, terminalSize[1], terminalSize[0]);
  moduleBarHeight = terminalSize[1] / 6;
  moduleBarPadding = terminalSize[0] / 8;

  if (!(this->MainScreen = newwin(terminalSize[1], terminalSize[0], 0, 0))) {
    std::clog << "[Error] Couldn't build main screen" << std::endl;
    return false;
  }
  if (!(this->ModuleBar = subwin(this->MainScreen, moduleBarHeight, terminalSize[0] - (moduleBarPadding * 2), 0, moduleBarPadding))) {
    std::clog << "[Error] Couldn't build module bar" << std::endl;
    return false;
  }

  if (!(this->ModuleData = subwin(this->MainScreen, terminalSize[1] - moduleBarHeight, terminalSize[0], moduleBarHeight, 0))) {
    std::clog << "[Error] Couldn't module data" << std::endl;
    return false;
  }
  std::clog << "Term size : " << terminalSize[1] << "x " << terminalSize[0] << "Mod bar height : " << moduleBarHeight << std::endl;
  this->buildOutline(this->ModuleBar);
  this->buildOutline(this->ModuleData);
//  this->buildOutline(this->ModuleData);
  init_pair(BG_COLOR, COLOR_BLACK, COLOR_BLACK);
  init_pair(MODULE_COLOR, COLOR_BLUE, COLOR_BLACK);
  init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
  init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
  init_pair(COLOR_GREEN_BG, COLOR_GREEN, COLOR_GREEN);
  init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
  return true;
}

bool Screen::drawModuleBar(const std::vector<IMonitorModule *> &modules) {
//  std::vector<std::string>	Mlist;

  size_t			index = 0;
//  int				paddingX = getmaxx(this->ModuleBar) / 10;
  int				currentOffset = 0;
  int				nbMaxModules = 3;
  int				IdentifierSize = 0;

  std::vector<IMonitorModule *>::const_iterator	it = modules.begin();
  wattron(this->ModuleBar, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(this->ModuleBar, 2, 2 + currentOffset, "Modules  ");
  wattroff(this->ModuleBar, COLOR_PAIR(MODULE_COLOR));
  currentOffset += 9;
  while (it != modules.end()) {
    if (index >= this->ModuleIndex && index < this->ModuleIndex + nbMaxModules) {
      IdentifierSize = static_cast<int>((*it)->getIdentifier().size());
      for (int i = 0; i < (25 - IdentifierSize) / 2; i++) {
	mvwprintw(this->ModuleBar, 2, 2 + currentOffset, " ");
	currentOffset += 1;
      }
      if (index == this->HModuleIndex) {
	wattron(this->ModuleBar, COLOR_PAIR(MODULE_COLOR) | A_UNDERLINE);
      }
      mvwprintw(this->ModuleBar, 2, 2 + currentOffset, (*it)->getIdentifier().c_str());
      if (index == this->HModuleIndex) {
	wattroff(this->ModuleBar, COLOR_PAIR(MODULE_COLOR) | A_UNDERLINE);
      }
      currentOffset += IdentifierSize;
      for (int i = 0; i < (25 - IdentifierSize) / 2; i++) {
	mvwprintw(this->ModuleBar, 2, 2 + currentOffset, " ");
	currentOffset += 1;
      }
    }
    index += 1;
    ++it;
  }

  wrefresh(this->ModuleBar);

  return true;
}


void Screen::handleSequence(std::string sequence, const std::vector<IMonitorModule *> &registeredModules) {
  if (sequence == this->keyMapString[0]) {
    this->handleLeft(registeredModules);
  }
  else if (sequence == this->keyMapString[1]) {
    this->handleRight(registeredModules);
  }
}

void Screen::handleLeft(const std::vector<IMonitorModule *> &registeredModules) {
  if (this->ModuleIndex > 0) {
    this->ModuleIndex -= 1;
    std::clog << "Module index : " << this->ModuleIndex << std::endl;
  }
  if (this->HModuleIndex > 0) {
    this->HModuleIndex -= 1;
  }
  wclear(this->ModuleBar);
  wclear(this->ModuleData);
  wrefresh(this->ModuleData);
  this->buildOutline(this->ModuleBar);
  this->buildOutline(this->ModuleData);
  this->drawModuleBar(registeredModules);
}


void Screen::handleRight(const std::vector<IMonitorModule *> &registeredModules) {
  if (this->ModuleIndex + 3 < registeredModules.size()) {
    this->ModuleIndex += 1;
  }
  if (this->HModuleIndex < registeredModules.size() - 1) {
    this->HModuleIndex += 1;
  }
  wclear(this->ModuleBar);
  wclear(this->ModuleData);
  wrefresh(this->ModuleData);
  this->buildOutline(this->ModuleBar);
  this->buildOutline(this->ModuleData);
  this->drawModuleBar(registeredModules);
}

size_t Screen::getHModuleIndex() const {
  return this->HModuleIndex;
}

WINDOW *Screen::getModuleDataScreen() const {
  return this->ModuleData;
}

bool Screen::buildOutline(WINDOW *window) {
  int	window_size[2];
  int	x = 0;
  int	y = 0;

  getmaxyx(window, window_size[1], window_size[0]);
  window_size[0] -= 1;
  window_size[1] -= 1;
  while (x <= window_size[0]) {
    y = 0;
    while (y <= window_size[1]) {
      if (x == 0) {
	y == 0 ? mvwaddch(window, y, x, ACS_ULCORNER) : 0;
	y == window_size[1] ? mvwaddch(window, y, x, ACS_LLCORNER) : 0;
	(y > 0 && y < window_size[1]) ? mvwaddch(window, y, x, ACS_VLINE) : 0;
      }
      else if (y == 0) {
	(x > 0 && x < window_size[0]) ? mvwaddch(window, y, x, ACS_HLINE) : 0;
	x == window_size[0] ? mvwaddch(window, y, x, ACS_URCORNER) : 0;
      }
      else if (x == window_size[0]) {
	(y > 0 && y < window_size[1]) ? mvwaddch(window, y, x , ACS_VLINE) : 0;
	y == window_size[1] ? mvwaddch(window, y, x, ACS_LRCORNER) : 0;
      }
      else if (y == window_size[1] && (x > 0 && x < window_size[0])) {
	mvwaddch(window, y, x, ACS_HLINE);
      }
      y += 1;
    }
    x += 1;
  }
  return true;
}
