/*
** Menu.cpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/sources/menu/Menu.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed May 24 10:48:07 2017 Vincent DUSAUTOIR
** Last update Wed May 24 10:48:07 2017 Vincent DUSAUTOIR
*/

#include	<iostream>
#include <menu/PlayerSelectMenu.hpp>
#include	"Engine.hpp"
#include	"core/Core.hpp"
#include        "controllers/MenuController.hpp"
#include        "menu/OptionsMenu.hpp"
#include        "menu/HomeMenu.hpp"
#include	"menu/MapSelectMenu.hpp"
#include	"menu/HighscoreMenu.hpp"


indie::Menu::Menu(Core &core) :
  _core(core),
  _hasSave(false) {

  _menus.push_back(std::make_unique<HomeMenu>(*this));
  _menus.push_back(std::make_unique<OptionsMenu>(*this));
  _menus.push_back(std::make_unique<PlayerSelectMenu>(*this));
  _menus.push_back(std::make_unique<MapSelectMenu>(*this));
  _menus.push_back(std::make_unique<HighscoreMenu>(*this));

  Engine::get().getSoundManager().switchGlobalVolume();
  Engine::get().getSoundManager().playSound("Bomberman");
  Engine::get().getSoundManager().enableSoundLoop("StageSelect");
  Engine::get().getSoundManager().playSound("StageSelect");
  Engine::get().getSoundManager().stopSound("Bomberman");
  Engine::get().getSoundManager().stopSound("StageSelect");
  Engine::get().getSoundManager().switchGlobalVolume();
}

indie::Menu::~Menu() {

}

bool indie::Menu::render() {
  _menus.at(this->_currentMenu)->render();
  return true;
}

bool indie::Menu::clear() {
  Engine::get().getSceneManager()->getGUIEnvironment()->clear();
  return true;
}

bool indie::Menu::update() {
  return false;
}

void indie::Menu::receiveEvent(const indie::EventManager &eventManager) {
  _menus.at(this->_currentMenu)->receiveEvent(eventManager);
}

void indie::Menu::changeCurrentMenu(indie::Menu::MenuType menu) {
  _currentMenu = menu;
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->clear();
  Engine::get().getWindowManager().setGUITransparency(0);
  _menus.at(this->_currentMenu)->buildElements();
}

void indie::Menu::close() const {
  _core.close();
}

void indie::Menu::setActive(bool)
{
  this->changeCurrentMenu(Menu::MAIN);
}

void indie::Menu::changeToGame(const MapAttributes &map) const {
  Engine::get().getSoundManager().stopSound("StageSelect");

  _core.changeToGame(map, _menus.at(PLAYER_SELECT)->getPlayerConfig());
}

void indie::Menu::changeToGame(void) const {
  Engine::get().getSoundManager().stopSound("StageSelect");

  _core.changeToGame(_menus.at(PLAYER_SELECT)->getPlayerConfig());
}

bool indie::Menu::hasSave() const {
  return _hasSave;
}

std::vector<std::pair<irr::io::path, indie::MapAttributes>> const &indie::Menu::getMaps(void) const {
  return _core.getMaps();
}