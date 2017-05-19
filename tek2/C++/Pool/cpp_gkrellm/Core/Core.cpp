/*
** Core.cpp for cpp_gkrellm in /home/foret_a/Lab/cpp_gkrellm/Core/Core.cpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 21 08:56:09 2017 Antoine FORET
** Last update Sat Jan 21 08:56:09 2017 Antoine FORET
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <dlfcn.h>
#include "Modules/FlyModule.hpp"
#include "Modules/NetworkModule.hpp"
#include "Modules/BatteryModule.hpp"
#include "Modules/UserModule.hpp"
#include "Modules/SystemModule.hpp"
#include "Modules/MemoryModule.hpp"
#include "Modules/DateTimeModule.hpp"
#include "Modules/MemoryModule.hpp"
#include "Modules/ProcessorModule.hpp"
#include "Graphics/SFMLEngine/SFMLEngine.hpp"
#include <Graphics/NCurses/NCursesEngine.hpp>
#include "Core.hpp"

Core::Core(Config::GraphicMode mode) : _graphicsEngine(nullptr), _cachedError(0), _mode(mode) {
  std::clog << "[Info] Load Graphics engine" << std::endl;
  this->registerBaseModules();
  this->loadGraphicsEngine();
  if (mode != Config::GraphicMode::TERM) // Avoid display on ncurse screen
    std::clog << "[Info] Core loaded" << std::endl;
}

Core::~Core() {
  std::vector<IMonitorModule *>::iterator it = this->_registeredModules.begin();

  std::clog << "[Info] Destuct Core" << std::endl;
  if (this->_graphicsEngine != nullptr)
    delete this->_graphicsEngine;
  while (it != this->_registeredModules.end())
  {
    delete *it;
    ++it;
  }
  std::clog << "[Info] Core destructed" << std::endl;
}

std::string GetLineFromCin() {
  std::string line;

  std::cin >> line;
//  std::getline(std::cin, line);
  return line;
}


bool Core::run() {
  if (this->_graphicsEngine == NULL)
  {
    std::cerr << "[Error] No display engine defined. Exit Core" << std::endl;
    return false;
  }
  if (this->_registeredModules.size() == 0)
    std::cerr << "[Warning] No module loaded." << std::endl;
  while (this->_graphicsEngine->isOpen() && this->_cachedError < 5)
  {
    try
    {
      this->gatherDatas();
      this->display();
    } catch (std::exception &e)
    {
      this->_cachedError += 1;
      std::cerr << "[Error] Core caught " << e.what() << " (" << this->_cachedError << " caught of 5)" << std::endl;
    }
  }
  if (this->_cachedError >= 5)
  {
    std::cerr << "[Error] Too much error cached. Program is still unstable. Exit core" << std::endl;
    return false;
  }
  return true;
}

void Core::registerModule(const IMonitorModule &module) {
  IMonitorModule *internalModule = module.clone();

  internalModule->setGraphics(this->_mode);
  this->_registeredModules.push_back(internalModule);
  this->reloadModules();
}

void Core::unregisterModule(const std::string &identifier) {
  std::vector<IMonitorModule *>::iterator it = this->_registeredModules.begin();

  while (it != this->_registeredModules.end())
  {
    if ((*it)->getIdentifier() == identifier)
    {
      delete *it;
      it = this->_registeredModules.erase(it);
    }
    else
      ++it;
  }
  this->reloadModules();
}

IMonitorModule &Core::getModule(const std::string &identifier) {
  std::vector<IMonitorModule *>::iterator it = this->_registeredModules.begin();

  while (it != this->_registeredModules.end())
  {
    if ((*it)->getIdentifier() == identifier)
      return **it;
    ++it;
  }
  return **this->_registeredModules.begin();
}

void Core::display() {
  if (this->_graphicsEngine != nullptr)
    this->_graphicsEngine->display(this->_enabledModules, this->_registeredModules);
  this->reloadModules();
}

void Core::reloadModules() {
  std::vector<IMonitorModule *>::iterator it = this->_registeredModules.begin();

  this->_enabledModules.clear();
  while (it != this->_registeredModules.end())
  {
    if ((*it)->isEnabled())
      this->_enabledModules.push_back(*it);
    ++it;
  }
}

void Core::gatherDatas() {
  std::vector<IMonitorModule *>::iterator it = this->_enabledModules.begin();

  while (it != this->_enabledModules.end())
  {
    (*it)->refresh();
    ++it;
  }
}

void Core::loadGraphicsEngine() {
  if (this->_mode == Config::GRAPHICS)
    this->_graphicsEngine = new SFMLEngine(this->_enabledModules);
  else if (this->_mode == Config::TERM)
    this->_graphicsEngine = new NCursesEngine(this->_enabledModules);
}

void Core::registerBaseModules() {
  this->registerModule(UserModule());
  this->registerModule(SystemModule());
  this->registerModule(DateTimeModule());
  this->registerModule(MemoryModule());
  this->registerModule(ProcessorModule());
  this->registerModule(NetworkModule());
  this->registerModule(BatteryModule());
  this->registerModule(FlyModule());
}
