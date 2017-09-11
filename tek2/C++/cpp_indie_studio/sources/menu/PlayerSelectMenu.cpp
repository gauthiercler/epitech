/*
** PlayerSelectMenu.cpp for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/sources/menu/PlayerSelectMenu.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Jun 13 21:28:44 2017 Anas Buyumad
** Last update Sat Jun 17 17:29:35 2017 Sylvain Chaugny
*/

#include <iostream>
#include <game/Game.hpp>
#include "Engine.hpp"
#include "menu/PlayerSelectMenu.hpp"

indie::PlayerSelectMenu::PlayerSelectMenu(indie::Menu &menu) :
  _menu(menu),
  _smgr(Engine::get().getSceneManager()->createNewSceneManager()),
  _camera(_smgr->addCameraSceneNode()) {

  this->_events.push_back({{irr::KEY_ESCAPE, PRESSED}, std::bind(&indie::PlayerSelectMenu::changeToMainMenu, this)});
  this->_events.push_back({{irr::KEY_UP, PRESSED}, std::bind(&indie::PlayerSelectMenu::jumpNext, this)});
  this->_events.push_back({{irr::KEY_DOWN, PRESSED}, std::bind(&indie::PlayerSelectMenu::jumpPrev, this)});
  this->_events.push_back({{irr::KEY_LEFT, PRESSED}, std::bind(&indie::PlayerSelectMenu::changeType, this, irr::KEY_LEFT)});
  this->_events.push_back({{irr::KEY_RIGHT, PRESSED}, std::bind(&indie::PlayerSelectMenu::changeType, this, irr::KEY_RIGHT)});
  this->_events.push_back({{irr::KEY_RETURN, PRESSED}, std::bind(&indie::PlayerSelectMenu::changeToMapSelect, this)});

  _players.push_back(std::make_unique<PlayerConfig>(_smgr->addAnimatedMeshSceneNode(Engine::get().getRessourceManager().getAnimatedMesh("bomberman_stand")), "bomberman_black", playerType::PLAYER_ONE, irr::core::vector3df(75.0f * -4.70f, 0, 0), irr::core::vector2df(MenuButton::Position::XCenter - MenuButton::Size::XEighthScreen * 3, MenuButton::Position::YCenter), irr::core::vector3df(0.0f, -20.0f, 0.0f)));
  _players.push_back(std::make_unique<PlayerConfig>(_smgr->addAnimatedMeshSceneNode(Engine::get().getRessourceManager().getAnimatedMesh("bomberman_stand")), "bomberman_pink", playerType::PLAYER_TWO, irr::core::vector3df(75.0f * -1.55f, 0, 0), irr::core::vector2df(MenuButton::Position::XCenter - MenuButton::Size::XEighthScreen, MenuButton::Position::YCenter), irr::core::vector3df(0.0f, 0.0f, 0.0f)));
  _players.push_back(std::make_unique<PlayerConfig>(_smgr->addAnimatedMeshSceneNode(Engine::get().getRessourceManager().getAnimatedMesh("bomberman_stand")), "bomberman_orange", playerType::AI, irr::core::vector3df(75.0f * 1.55f, 0, 0), irr::core::vector2df(MenuButton::Position::XCenter + MenuButton::Size::XEighthScreen, MenuButton::Position::YCenter), irr::core::vector3df(0.0f, 0.0f, 0.0f)));
  _players.push_back(std::make_unique<PlayerConfig>(_smgr->addAnimatedMeshSceneNode(Engine::get().getRessourceManager().getAnimatedMesh("bomberman_stand")), "bomberman_purple", playerType::AI, irr::core::vector3df(75.0f * 4.70f, 0, 0), irr::core::vector2df(MenuButton::Position::XCenter + MenuButton::Size::XEighthScreen * 3, MenuButton::Position::YCenter), irr::core::vector3df(0.0f, 20.0f, 0.0f)));

  _currentPlayer = _players.begin();

  _playerTypes.push_back({{playerType::NONE, "PlayerSelectNoneButton"}, false});
  _playerTypes.push_back({{playerType::PLAYER_ONE, "PlayerSelectPlayerOneButton"}, true});
  _playerTypes.push_back({{playerType::PLAYER_TWO, "PlayerSelectPlayerTwoButton"}, true});
  _playerTypes.push_back({{playerType::PLAYER_THREE, "PlayerSelectPlayerThreeButton"}, false});
  _playerTypes.push_back({{playerType::PLAYER_FOUR, "PlayerSelectPlayerFourButton"}, false});
  _playerTypes.push_back({{playerType::AI, "PlayerSelectAIButton"}, false});

  _camera->setTarget({0, 0, 0});
  _camera->setPosition({0, 100, -350});
}

