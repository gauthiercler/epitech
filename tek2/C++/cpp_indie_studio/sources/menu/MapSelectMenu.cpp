/*
** MapSelectMenu.c for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/sources/menu/MapSelectMenu.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jun 17 23:01:46 2017 Anas Buyumad
** Last update Sun Jun 18 15:36:58 2017 Sylvain Chaugny
*/

#include <functional>
#include <menu/MenuButton.hpp>
#include "Engine.hpp"
#include "menu/MapSelectMenu.hpp"

indie::MapSelectMenu::MapSelectMenu(indie::Menu &menu) :_menu(menu), _maps(_menu.getMaps()) {
  this->_events.push_back({{irr::KEY_ESCAPE, PRESSED}, std::bind(&indie::MapSelectMenu::changeToPlayerSelect, this)});
  this->_events.push_back({{irr::KEY_LEFT, PRESSED}, std::bind(&indie::MapSelectMenu::jumpNext, this)});
  this->_events.push_back({{irr::KEY_RIGHT, PRESSED}, std::bind(&indie::MapSelectMenu::jumpPrev, this)});
  this->_events.push_back({{irr::KEY_RETURN, PRESSED}, std::bind(&indie::MapSelectMenu::changeToGame, this)});

  _mapConfigs.push_back(std::make_unique<MapConfig>(Engine::get().getRessourceManager().getTexture("MapSelectRandomInfo"), Engine::get().getRessourceManager().getTexture("MapSelectRandomDisplay"), MapConfig::MapType::RANDOM, _maps.end()));

  for (auto map = _maps.begin() ; map != _maps.end() ; ++map) {

    auto info = Engine::get().getWindowManager().getDevice().getVideoDriver()->getTexture(map->second.infos.mapName);
    auto display = Engine::get().getWindowManager().getDevice().getVideoDriver()->getTexture(map->second.infos.mapDisplay);

    if (info == nullptr || display == nullptr) {
      throw IrrlichtError("Couldn't load map info/display");
    }
    _mapConfigs.push_back(std::make_unique<MapConfig>(info, display, MapConfig::MapType::LOADED, map));
  }

  _currentMap = _mapConfigs.begin();
}

indie::MapSelectMenu::~MapSelectMenu() {

}

void
indie::MapSelectMenu::receiveEvent(const indie::EventManager &eventManager) {
  for (auto event : this->_events) {
    switch (event.first.second)
    {
      case PRESSED:
	if (eventManager.isKeyPressed(event.first.first))
	  event.second();
	break;
      case DOWN:
	if (eventManager.isKeyDown(event.first.first))
	  event.second();
	break;
      case UP:
	if (eventManager.isKeyUp(event.first.first))
	  event.second();
	break;
      case RELEASED:
	if (eventManager.isKeyReleased(event.first.first))
	  event.second();
	break;
    }
  }
}

void indie::MapSelectMenu::buildElements(void) {
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("MainMenuWallpaper"), {0,0});
  _currentMap->get()->drawElements();

}

void indie::MapSelectMenu::render(void) {
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->drawAll();
}

void indie::MapSelectMenu::changeToPlayerSelect(void) const {
  Engine::get().getSoundManager().playSound("Reset");
  _menu.changeCurrentMenu(Menu::PLAYER_SELECT);
}

void indie::MapSelectMenu::changeToGame(void) const {
  Engine::get().getSoundManager().playSound("Confirm");
  if (_currentMap->get()->getType() == MapConfig::LOADED)
  {
    _menu.changeToGame(_currentMap->get()->getMap()->second);
  }
  else
  {
    _menu.changeToGame();
  }
}

void indie::MapSelectMenu::jumpPrev(void) {
  Engine::get().getSoundManager().playSound("Select");

  if (_currentMap == _mapConfigs.begin())
    _currentMap = std::prev(_mapConfigs.end());
  else
    _currentMap = std::prev(_currentMap);

  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->clear();
  this->buildElements();
}

void indie::MapSelectMenu::jumpNext(void) {
  Engine::get().getSoundManager().playSound("Select");

  _currentMap = std::next(_currentMap);
  if (_currentMap == _mapConfigs.end()) {
    _currentMap = _mapConfigs.begin();
  }

  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->clear();
  this->buildElements();
}

const std::vector<indie::Game::PlayerInfo> &
indie::MapSelectMenu::getPlayerConfig() {
  return playerInfo;
}

indie::MapSelectMenu::MapConfig::MapConfig(irr::video::ITexture *info,
					   irr::video::ITexture *display,
					   MapType type,
					   const std::vector<std::pair<irr::io::path, MapAttributes>>::const_iterator map) :
  _info(info),
  _display(display),
  _type(type),
  _map(map) {

}

indie::MapSelectMenu::MapConfig::~MapConfig() {

}

void indie::MapSelectMenu::MapConfig::drawElements(void) const {
  if (_info)
    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(_info, {MenuButton::XLeftCenter - static_cast<int>(_info->getSize().Width) / 2, MenuButton::YCenter - static_cast<int>(_info->getSize().Height) / 2});
  if (_display)
    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(_display, {MenuButton::XRightCenter - static_cast<int>(_display->getSize().Width) / 2, MenuButton::YCenter - static_cast<int>(_display->getSize().Height) / 2});
}

indie::MapSelectMenu::MapConfig::MapType
indie::MapSelectMenu::MapConfig::getType(void) const {
  return _type;
}

const std::vector<std::pair<irr::io::path, indie::MapAttributes>>::const_iterator indie::MapSelectMenu::MapConfig::getMap(void) const {
  return _map;
}
