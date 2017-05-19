/*
** ProcessorModule.cpp for cpp_gkrellm in /home/ventinc/epitech/piscine/cpp_gkrellm/Modules/ProcessorModule.cpp
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
#include <iomanip>
#include "Charts/Chart.hpp"
#include "Utils/Utils.hpp"
#include "ProcessorModule.hpp"

ProcessorModule::ProcessorModule(): _id("CPU"), _enabled(true), _graphicMode(Config::GRAPHICS){
  std::clog << "[Info] Create a module : " << this->getIdentifier() << std::endl;
  this->setCacheInterval(400);
}

ProcessorModule::ProcessorModule(const ProcessorModule &other): _id(other.getIdentifier()), _enabled(other.isEnabled()), _graphicMode(other._graphicMode), _content(other._content), _cacheInterval(other._cacheInterval) {

}

ProcessorModule::~ProcessorModule() {
  std::clog << "[Info] Module \"" << this->getIdentifier() << "\" destructed" << std::endl;
}

bool ProcessorModule::refresh() {
  std::ifstream		file;
  std::string		line;
  std::string		name;
  float			user;
  float			nice;
  float			system;
  float			idle;
  float			iowait;
  float			irq;
  float			softirq;
  float			steal;
  float			guest;
  float			guest_nice;


  file.open("/proc/stat");
  if (!file.is_open()){
    std::clog << "[ERROR] Can't open /proc/stat" << std::endl;
    return false;
  };
  while (std::getline(file, line)){
    if (line.length() >= 3 && line.substr(0, 3) == "cpu"){
      std::stringstream(line) >> name >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;
      this->_content[name]["user"] = user;
      this->_content[name]["nice"] = nice;
      this->_content[name]["system"] = system;
      this->_content[name]["idle"] = idle;
      this->_content[name]["iowait"] = iowait;
      this->_content[name]["irq"] = irq;
      this->_content[name]["softirq"] = softirq;
      this->_content[name]["steal"] = steal;
      this->_content[name]["guest"] = guest;
      this->_content[name]["guest_nice"] = guest_nice;
      this->computePercentages(this->_content[name], name);
    }
  }
  file.close();
  file.open("/proc/cpuinfo");
  if (!file.is_open()){
    std::clog << "[ERROR] Can't open /proc/cpuinfo" << std::endl;
    return false;
  };
  while (std::getline(file, line)){
    if (line.length() >= 10 && line.substr(0, 10) == "model name"){
      this->_modelName = line.substr(line.find(':') + 1);
      this->_modelName = Utils::trim(this->_modelName);
      break;
    }
  }
  file.close();
  return true;
}

void ProcessorModule::clearCache() {
  this->_cache.clear();
}

void ProcessorModule::setCacheInterval(unsigned int interval) {
  this->_cacheInterval = interval;
}

const std::string &ProcessorModule::getIdentifier() const {
  return this->_id;
}

bool ProcessorModule::isEnabled() const {
  return this->_enabled;
}

void ProcessorModule::enable() {
  this->_enabled = true;
}

void ProcessorModule::disable() {
  this->_enabled = false;
  this->clearCache();
}

void ProcessorModule::setGraphics(Config::GraphicMode graphics) {
  this->_graphicMode = graphics;
}

void ProcessorModule::computePercentages(std::map<std::string, float> container,const std::string &name) {
  float		work;
  float		total;
  float		diff_work;
  float		diff_total;

  if (this->_count.find(name) == this->_count.end())
    this->_count[name] = 10;
  if (this->_count[name] != 10)
    this->_count[name]++;
  else {
    total = container["user"] + container["nice"] + container["system"] + container["idle"] + container["iowait"] + container["irq"] + container["softirq"] + container["steal"] + container["steal"] + container["guest"] + container["guest_nice"];
    work = container["user"] + container["nice"] + container["system"];
    diff_work = work;
    if (this->_prev_work.find(name) != this->_prev_work.end())
      diff_work -= this->_prev_work[name];
    diff_total = total;
    if (this->_prev_total.find(name) != this->_prev_total.end())
      diff_total -= this->_prev_total[name];
    this->_percentages[name] = (diff_work / diff_total) * 100;
    this->_prev_total[name] = total;
    this->_prev_work[name] = work;
    this->_cache[name].push_back(this->_percentages[name]);
    if (this->_cache[name].size() > this->_cacheInterval)
      this->_cache[name].pop_front();
    this->_count[name] = 0;
  }
}

void     ProcessorModule::display(sf::RenderTexture &texture, sf::Text &writter){
  std::stringstream content;
  std::string name;
  sf::RenderTexture bar;
  sf::Sprite spriteBar;
  std::map<std::string, std::map<std::string, float>>::iterator it;
  unsigned int		i = 0;

  it = this->_content.begin();
  bar.create(500, 28);
  while (it != this->_content.end()){
    name = it->first;
    std::transform(name.begin(), name.end(), name.begin(), ::toupper);
    content.clear();
    content.str("");
    content << std::fixed << std::setprecision(2) << this->_percentages[it->first] << " %";
    writter.setString(name);
    writter.setPosition(100, 50 + (50 * i));
    texture.draw(writter);
    writter.setString(content.str());
    writter.setPosition(830, 50 + (50 * i));
    texture.draw(writter);
    if (this->_percentages[it->first] > 80)
      Chart::drawProgressBar(bar, this->_percentages[it->first], sf::Color(231, 76, 60), sf::Color(44, 62, 80));
    else if (this->_percentages[it->first] > 65)
      Chart::drawProgressBar(bar, this->_percentages[it->first], sf::Color(230, 126, 34), sf::Color(44, 62, 80));
    else
      Chart::drawProgressBar(bar, this->_percentages[it->first], sf::Color(46, 204, 113), sf::Color(44, 62, 80));
    spriteBar.setTexture(bar.getTexture());
    spriteBar.setPosition(250, 58 + (49 * i));
    texture.draw(spriteBar);
    ++it;
    i++;
  }
  writter.setString(this->_modelName);
  writter.setPosition(220, this->_content.size() * 60 + 10);
  texture.draw(writter);
}

IMonitorModule *ProcessorModule::clone() const {
  std::clog << "[Info] Clone : " << this->getIdentifier() << std::endl;
  return new ProcessorModule(*this);
}

ProcessorModule &ProcessorModule::operator=(const ProcessorModule &other) {
  if (other.isEnabled())
    this->enable();
  else
    this->disable();
  this->_content = std::map<std::string, std::map<std::string, float>>(other._content);
  this->_id = other.getIdentifier();
  this->setGraphics(other._graphicMode);
  return *this;
}

void ProcessorModule::display(WINDOW *ModuleRender) {
  std::map<std::string, std::map<std::string, float>>::iterator it;
  int			termSize[2];
  std::stringstream 	content;
  std::string		PercentageS;
  std::string		name;
  int			CurrentSizePad = 5;
  int			BarH = 5;


  getmaxyx(ModuleRender, termSize[1], termSize[0]);
  CurrentSizePad = (termSize[0] / 2) - (52 / 2);
  it = this->_content.begin();
  while (it != this->_content.end()) {

    name = it->first;
    std::transform(name.begin(), name.end(), name.begin(), ::toupper);

    content.clear();
    content.str("");
    content << std::fixed << std::setprecision(2) << this->_percentages[it->first];
    PercentageS = content.str();

/*    if (name != "CPU") {
      BarH = termSize[1] / 2 - 2;
    }*/

    wattron(ModuleRender, COLOR_PAIR(MODULE_COLOR));
    mvwprintw(ModuleRender, BarH, CurrentSizePad, name.c_str());
    CurrentSizePad += name.size();
    wattroff(ModuleRender, COLOR_PAIR(MODULE_COLOR));

    if (name == "CPU") {
      mvwaddch(ModuleRender, BarH, CurrentSizePad, ' ');
      CurrentSizePad += 1;
    }
    mvwprintw(ModuleRender, BarH, CurrentSizePad, " [");
    CurrentSizePad += 2;

    if (this->_percentages[it->first] > 80) {
      wattron(ModuleRender, COLOR_PAIR(COLOR_RED));
    }
    else if (this->_percentages[it->first] > 60) {
      wattron(ModuleRender, COLOR_PAIR(COLOR_YELLOW));
    }
    else {
      wattron(ModuleRender, COLOR_PAIR(COLOR_GREEN));
    }

    for (int i = 0; i < this->_percentages[it->first] / 2.5; i++) {
      mvwaddch(ModuleRender, BarH, CurrentSizePad, '|');
      CurrentSizePad += 1;
    }

    if (this->_percentages[it->first] > 80) {
      wattroff(ModuleRender, COLOR_PAIR(COLOR_RED));
    }
    else if (this->_percentages[it->first] > 60) {
      wattroff(ModuleRender, COLOR_PAIR(COLOR_YELLOW));
    }
    else {
      wattroff(ModuleRender, COLOR_PAIR(COLOR_GREEN));
    }

    for (int i = 0; i < (40 - (this->_percentages[it->first] / 2.5)); i++) {
      mvwaddch(ModuleRender, BarH, CurrentSizePad, ' ');
      CurrentSizePad += 1;
    }

    mvwprintw(ModuleRender, BarH, CurrentSizePad, "]   ");
    CurrentSizePad += 4;
    mvwprintw(ModuleRender, BarH, CurrentSizePad, PercentageS.c_str());
    CurrentSizePad += PercentageS.size();
    mvwprintw(ModuleRender, BarH, CurrentSizePad, " %%");
    CurrentSizePad += 2;
    BarH += 2;
    if (name == "CPU") {
      BarH = termSize[1] / 2 - 4;
    }
    CurrentSizePad = (termSize[0] / 2) - (52 / 2);
    ++it;
  }
  wrefresh(ModuleRender);
}
