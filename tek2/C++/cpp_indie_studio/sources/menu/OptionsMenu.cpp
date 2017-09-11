/*
** OptionsMenu.cpp for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/sources/menu/OptionsMenu.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri May 26 16:13:39 2017 Anas Buyumad
** Last update Sat Jun 17 17:06:43 2017 Sylvain Chaugny
*/

#include <iostream>
#include <functional>
#include "Engine.hpp"
#include "menu/OptionsMenu.hpp"

indie::OptionsMenu::OptionsMenu(indie::Menu &menu) : _menu(menu), _AILevel(AILevel::EASY) {
  this->_events.push_back({{irr::KEY_ESCAPE, PRESSED}, std::bind(&indie::OptionsMenu::changeToMainMenu, this)});
  this->_events.push_back({{irr::KEY_UP, PRESSED}, std::bind(&indie::OptionsMenu::jumpPrev, this)});
  this->_events.push_back({{irr::KEY_DOWN, PRESSED}, std::bind(&indie::OptionsMenu::jumpNext, this)});
  this->_events.push_back({{irr::KEY_LEFT, PRESSED}, std::bind(&indie::OptionsMenu::moveLeft, this)});
  this->_events.push_back({{irr::KEY_RIGHT, PRESSED}, std::bind(&indie::OptionsMenu::moveRight, this)});
}

indie::OptionsMenu::~OptionsMenu() {

}

void indie::OptionsMenu::receiveEvent(const indie::EventManager &eventManager) {
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

void indie::OptionsMenu::render(void) {
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->drawAll();
}

void indie::OptionsMenu::buildElements(void) {
  this->_buttons.clear();
  this->_configButtons.clear();

  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("MainMenuWallpaper"), {0,0});

  function binding = {std::bind(&indie::OptionsMenu::changeSound, this, irr::KEY_LEFT), std::bind(&indie::OptionsMenu::changeSound, this, irr::KEY_RIGHT)};

  this->_buttons.push_back({std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("OptionsSoundButton"), indie::MenuButton::XLeftCenter, indie::MenuButton::YUpperCenter, "OptionsSoundButton"), binding});

  if (Engine::get().getSoundManager().getGlobalVolume()) {
    this->_configButtons.push_back(std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("OptionsONButton"), indie::MenuButton::Position::XRightCenter, indie::MenuButton::Position::YUpperCenter, "SoundStateButton"));
  }
  else
    this->_configButtons.push_back(std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("OptionsOFFButton"), indie::MenuButton::Position::XRightCenter, indie::MenuButton::Position::YUpperCenter, "SoundStateButton"));

  this->_configButtons.push_back(std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("OptionsLeftArrowButton"), indie::MenuButton::Position::XRightCenter - indie::MenuButton::Size::XEighthScreen, indie::MenuButton::Position::YUpperCenter, "SoundLeftArrowButton"));
  this->_configButtons.push_back(std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("OptionsRightArrowButton"), indie::MenuButton::Position::XRightCenter + indie::MenuButton::Size::XEighthScreen, indie::MenuButton::Position::YUpperCenter, "SoundRightArrowButton"));

  this->_buttons.push_back({std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("OptionsAIButton"), indie::MenuButton::XLeftCenter, indie::MenuButton::YCenter, "OptionsAIButton"), {std::bind(&indie::OptionsMenu::changeAILevel, this, irr::KEY_LEFT), std::bind(&indie::OptionsMenu::changeAILevel, this, irr::KEY_RIGHT)}});

  function binding_ai = { std::bind(&indie::OptionsMenu::changeAILevel, this, irr::KEY_LEFT), std::bind(&indie::OptionsMenu::changeAILevel, this, irr::KEY_RIGHT) };
  this->_buttons.push_back({std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("OptionsAIButton"), indie::MenuButton::XLeftCenter, indie::MenuButton::YCenter, "OptionsAIButton"), binding_ai});

  _AIDifficulties.insert({AILevel::EASY, "OptionsEasyButton"});
  _AIDifficulties.insert({AILevel::HARD, "OptionsHardButton"});

  this->_configButtons.push_back(std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture(_AIDifficulties[_AILevel]), indie::MenuButton::Position::XRightCenter, indie::MenuButton::Position::YCenter, "AILevelButton"));

  this->_configButtons.push_back(std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("OptionsLeftArrowButton"), indie::MenuButton::Position::XRightCenter - indie::MenuButton::Size::XEighthScreen, indie::MenuButton::Position::YCenter, "AILeftArrowButton"));
  this->_configButtons.push_back(std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("OptionsRightArrowButton"), indie::MenuButton::Position::XRightCenter + indie::MenuButton::Size::XEighthScreen, indie::MenuButton::Position::YCenter, "AIRightArrowButton"));


  this->_currentButton = this->_buttons.begin();
  this->drawSelected(this->_currentButton->first->getName());
}

