/*
** NetworkModule.cpp for cpp_gkrellm in /home/gogo/rendu/tek2/cpp_gkrellm/Modules/NetworkModule.cpp
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
#include "Utils/Utils.hpp"
#include "NetworkModule.hpp"

bool NetworkModule::isEnabled() const {
  return this->_enabled;
}

NetworkModule::NetworkModule() : _id("Network"), _enabled(true), _graphicMode(Config::GRAPHICS), _cacheInterval(25), _cacheIterator(25){
  std::clog << "[Info] Construction of " << this->getIdentifier() << std::endl;
}

NetworkModule::~NetworkModule() {
  std::clog << "[Info] Destruction of " << this->getIdentifier() << std::endl;
}

NetworkModule::NetworkModule(const NetworkModule &other) : _id(other.getIdentifier()), _enabled(other.isEnabled()), _graphicMode(other._graphicMode),
							   _cacheInterval(other._cacheInterval), _cacheIterator(other._cacheIterator){
  this->_content = std::map<std::string, std::map<std::string, unsigned int>>(other._content);
  this->_cache = std::map<std::string, std::map<std::string, unsigned int>>(other._cache);
}

void NetworkModule::enable() {
  this->_enabled = true;
}

void NetworkModule::disable() {
  this->_enabled = false;
}

void NetworkModule::setGraphics(Config::GraphicMode graphics) {
  this->_graphicMode = graphics;
}

IMonitorModule *NetworkModule::clone() const {
  return new NetworkModule(*this);
}

NetworkModule &NetworkModule::operator=(const NetworkModule &other) {
  this->_id = other.getIdentifier();
  this->_enabled = other.isEnabled();
  this->setGraphics(other._graphicMode);
  this->setCacheInterval(other._cacheInterval);
  this->_cacheIterator = other._cacheIterator;
  this->_content = std::map<std::string, std::map<std::string, unsigned int>>(other._content);
  this->_cache = std::map<std::string, std::map<std::string, unsigned int>>(other._cache);
  return *this;
}

void NetworkModule::clearCache() {

}

const std::string &NetworkModule::getIdentifier() const {
  return this->_id;
}

void NetworkModule::setCacheInterval(unsigned int interval) {
  this->_cacheInterval = interval;
}

bool NetworkModule::refresh() {
  std::ifstream		inputFile;
  std::string		name;
  std::string		line;
  unsigned int		rBytes;
  unsigned int		rPackets;
  unsigned int		tBytes;
  unsigned int		tPackets;
  unsigned int		tmp;

  inputFile.open("/proc/net/dev");
  if (!inputFile.is_open())
    return false;

  std::getline(inputFile, line);
  std::getline(inputFile, line);
  while (std::getline(inputFile, line))
  {
    std::stringstream(line) >> name >>rBytes >> rPackets >> tmp
			    >> tmp >> tmp >> tmp
			    >> tmp >> tmp >> tBytes
			    >> tPackets >> tmp >> tmp
			    >> tmp >> tmp >> tmp;
    name = line.substr(0, line.find(':'));
    if (this->_cacheIterator >= this->_cacheInterval){
      this->_cache[name]["rBytes"] = (rBytes - ((this->_content.find(name) != this->_content.end()) ? this->_content[name]["rBytes"] : 0 + 10)) / 1000;
      this->_cache[name]["rPackets"] = (rPackets - ((this->_content.find(name) != this->_content.end()) ? this->_content[name]["rPackets"] : 0 + 10)) / 1000;
      this->_cache[name]["tBytes"] = (tBytes - ((this->_content.find(name) != this->_content.end()) ? this->_content[name]["tBytes"] : 0 + 10)) / 1000;
      this->_cache[name]["tPackets"] = (tPackets - ((this->_content.find(name) != this->_content.end()) ? this->_content[name]["tPackets"] : 0 + 10)) / 1000;
      this->_content[name]["rBytes"] = rBytes;
      this->_content[name]["rPackets"] = rPackets;
      this->_content[name]["tBytes"] = tBytes;
      this->_content[name]["tPackets"] = tPackets;

    }
  }
  if (this->_cacheIterator >= this->_cacheInterval)
    this->_cacheIterator = 0;
  else
    this->_cacheIterator += 1;
  inputFile.close();
  return true;
}

void NetworkModule::display(sf::RenderTexture &texture, sf::Text &writer) {
  unsigned int		iterator = 0;
  std::stringstream 	content;

  for (std::map<std::string, std::map<std::string, unsigned int>>::iterator it = this->_cache.begin(); it != this->_cache.end(); ++it)
  {
    writer.setString(std::string(it->first + "\t")
		     + ":\t" + std::to_string(it->second["rBytes"])
		     + "KB down, " + std::to_string(it->second["tBytes"]) + "KB up");
    writer.setPosition(Config::width / 2 - writer.getLocalBounds().width / 2, 50 + (iterator * 75));
    texture.draw(writer);
    iterator += 1;
  }
  texture.display();
}

void NetworkModule::display(WINDOW *ModuleRender) {
  int		termSize[2];
  int		Hpad = -5;
  std::stringstream	format;
  std::string		formatS;

  getmaxyx(ModuleRender, termSize[1], termSize[0]);

  for (std::map<std::string, std::map<std::string, unsigned int>>::iterator it = this->_cache.begin(); it != this->_cache.end(); ++it) {
    wattron(ModuleRender, COLOR_PAIR(MODULE_COLOR));
    mvwprintw(ModuleRender, (termSize[1] / 2) + Hpad, (termSize[0] / 2) - (static_cast<int>(Utils::trim(it->first).size()) / 2), Utils::trim(it->first).c_str());
    wattroff(ModuleRender, COLOR_PAIR(MODULE_COLOR));
    format.clear();
    format.str(std::string());
    format << it->second["rBytes"] << " KB Up" << " / " << it->second["tBytes"] << " KB Down";
    formatS = format.str();
    Hpad += 2;
    mvwprintw(ModuleRender, (termSize[1] / 2) + Hpad, (termSize[0] / 2) - (static_cast<int>(formatS.size()) / 2 ), formatS.c_str());
    mvwprintw(ModuleRender, (termSize[1] / 2) + Hpad, (termSize[0] / 2) + (static_cast<int>(formatS.size()) / 2 ) + 1, "               ");
    Hpad += 2;
  }

  wrefresh(ModuleRender);
}


