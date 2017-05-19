/*
** FlyModule.cpp for cpp_gkrellm in /home/gogo/rendu/tek2/cpp_gkrellm/Modules/FlyModule.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Jan 22 05:29:01 2017 Gauthier CLER
** Last update Sun Jan 22 05:29:01 2017 Gauthier CLER
*/

#include <iostream>
#include <fstream>
#include "FlyModule.hpp"

FlyModule::FlyModule(): _id("Dan's favorite animal"), _enabled(false), _graphicMode(Config::GRAPHICS), _state(0){
  std::clog << "[Info] Create a module : " << this->getIdentifier() << std::endl;
}

FlyModule::FlyModule(const FlyModule &other): _id(other.getIdentifier()), _enabled(other.isEnabled()), _graphicMode(other._graphicMode), _state(other._state) {

}

FlyModule::~FlyModule() {
  std::clog << "[Info] Module \"" << this->getIdentifier() << "\" destructed" << std::endl;
}

bool FlyModule::refresh() {
  return true;
}

void FlyModule::clearCache() {

}

void FlyModule::setCacheInterval(unsigned int interval) {
  (void) interval;
}

const std::string &FlyModule::getIdentifier() const {
  return this->_id;
}

bool FlyModule::isEnabled() const {
  return this->_enabled;
}

void FlyModule::enable() {
  this->_enabled = true;
}

void FlyModule::disable() {
  this->_enabled = false;
}

void FlyModule::display(sf::RenderTexture &texture, sf::Text &writter) {
  sf::Texture logo;
  sf::Sprite logoSprite;
  bool		openRet;

  if (this->_state)
    openRet = logo.loadFromFile(Config::flyPath1);
  else
    openRet = logo.loadFromFile(Config::flyPath2);
  if (!openRet)
    std::clog << "[Warning] Unable to load image " << Config::userPath << std::endl;
  else {
    logo.setSmooth(true);
    logoSprite.setTexture(logo);
    logoSprite.setScale(2.5, 2.5);
    logoSprite.setPosition(175, 50);
    this->_state = !(this->_state);
    texture.draw(logoSprite);
  }
  (void)writter;
}

void FlyModule::setGraphics(Config::GraphicMode graphics) {
  this->_graphicMode = graphics;
}

IMonitorModule *FlyModule::clone() const {
  std::clog << "[Info] Clone : " << this->getIdentifier() << std::endl;
  return new FlyModule(*this);
}

FlyModule &FlyModule::operator=(const FlyModule &other) {
  if (other.isEnabled())
    this->enable();
  else
    this->disable();
  this->setGraphics(other._graphicMode);
  return *this;
}

void FlyModule::display(WINDOW *ModuleRender) {
  (void)ModuleRender;
}
