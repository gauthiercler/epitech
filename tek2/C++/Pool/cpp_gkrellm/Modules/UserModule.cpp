/*
** UserModule.cpp for cpp_gkrellm in /home/ventinc/epitech/piscine/cpp_gkrellm/Modules/UserModule.cpp
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
#include "Charts/Chart.hpp"
#include "Env/Env.hpp"
#include "UserModule.hpp"


UserModule::UserModule(): _id("User"), _enabled(true), _graphicMode(Config::GRAPHICS){
  std::clog << "[Info] Create a module : " << this->getIdentifier() << std::endl;
}

UserModule::UserModule(const UserModule &other): _id(other.getIdentifier()), _enabled(other.isEnabled()), _graphicMode(other._graphicMode), _content(other._content) {

}

UserModule::~UserModule() {
  std::clog << "[Info] Module \"" << this->getIdentifier() << "\" destructed" << std::endl;
}

bool UserModule::refresh() {
  std::ifstream		file;
  std::stringstream	content;

  file.open("/proc/sys/kernel/hostname");
  if (!file.is_open()){
    std::clog << "[ERROR] Can't open /proc/sys/kernel/hostname" << std::endl;
    return false;
  };
  content << file.rdbuf();
  file.close();
  this->_content["userName"] = "Koala";
  this->_content["machineName"] = content.str().erase(content.str().find_last_not_of("\n")+1);
  if (Env::env["USER"] != "")
    this->_content["userName"] = Env::env.at("USER");
  return true;
}

void UserModule::clearCache() {

}

void UserModule::setCacheInterval(unsigned int interval) {
  (void) interval;
}

const std::string &UserModule::getIdentifier() const {
  return this->_id;
}

bool UserModule::isEnabled() const {
  return this->_enabled;
}

void UserModule::enable() {
  this->_enabled = true;
}

void UserModule::disable() {
  this->_enabled = false;
}

void UserModule::display(sf::RenderTexture &texture, sf::Text &writer) {
  sf::Texture logo;
  sf::Sprite logoSprite;

  if (!logo.loadFromFile(Config::userPath))
    std::clog << "[Warning] Unable to load image " << Config::userPath << std::endl;
  else {
    logo.setSmooth(true);
    logoSprite.setTexture(logo);
    logoSprite.setPosition(372, 50);
    texture.draw(logoSprite);
  }
  writer.setString(std::string("{Machine} - ") + this->_content["machineName"]);
  writer.setPosition(Config::width / 2 - writer.getLocalBounds().width / 2, 340);
  texture.draw(writer);
  writer.setString(std::string("{Username} - ") + this->_content["userName"]);
  writer.setPosition(Config::width / 2 - writer.getLocalBounds().width / 2, 415);
  texture.draw(writer);
  texture.display();
}

void UserModule::setGraphics(Config::GraphicMode graphics) {
  this->_graphicMode = graphics;
}

IMonitorModule *UserModule::clone() const {
  std::clog << "[Info] Clone : " << this->getIdentifier() << std::endl;
  return new UserModule(*this);
}

UserModule &UserModule::operator=(const UserModule &other) {
  if (other.isEnabled())
    this->enable();
  else
    this->disable();
  this->_content = std::map<std::string, std::string>(other._content);
  this->_id = other.getIdentifier();
  this->setGraphics(other._graphicMode);
  return *this;
}

void UserModule::display(WINDOW *ModuleRender) {
  int		wSize[2];

  getmaxyx(ModuleRender, wSize[1], wSize[0]);
  wattron(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(ModuleRender, (wSize[1] / 2) - 3, (wSize[0] / 2) - 7 / 2, "MACHINE");
  wattroff(ModuleRender, COLOR_PAIR(MODULE_COLOR));

  mvwprintw(ModuleRender, (wSize[1] / 2) - 1, (wSize[0] / 2) - (static_cast<int>((this->_content["machineName"]).size()) / 2), this->_content["machineName"].c_str());
//  mvwaddch(ModuleRender, (wSize[1] / 2), (wSize[0] / 2) - 1, ACS_HLINE);
//  mvwaddch(ModuleRender, (wSize[1] / 2), (wSize[0] / 2), ACS_HLINE);
//  mvwaddch(ModuleRender, (wSize[1] / 2), (wSize[0] / 2) + 1, ACS_HLINE);
  mvwprintw(ModuleRender, (wSize[1] / 2) + 1, (wSize[0] / 2) - (static_cast<int>((this->_content["userName"]).size()) / 2), this->_content["userName"].c_str());
  wattron(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  mvwprintw(ModuleRender, (wSize[1] / 2) + 3, (wSize[0] / 2) - 4 / 2, "USER");
  wattroff(ModuleRender, COLOR_PAIR(MODULE_COLOR));
  wrefresh(ModuleRender);
}
