/*
** MemoryModule.cpp for cpp_gkrellm in /home/gogo/rendu/tek2/cpp_gkrellm/Modules/MemoryModule.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Jan 21 12:01:22 2017 Gauthier CLER
** Last update Sat Jan 21 12:01:24 2017 Gauthier CLER
*/

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Charts/Chart.hpp"
#include "MemoryModule.hpp"

bool MemoryModule::isEnabled() const {
  return this->_enabled;
}

MemoryModule::MemoryModule() : _id("Memory Usage"), _enabled(true), _graphicMode(Config::GRAPHICS) {
  std::clog << "[Info] Construction of " << this->getIdentifier() << std::endl;
}

MemoryModule::~MemoryModule() {
  std::clog << "[Info] Destruction of " << this->getIdentifier() << std::endl;
}

MemoryModule::MemoryModule(const MemoryModule &other) : _id(other.getIdentifier()), _enabled(other.isEnabled()), _graphicMode(other._graphicMode) {
  this->_content = std::map<std::string, int>(other._content);
}

void MemoryModule::enable() {
  this->_enabled = true;
}

void MemoryModule::disable() {
  this->_enabled = false;
}

void MemoryModule::setGraphics(Config::GraphicMode graphics) {
  this->_graphicMode = graphics;
}

IMonitorModule *MemoryModule::clone() const {
  return new MemoryModule(*this);
}

MemoryModule &MemoryModule::operator=(const MemoryModule &other) {
  this->_id = other.getIdentifier();
  this->_enabled = other.isEnabled();
  this->setGraphics(other._graphicMode);
  this->_content = std::map<std::string, int>(other._content);
  return *this;
}

void MemoryModule::clearCache() {

}

const std::string &MemoryModule::getIdentifier() const {
  return this->_id;
}

void MemoryModule::display(sf::RenderTexture &texture, sf::Text &writer) {
  sf::RenderTexture bar;
  sf::Sprite spriteBar;
  std::stringstream content;

  bar.create(500, 90);
  Chart::drawProgressBar(bar,  this->_memoryPercent, sf::Color(52, 152, 219), sf::Color(44, 62, 80));
  spriteBar.setTexture(bar.getTexture());
  spriteBar.setPosition(250, 158);
  texture.draw(spriteBar);
  Chart::drawProgressBar(bar,  this->_swapPercent, sf::Color(155, 89, 182), sf::Color(44, 62, 80));
  spriteBar.setTexture(bar.getTexture());
  spriteBar.setPosition(250, 358);
  texture.draw(spriteBar);
  writer.setString("RAM");
  writer.setPosition(100, 180);
  texture.draw(writer);
  content << std::fixed << std::setprecision(2) << this->_memoryPercent << "%";
  writer.setString(content.str());
  writer.setPosition(830, 180);
  texture.draw(writer);
  writer.setString("Swap");
  writer.setPosition(100, 380);
  texture.draw(writer);
  content.clear();
  content.str("");
  content << std::fixed << std::setprecision(2) << this->_swapPercent << "%";
  writer.setString(content.str());
  writer.setPosition(830, 380);
  texture.draw(writer);
}

void MemoryModule::setCacheInterval(unsigned int interval) {
  (void)interval;
}

bool MemoryModule::refresh() {
  std::ifstream		inputFile;
  std::string		name;
  int			value;
  std::string		line;

  inputFile.open("/proc/meminfo");
  if (!inputFile.is_open())
    return false;
  while (std::getline(inputFile, line))
  {
    std::stringstream(line) >> name >> value;
    this->_content[name.substr(0, name.length() - 1)] = value;
  }
  this->_memoryPercent = std::abs(static_cast<float>(this->_content["MemFree"] - this->_content["MemTotal"]) / this->_content["MemTotal"] * 100);
  this->_swapPercent = std::abs(static_cast<float>(this->_content["SwapFree"] - this->_content["SwapTotal"]) / this->_content["SwapTotal"] * 100);
  inputFile.close();
  return true;
}

