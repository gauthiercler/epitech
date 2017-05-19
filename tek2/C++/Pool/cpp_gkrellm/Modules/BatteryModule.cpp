/*
** BatteryModule.cpp for cpp_gkrellm in /home/ventinc/epitech/piscine/cpp_gkrellm/Modules/BatteryModule.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sat Jan 21 12:01:46 2017 Vincent DUSAUTOIR
** Last update Sat Jan 21 12:01:46 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include "Utils/Utils.hpp"
#include "Charts/Chart.hpp"
#include "Env/Env.hpp"
#include "BatteryModule.hpp"


BatteryModule::BatteryModule(): _id("Battery"), _enabled(true), _graphicMode(Config::GRAPHICS){
  std::clog << "[Info] Create a module : " << this->getIdentifier() << std::endl;
}

BatteryModule::BatteryModule(const BatteryModule &other): _id(other.getIdentifier()), _enabled(other.isEnabled()), _graphicMode(other._graphicMode), _content(other._content) {

}

BatteryModule::~BatteryModule() {
  std::clog << "[Info] Module \"" << this->getIdentifier() << "\" destructed" << std::endl;
}

bool BatteryModule::refresh() {
  std::ifstream		file;
  std::stringstream	content;

  file.open("/sys/class/power_supply/BAT0/capacity");
  if (!file.is_open()){
    std::clog << "[ERROR] Can't open /sys/class/power_supply/BAT0/capacity" << std::endl;
    return false;
  };
  content << file.rdbuf();
  file.close();
  this->_content["capacity"] = content.str();
  file.open("/sys/class/power_supply/BAT0/technology");
  if (!file.is_open()){
    std::clog << "[ERROR] Can't open /sys/class/power_supply/BAT0/technology" << std::endl;
    return false;
  };
  content.clear();
  content.str("");
  content << file.rdbuf();
  file.close();
  this->_content["technology"] = content.str();
  return true;
}

void BatteryModule::clearCache() {

}

void BatteryModule::setCacheInterval(unsigned int interval) {
  (void) interval;
}

const std::string &BatteryModule::getIdentifier() const {
  return this->_id;
}

bool BatteryModule::isEnabled() const {
  return this->_enabled;
}

void BatteryModule::enable() {
  this->_enabled = true;
}

void BatteryModule::disable() {
  this->_enabled = false;
}

void BatteryModule::display(sf::RenderTexture &texture, sf::Text &writter) {
  sf::RenderTexture bar;
  sf::Sprite spriteBar;
  float capacity;


  std::stringstream(this->_content["capacity"]) >> capacity;
  this->_content["capacity"] = Utils::trim(this->_content["capacity"]);
  writter.setString("Battery " + this->_content["technology"]);
  writter.setPosition(410, 150);
  texture.draw(writter);
  writter.setString(this->_content["capacity"] + " %");
  writter.setPosition(475, 420);
  texture.draw(writter);
  bar.create(960, 180);
  Chart::drawProgressBar(bar, capacity, sf::Color(46, 204, 113), sf::Color(44, 62, 80));
  spriteBar.setTexture(bar.getTexture());
  spriteBar.setPosition(20, 313 - 90);
  texture.draw(spriteBar);
}

void BatteryModule::setGraphics(Config::GraphicMode graphics) {
  this->_graphicMode = graphics;
}

IMonitorModule *BatteryModule::clone() const {
  std::clog << "[Info] Clone : " << this->getIdentifier() << std::endl;
  return new BatteryModule(*this);
}

BatteryModule &BatteryModule::operator=(const BatteryModule &other) {
  if (other.isEnabled())
    this->enable();
  else
    this->disable();
  this->_content = std::map<std::string, std::string>(other._content);
  this->_id = other.getIdentifier();
  this->setGraphics(other._graphicMode);
  return *this;
}

void BatteryModule::display(WINDOW *ModuleRender) {
  int	termSize[2];
  std::stringstream	string;
  int			capacity;
  int	pad;

  getmaxyx(ModuleRender, termSize[1], termSize[0]);
  wattron(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(ModuleRender, (termSize[1] / 2) - 1, (termSize[0] / 2) - 10/2, "Battery   ");
  wattroff(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(ModuleRender, (termSize[1] / 2) - 1, (termSize[0] / 2) + 10/2 + 1, Utils::trim(this->_content["technology"]).c_str());

  pad = (termSize[0] / 2) - 21;
  mvwprintw(ModuleRender, termSize[1] / 2 + 1, pad, "[");
  pad += 1;

  string.clear();
  string.str( std::string());

  string << this->_content["capacity"];
  string >> capacity;

  wattron(ModuleRender, COLOR_PAIR(COLOR_GREEN));
  for (int i = 0; i < capacity / 2.5; i++) {
    mvwaddch(ModuleRender, termSize[1] / 2 + 1, pad, '|');
    pad += 1;
  }
  wattroff(ModuleRender, COLOR_PAIR(COLOR_GREEN));
  for (int i = 0; i < 40 - capacity / 2.5; i++) {
    mvwaddch(ModuleRender, termSize[1] / 2 + 1, pad, ' ');
    pad += 1;
  }
  mvwprintw(ModuleRender, termSize[1] / 2 + 1, pad, "]");
  pad += 3;
  string.clear();
  string.str(std::string());
  string << Utils::trim(this->_content["capacity"]);
  string << " %%";
  mvwprintw(ModuleRender, termSize[1] / 2 + 1, pad, Utils::trim(string.str()).c_str());
  wrefresh(ModuleRender);
}