void indie::OptionsMenu::jumpNext(void) {
  Engine::get().getSoundManager().playSound("Select");
  this->_currentButton = std::next(this->_currentButton);
  if (this->_currentButton == this->_buttons.end())
    this->_currentButton = this->_buttons.begin();
  this->drawSelected(this->_currentButton->first->getName());
}

void indie::OptionsMenu::jumpPrev(void) {
  Engine::get().getSoundManager().playSound("Select");
  if (this->_currentButton == this->_buttons.begin())
    this->_currentButton = std::prev(this->_buttons.end());
  else
    this->_currentButton = std::prev(this->_currentButton);
  this->drawSelected(this->_currentButton->first->getName());
}

void indie::OptionsMenu::moveLeft(void) {
  Engine::get().getSoundManager().playSound("Select");
  this->_currentButton->second.first(irr::KEY_LEFT);
}

void indie::OptionsMenu::moveRight(void) {
  Engine::get().getSoundManager().playSound("Select");
  this->_currentButton->second.second(irr::KEY_RIGHT);
}

void indie::OptionsMenu::drawSelected(const std::string &selectedElement) {
  for (auto button = this->_buttons.begin() ; button != this->_buttons.end() ; button++) {
    if (selectedElement == button->first->getName()) {
      button->first->setImage(Engine::get().getRessourceManager().getTexture("Selected" + button->first->getName()));
    }
    else {
      button->first->setImage(Engine::get().getRessourceManager().getTexture(button->first->getName()));
    }
  }
}

void indie::OptionsMenu::changeToMainMenu(void) const {
  Engine::get().getSoundManager().playSound("Reset");
  this->_menu.changeCurrentMenu(indie::Menu::MAIN);
}

void indie::OptionsMenu::changeSound(irr::EKEY_CODE) {
  auto SoundStateButton = this->findConfigButton("SoundStateButton");

  if (SoundStateButton == this->_configButtons.end()) {
    throw IrrlichtError("Couldn't find SoundStateButton.");
  }
  Engine::get().getSoundManager().switchGlobalVolume();
  if (Engine::get().getSoundManager().getGlobalVolume()) {
    (*SoundStateButton)->setImage(Engine::get().getRessourceManager().getTexture("OptionsONButton"));
  }
  else {
    (*SoundStateButton)->setImage(Engine::get().getRessourceManager().getTexture("OptionsOFFButton"));
  }
}

void indie::OptionsMenu::changeAILevel(irr::EKEY_CODE key) {
  auto currentLevel = _AIDifficulties.find(_AILevel);
  if (currentLevel == _AIDifficulties.end()) {
    throw IrrlichtError("Couldn't find AI difficulty.");
  }
  if (key == irr::EKEY_CODE::KEY_LEFT) {
    if (currentLevel == _AIDifficulties.begin()) {
      currentLevel = std::prev(_AIDifficulties.end());
    }
    else {
      currentLevel = std::prev(currentLevel);
    }
  }
  else if (key == irr::EKEY_CODE::KEY_RIGHT) {
    currentLevel = std::next(currentLevel);
    if (currentLevel == _AIDifficulties.end()) {
      currentLevel = _AIDifficulties.begin();
    }
  }

  auto levelButton = findConfigButton("AILevelButton");
  if (levelButton == _configButtons.end()) {
    throw IrrlichtError("Couldn't find AILevelButton.");
  }

  _AILevel = currentLevel->first;
  levelButton->get()->setImage(Engine::get().getRessourceManager().getTexture(_AIDifficulties[_AILevel]));
}

std::vector<std::unique_ptr<indie::MenuButton>>::iterator
indie::OptionsMenu::findConfigButton(const std::string &name) {
  for (auto button = this->_configButtons.begin() ; button != this->_configButtons.end() ;  ++button) {
    if ((*button)->getName() == name) {
      return button;
    }
  }
  return this->_configButtons.end();
}

const std::vector<indie::Game::PlayerInfo> &
indie::OptionsMenu::getPlayerConfig() {
  return playerConfig;
}