indie::PlayerSelectMenu::~PlayerSelectMenu() {

}

void
indie::PlayerSelectMenu::receiveEvent(const indie::EventManager &eventManager) {
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

void indie::PlayerSelectMenu::buildElements(void) {
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("MainMenuWallpaper"), {0,0});

  for (auto player = _players.begin() ; player != _players.end() ; player++) {
    (*player)->buildArrows();
    (*player)->buildType(getTypeTexture((*player)->getType()));
    (*player)->showArrows(false);
  }

  (*_currentPlayer)->showArrows(true);
}

void indie::PlayerSelectMenu::render(void) {
  (*_currentPlayer)->rotate(1.0f);

  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->drawAll();
  this->_smgr->drawAll();
}

void indie::PlayerSelectMenu::changeToMainMenu(void) const {
  Engine::get().getSoundManager().playSound("Reset");
  _menu.changeCurrentMenu(Menu::MAIN);
}

void indie::PlayerSelectMenu::jumpPrev(void) {
  Engine::get().getSoundManager().playSound("Select");
  (*_currentPlayer)->showArrows(false);
  (*_currentPlayer)->resetRotation();
  if (_currentPlayer == _players.begin())
    _currentPlayer = std::prev(_players.end());
  else
    _currentPlayer = std::prev(_currentPlayer);
  (*_currentPlayer)->showArrows(true);
}

void indie::PlayerSelectMenu::jumpNext(void) {
  Engine::get().getSoundManager().playSound("Select");
  (*_currentPlayer)->showArrows(false);
  (*_currentPlayer)->resetRotation();
  _currentPlayer = std::next(_currentPlayer);
  if (_currentPlayer == _players.end()) {
    _currentPlayer = _players.begin();
  }
  (*_currentPlayer)->showArrows(true);
}

irr::video::ITexture *indie::PlayerSelectMenu::getTypeTexture(
  indie::PlayerSelectMenu::playerType type) {
  for (auto playerType : _playerTypes) {
    if (playerType.first.first == type) {
      return Engine::get().getRessourceManager().getTexture(playerType.first.second);
    }
  }
  return nullptr;
}

void indie::PlayerSelectMenu::changeType(irr::EKEY_CODE key) {
  Engine::get().getSoundManager().playSound("Select");
  auto currentType = getTypeIterator((*_currentPlayer)->getType());

  if (currentType == _playerTypes.end()) {
    throw IrrlichtError("Couldn't find current type.");
  }

  if (currentType->first.first == PLAYER_ONE || currentType->first.first == PLAYER_TWO || currentType->first.first == PLAYER_THREE || currentType->first.first == PLAYER_FOUR) {
    currentType->second = false;
  }

  if (key == irr::KEY_LEFT) {
    if (currentType == _playerTypes.begin())
      currentType = std::prev(_playerTypes.end());
    else
      currentType = std::prev(currentType);
  }
  else if (key == irr::KEY_RIGHT) {
    currentType = std::next(currentType);
    if (currentType == _playerTypes.end()) {
      currentType = _playerTypes.begin();
    }
  }

  while (currentType->second) {
    if (key == irr::KEY_LEFT) {
      if (currentType == _playerTypes.begin())
	currentType == std::prev(_playerTypes.end());
      else
	currentType = std::prev(currentType);
    }
    else if (key == irr::KEY_RIGHT) {
      currentType = std::next(currentType);
      if (currentType == _playerTypes.end()) {
	currentType = _playerTypes.begin();
      }
    }
  }
  if (currentType->first.first == PLAYER_ONE || currentType->first.first == PLAYER_TWO  || currentType->first.first == PLAYER_THREE || currentType->first.first == PLAYER_FOUR) {
    currentType->second = true;
  }

  (*_currentPlayer)->changeType(currentType->first.first, getTypeTexture(currentType->first.first));
}

void indie::PlayerSelectMenu::setTypeState(playerType type, bool state) {
  for (auto playerType : _playerTypes) {
    if (playerType.first.first == type) {
      playerType.second = state;
    }
  }
}

