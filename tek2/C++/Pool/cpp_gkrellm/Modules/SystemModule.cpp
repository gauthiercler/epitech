/*
** SystemModule.cpp for cpp_gkrellm in /home/gogo/rendu/tek2/cpp_gkrellm/Modules/SystemModule.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Jan 21 12:01:22 2017 Gauthier CLER
** Last update Sat Jan 21 12:01:24 2017 Gauthier CLER
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "SystemModule.hpp"

bool SystemModule::isEnabled() const {
  return this->_enabled;
}

SystemModule::SystemModule() : _id("Operating System"), _enabled(true), _graphicMode(Config::GRAPHICS) {
  std::clog << "[Info] Construction of " << this->getIdentifier() << std::endl;
}

SystemModule::~SystemModule() {
  std::clog << "[Info] Destruction of " << this->getIdentifier() << std::endl;
}

SystemModule::SystemModule(const SystemModule &other) : _id(other.getIdentifier()), _enabled(other.isEnabled()), _graphicMode(other._graphicMode) {
  this->_content = std::map<std::string, std::string>(other._content);
}

void SystemModule::enable() {
  this->_enabled = true;
}

void SystemModule::disable() {
  this->_enabled = false;
}

void SystemModule::setGraphics(Config::GraphicMode graphics) {
  this->_graphicMode = graphics;
}

IMonitorModule *SystemModule::clone() const {
  return new SystemModule(*this);
}

SystemModule &SystemModule::operator=(const SystemModule &other) {
  this->_id = other.getIdentifier();
  this->_enabled = other.isEnabled();
  this->setGraphics(other._graphicMode);
  this->_content = std::map<std::string, std::string>(other._content);
  return *this;
}

void SystemModule::clearCache() {

}

const std::string &SystemModule::getIdentifier() const {
  return this->_id;
}

void SystemModule::display(sf::RenderTexture &texture, sf::Text &writer) {
  sf::Texture logo;
  sf::Sprite logoSprite;

  if (!logo.loadFromFile(Config::linuxPath))
    std::clog << "[Warning] Unable to load image " << Config::linuxPath << std::endl;
  else {
    logo.setSmooth(true);
    logoSprite.setTexture(logo);
    logoSprite.setPosition(372, 50);
    texture.draw(logoSprite);
  }
  writer.setPosition(340, 340);
  writer.setString(std::string("{OS} ") + this->_content["operatingSystem"]);
  texture.draw(writer);

  writer.setPosition(195, 415);
  writer.setString(std::string("{Kernel version} ") + this->_content["kernel"]);
  texture.draw(writer);

  texture.display();
}

void SystemModule::setCacheInterval(unsigned int interval) {
  (void)interval;
}

bool SystemModule::refresh() {
  std::ifstream		inputFile;
  std::stringstream	text;

  inputFile.open("/etc/issue.net");
  if (!inputFile.is_open())
    return false;
  text << inputFile.rdbuf();
  this->_content["operatingSystem"]  = text.str();
  inputFile.close();
  inputFile.open("/proc/version");
  if (!inputFile.is_open())
    return false;
  text.clear();
  text.str("");
  text << inputFile.rdbuf();
  this->_content["kernel"]  = text.str().substr(0, text.str().find("("));
  inputFile.close();
  return true;
}

void SystemModule::display(WINDOW *ModuleRender) {
  int		wSize[2];

  getmaxyx(ModuleRender, wSize[1], wSize[0]);
  wattron(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(ModuleRender, (wSize[1] / 2) - 3, (wSize[0] / 2) - 2 / 2, "OS");
  wattroff(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(ModuleRender, (wSize[1] / 2) - 1, (wSize[0] / 2) - (static_cast<int>((this->_content["operatingSystem"]).size()) / 2), this->_content["operatingSystem"].c_str());
//  mvwaddch(ModuleRender, (wSize[1] / 2), (wSize[0] / 2) - 1, ACS_HLINE);
//  mvwaddch(ModuleRender, (wSize[1] / 2), (wSize[0] / 2), ACS_HLINE);
//  mvwaddch(ModuleRender, (wSize[1] / 2), (wSize[0] / 2) + 1, ACS_HLINE);
  mvwprintw(ModuleRender, (wSize[1] / 2) + 1, (wSize[0] / 2) - (static_cast<int>((this->_content["kernel"]).size()) / 2), this->_content["kernel"].c_str());
  wattron(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(ModuleRender, (wSize[1] / 2) + 3, (wSize[0] / 2) - 6 / 2, "KERNEL");
  wattroff(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  wrefresh(ModuleRender);
}