void MemoryModule::display(WINDOW *ModuleRender) {
  std::stringstream	stream;
  int			MemPadding = this->_content["MemTotal"] / 40;
  int			UsedMemory = this->_content["MemTotal"] - (this->_content["MemFree"]);
  int			MaxMemoryPads = this->_content["MemTotal"] / MemPadding;
  int			MemoryPads = UsedMemory / MemPadding;
  int			SwapMemPadding = this->_content["SwapTotal"] / 40;
  int			SwapUsedMemory = this->_content["SwapTotal"] - this->_content["SwapFree"];
  int			SwapMaxMemoryPads = this->_content["SwapTotal"] / SwapMemPadding;
  int			SwapMemoryPads = SwapUsedMemory / SwapMemPadding;
  int			CurrentSizePad = 5;
  int			MemoryBarH = 5;
  int			SwapMemoryBarH = 7;
  std::string		MaxMemoryS;
  std::string		UsedMemoryS;
  std::string		SwapMaxMemoryS;
  std::string		SwapUsedMemoryS;
  int			termSize[2];

  stream << this->_content["MemTotal"] << " KB";
  MaxMemoryS = stream.str();
  stream.clear();
  stream.str(std::string());
  stream << UsedMemory;
  UsedMemoryS = stream.str();
  stream.clear();
  stream.str(std::string());
  stream << this->_content["SwapTotal"] << " KB";
  SwapMaxMemoryS = stream.str();
  stream.clear();
  stream.str(std::string());
  stream << SwapUsedMemory;
  SwapUsedMemoryS = stream.str();
  stream.clear();
  stream.str(std::string());

  getmaxyx(ModuleRender, termSize[1], termSize[0]);

  MemoryBarH = termSize[1] / 2 - 1;
  SwapMemoryBarH = termSize[1] / 2 + 1;
//  mvwprintw(ModuleRender, 2, CurrentSizePad, "This module displays memory information");

  // Memory Bar

  wattron(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(ModuleRender, MemoryBarH - 3, (termSize[0] / 2) - 3 , "Memory");
  wattroff(ModuleRender, COLOR_PAIR(MODULE_COLOR));

  CurrentSizePad = (termSize[0] / 2) - (static_cast<int>(UsedMemoryS.size() +
    static_cast<int>(MaxMemoryS.size() + 3)) / 2);
  mvwprintw(ModuleRender, MemoryBarH -1, CurrentSizePad, UsedMemoryS.c_str());
  CurrentSizePad += UsedMemoryS.size();
  mvwprintw(ModuleRender, MemoryBarH - 1, CurrentSizePad, " / ");
  CurrentSizePad += 3;
  mvwprintw(ModuleRender, MemoryBarH - 1, CurrentSizePad, MaxMemoryS.c_str());

  CurrentSizePad = (termSize[0] / 2) - (42 / 2);
  mvwprintw(ModuleRender, MemoryBarH, CurrentSizePad, "[");
  CurrentSizePad += 1;
  wattron(ModuleRender, COLOR_PAIR(COLOR_GREEN));
  for (int i = 0 ; i < MemoryPads ; i++) {
    mvwaddch(ModuleRender, MemoryBarH, CurrentSizePad, '|');
    CurrentSizePad += 1;
  }
  wattroff(ModuleRender, COLOR_PAIR(COLOR_GREEN));
  for (int i = 0; i < MaxMemoryPads - MemoryPads; i++) {
    mvwaddch(ModuleRender, MemoryBarH, CurrentSizePad, ' ');
    CurrentSizePad += 1;
  }
  mvwprintw(ModuleRender, MemoryBarH, CurrentSizePad, "]");
  CurrentSizePad += 4;
  CurrentSizePad = (termSize[0] / 2) - (42 / 2);
  // Swap Memory Bar

  wattron(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(ModuleRender, SwapMemoryBarH + 3, (termSize[0] / 2) - 2, "Swap    ");
  wattroff(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(ModuleRender, SwapMemoryBarH, CurrentSizePad, "[");
  CurrentSizePad += 1;
  wattron(ModuleRender, COLOR_PAIR(COLOR_RED));
  for (int i = 0 ; i < SwapMemoryPads ; i++) {
    mvwaddch(ModuleRender, SwapMemoryBarH, CurrentSizePad, '|');
    CurrentSizePad += 1;
  }
  wattroff(ModuleRender, COLOR_PAIR(COLOR_RED));
  for (int i = 0; i < SwapMaxMemoryPads - SwapMemoryPads; i++) {
    mvwaddch(ModuleRender, SwapMemoryBarH, CurrentSizePad, ' ');
    CurrentSizePad += 1;
  }
  mvwprintw(ModuleRender, SwapMemoryBarH, CurrentSizePad, "]   ");
  CurrentSizePad += 4;

  CurrentSizePad = (termSize[0] / 2) - (static_cast<int>(SwapUsedMemoryS.size() +
							 static_cast<int>(SwapMaxMemoryS.size() + 3)) / 2);
  mvwprintw(ModuleRender, SwapMemoryBarH +1, CurrentSizePad, SwapUsedMemoryS.c_str());
  CurrentSizePad += SwapUsedMemoryS.size();
  mvwprintw(ModuleRender, SwapMemoryBarH + 1, CurrentSizePad, " / ");
  CurrentSizePad += 3;
  mvwprintw(ModuleRender, SwapMemoryBarH + 1, CurrentSizePad, SwapMaxMemoryS.c_str());

  wrefresh(ModuleRender);
}


