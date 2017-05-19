/*
** DateTimeModule.cpp for cpp_gkrellm in /home/ventinc/epitech/piscine/cpp_gkrellm/Modules/DateTimeModule.cpp
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
#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule(): _id("Date and Time"), _enabled(true), _graphicMode(Config::GRAPHICS){
  std::clog << "[Info] Create a module : " << this->getIdentifier() << std::endl;
}

DateTimeModule::DateTimeModule(const DateTimeModule &other): _id(other.getIdentifier()), _enabled(other.isEnabled()), _graphicMode(other._graphicMode), _content(other._content) {

}

DateTimeModule::~DateTimeModule() {
  std::clog << "[Info] Module \"" << this->getIdentifier() << "\" destructed" << std::endl;
}

bool DateTimeModule::refresh() {
  std::ifstream		file;
  std::string		line;
  std::string		name;
  std::string		value;

  file.open("/proc/driver/rtc");
  if (!file.is_open()){
    std::clog << "Can't open /proc/driver/rtc" << std::endl;
    return false;
  }
  while (std::getline(file, line)){
    this->_content[name] = value;
    name = line.substr(0, line.find(':') - 1);
    name = Utils::trim(name);
    value = line.substr(line.find(':') + 1);
    value = Utils::trim(value);
    if (name != ""){
      this->_content[name] = value;
    }
  }
  return true;
}

void DateTimeModule::clearCache() {

}

void DateTimeModule::setCacheInterval(unsigned int interval) {
  (void) interval;
}

const std::string &DateTimeModule::getIdentifier() const {
  return this->_id;
}

bool DateTimeModule::isEnabled() const {
  return this->_enabled;
}

void DateTimeModule::enable() {
  this->_enabled = true;
}

void DateTimeModule::disable() {
  this->_enabled = false;
}

void DateTimeModule::display(sf::RenderTexture &texture, sf::Text &writer) {
  sf::Texture logo;
  sf::Sprite logoSprite;

  if (!logo.loadFromFile(Config::datetimePath))
    std::clog << "[Warning] Unable to load image " << Config::datetimePath << std::endl;
  else {
    logo.setSmooth(true);
    logoSprite.setTexture(logo);
    logoSprite.setPosition(Config::width / 2 - logoSprite.getLocalBounds().width / 2 - 40, 50);
    texture.draw(logoSprite);
  }
  writer.setPosition(Config::width / 2 - writer.getLocalBounds().width / 2, 340);
  writer.setString(this->_content["rtc_date"]);
  texture.draw(writer);
  writer.setPosition(Config::width / 2 - writer.getLocalBounds().width / 2, 415);
  writer.setString(this->_content["rtc_time"]);
  texture.draw(writer);


  texture.display();
}

void DateTimeModule::setGraphics(Config::GraphicMode graphics) {
  this->_graphicMode = graphics;
}

IMonitorModule *DateTimeModule::clone() const {
  std::clog << "[Info] Clone : " << this->getIdentifier() << std::endl;
  return new DateTimeModule(*this);
}

DateTimeModule &DateTimeModule::operator=(const DateTimeModule &other) {
  if (other.isEnabled())
    this->enable();
  else
    this->disable();
  this->_content = std::map<std::string, std::string>(other._content);
  this->_id = other.getIdentifier();
  this->setGraphics(other._graphicMode);
  return *this;
}

void DateTimeModule::display(WINDOW *ModuleRender) {
  int		wSize[2];

  getmaxyx(ModuleRender, wSize[1], wSize[0]);
  wattron(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(ModuleRender, (wSize[1] / 2) - 3, (wSize[0] / 2) - 3 / 2, "DAY");
  wattroff(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(ModuleRender, (wSize[1] / 2) - 1, (wSize[0] / 2) - (static_cast<int>((this->_content["rtc_date"]).size()) / 2), this->_content["rtc_date"].c_str());
//  mvwaddch(ModuleRender, (wSize[1] / 2), (wSize[0] / 2) - 1, ACS_HLINE);
//  mvwaddch(ModuleRender, (wSize[1] / 2), (wSize[0] / 2), ACS_HLINE);
//  mvwaddch(ModuleRender, (wSize[1] / 2), (wSize[0] / 2) + 1, ACS_HLINE);
  mvwprintw(ModuleRender, (wSize[1] / 2) + 1, (wSize[0] / 2) - (static_cast<int>((this->_content["rtc_time"]).size()) / 2), this->_content["rtc_time"].c_str());
  wattron(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(ModuleRender, (wSize[1] / 2) + 3, (wSize[0] / 2) - 4 / 2, "TIME");
  wattroff(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  wrefresh(ModuleRender);
}