std::vector<std::pair<std::pair<indie::PlayerSelectMenu::playerType, std::string>, bool>>::iterator
indie::PlayerSelectMenu::getTypeIterator(
  indie::PlayerSelectMenu::playerType type) {
  for (auto playerType = _playerTypes.begin() ; playerType != _playerTypes.end() ; playerType++) {
    if (playerType->first.first == type) {
      return playerType;
    }
  }
  return _playerTypes.end();
}

void indie::PlayerSelectMenu::changeToMapSelect(void) {
  Engine::get().getSoundManager().playSound("Confirm");
  playersInfo.clear();
  for (auto &player : _players) {
    if (player->getType() == PlayerSelectMenu::playerType::AI) {

      playersInfo.push_back({player->getTexture(), indie::Game::PlayerMode::AI});
    }
    else if (player->getType() != PlayerSelectMenu::playerType::NONE) {
      playersInfo.push_back({player->getTexture(), indie::Game::PlayerMode::HUMAN});
    }
  }
  _menu.changeCurrentMenu(Menu::MAP_SELECT);
}

const std::vector<std::unique_ptr<indie::PlayerSelectMenu::PlayerConfig>> &
indie::PlayerSelectMenu::getPlayersConfig(void) const {
  return _players;
}

const std::vector<indie::Game::PlayerInfo> &
indie::PlayerSelectMenu::getPlayerConfig() {
  return playersInfo;
}

indie::PlayerSelectMenu::PlayerConfig::PlayerConfig(
  irr::scene::IAnimatedMeshSceneNode *node, const std::string &skinID,
  indie::PlayerSelectMenu::playerType type, const irr::core::vector3df &pos, const irr::core::vector2df &centerPos, const irr::core::vector3df &rotation) :
  _node(node),
  _skin(skinID),
  _type(type),
  _centerPos(centerPos),
  _rotationBase(rotation),
  _rotation(_rotationBase) {
  _node->setMaterialTexture(0, Engine::get().getRessourceManager().getTexture(skinID));
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  _node->setScale({75.0f, 75.0f, 75.0f});
  _node->setRotation(_rotationBase);
  _node->setPosition(pos);
  _node->setVisible(true);
}

indie::PlayerSelectMenu::PlayerConfig::~PlayerConfig() {

}


void indie::PlayerSelectMenu::PlayerConfig::buildArrows() {
  _arrowsButton = {std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("OptionsLeftArrowButton"), getCenterPos().X - MenuButton::Size::XSixteenthScreen, getCenterPos().Y, "LeftArrow"),
		   std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("OptionsRightArrowButton"), getCenterPos().X + MenuButton::Size::XSixteenthScreen, getCenterPos().Y, "RightArrow")};
}

void indie::PlayerSelectMenu::PlayerConfig::showArrows(bool state) {
  this->_arrowsButton.first->setVisible(state);
  this->_arrowsButton.second->setVisible(state);
}

irr::core::vector2df indie::PlayerSelectMenu::PlayerConfig::getCenterPos(void) const {
  return _centerPos;
}

void indie::PlayerSelectMenu::PlayerConfig::buildType(irr::video::ITexture *typeTexture) {
  _typeButton = std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), typeTexture, getCenterPos().X, getCenterPos().Y + MenuButton::Size::YFourthScreen, "TypeButton");
}

indie::PlayerSelectMenu::playerType
indie::PlayerSelectMenu::PlayerConfig::getType(void) const {
  return _type;
}

void indie::PlayerSelectMenu::PlayerConfig::changeType(
  indie::PlayerSelectMenu::playerType type, irr::video::ITexture *typeTexture) {
  _type = type;
  _typeButton->setImage(typeTexture);
}

void indie::PlayerSelectMenu::PlayerConfig::rotate(irr::f32 Yangle) {
  _rotation.Y += Yangle;
  if (_rotation.Y > 360.0f) {
    _rotation.Y = 0.0f;
  }
  _node->setRotation(_rotation);
}

void
indie::PlayerSelectMenu::PlayerConfig::setRotation(irr::core::vector3df angle) {
  _rotation = angle;
  _node->setRotation(_rotation);
}

void indie::PlayerSelectMenu::PlayerConfig::resetRotation(void) {
  _rotation = _rotationBase;
  _node->setRotation(_rotation);
}

const std::string &
indie::PlayerSelectMenu::PlayerConfig::getTexture(void) const {
  return _skin;
}
