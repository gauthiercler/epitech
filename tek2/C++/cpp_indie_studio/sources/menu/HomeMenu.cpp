/*
** HomeMenu.cpp for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/sources/menu/HomeMenu.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri May 26 16:13:11 2017 Anas Buyumad
** Last update Sat Jun 17 17:06:17 2017 Sylvain Chaugny
*/

#include	<iostream>
#include	"Engine.hpp"
#include	"menu/HomeMenu.hpp"

indie::HomeMenu::HomeMenu(indie::Menu &menu) : _menu(menu) {
  _events.push_back({{irr::KEY_ESCAPE, PRESSED}, std::bind(&indie::Menu::close, &this->_menu)});
  _events.push_back({{irr::KEY_UP, PRESSED}, std::bind(&indie::HomeMenu::jumpPrev, this)});
  _events.push_back({{irr::KEY_DOWN, PRESSED}, std::bind(&indie::HomeMenu::jumpNext, this)});
  _events.push_back({{irr::KEY_RETURN, PRESSED}, std::bind(&indie::HomeMenu::select, this)});
}

indie::HomeMenu::~HomeMenu() {

}

void indie::HomeMenu::receiveEvent(const indie::EventManager &eventManager) {
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

void indie::HomeMenu::render(void) {
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->drawAll();
}

void indie::HomeMenu::buildElements(void) {
  _buttons.clear();

  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("MainMenuWallpaper"), {0,0});

  _buttons.push_back({std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("MainMenuNewGameButton"), indie::MenuButton::Position::XCenter, indie::MenuButton::Position::YCenter - indie::MenuButton::Size::YFourthScreen - indie::MenuButton::Size::YSixteenthScreen, "MainMenuNewGameButton"), std::bind(&indie::HomeMenu::changeToPlayerSelect, this)});

  if (_menu.hasSave())
    _buttons.push_back({std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("MainMenuResumeButton"), indie::MenuButton::Position::XCenter, indie::MenuButton::Position::YCenter - indie::MenuButton::Size::YEighthScreen , "MainMenuResumeButton"), std::bind(&indie::HomeMenu::resumeGame, this)});
  else
    _buttons.push_back({std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("DisabledMainMenuResumeButton"), indie::MenuButton::Position::XCenter, indie::MenuButton::Position::YCenter - indie::MenuButton::Size::YEighthScreen , "DisabledMainMenuResumeButton"), std::bind(&indie::HomeMenu::resumeGame, this)});
  _buttons.push_back({std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("MainMenuOptionsButton"), indie::MenuButton::Position::XCenter, indie::MenuButton::Position::YCenter + indie::MenuButton::Size::YEighthScreen, "MainMenuOptionsButton"), std::bind(&indie::HomeMenu::changeToOptions, this)});

  _buttons.push_back({std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("MainMenuHighscoresButton"), indie::MenuButton::Position::XCenter, indie::MenuButton::Position::YCenter + indie::MenuButton::Size::YFourthScreen + indie::MenuButton::Size::YSixteenthScreen, "MainMenuHighscoresButton"), std::bind(&indie::HomeMenu::changeToHighscores, this)});

  _currentButton = this->findButton("MainMenuNewGameButton");
  if (_currentButton == _buttons.end()) {
    throw IrrlichtError("Couldn't find MainMenuNewGameButton");
  }
  this->drawSelected(_currentButton->first->getName());
}


std::vector<std::pair<std::unique_ptr<indie::MenuButton>, std::function<void(
  void)>>>::iterator indie::HomeMenu::findButton(const std::string &name) {
  for (auto button = _buttons.begin() ; button != _buttons.end() ; ++button) {
    if (button->first->getName() == name) {
      return button;
    }
  }
  return _buttons.end();
}

void indie::HomeMenu::jumpNext(void) {
  Engine::get().getSoundManager().playSound("Select");
  _currentButton = std::next(_currentButton);
  if (_currentButton == _buttons.end())
    _currentButton = _buttons.begin();
  if (_currentButton->first->getName() == "DisabledMainMenuResumeButton" && !_menu.hasSave()) {
    jumpNext();
  }
  else {
    this->drawSelected(_currentButton->first->getName());
  }
}

void indie::HomeMenu::jumpPrev(void) {
  Engine::get().getSoundManager().playSound("Select");
  if (_currentButton == _buttons.begin())
    _currentButton = std::prev(_buttons.end());
  else
    _currentButton = std::prev(_currentButton);
  if (_currentButton->first->getName() == "DisabledMainMenuResumeButton" && !_menu.hasSave()) {
    jumpPrev();
  }
  else {
    this->drawSelected(_currentButton->first->getName());
  }
}

void indie::HomeMenu::select(void) {
  Engine::get().getSoundManager().playSound("Confirm");
  _currentButton->second();
}

void indie::HomeMenu::drawSelected(const std::string &selectedElement) {
  for (auto button = _buttons.begin() ; button != _buttons.end() ; ++button) {
    if (selectedElement == (*button->first).getName()) {
      button->first->setImage(Engine::get().getRessourceManager().getTexture("Selected" + button->first->getName()));
    }
    else {
      button->first->setImage(Engine::get().getRessourceManager().getTexture(button->first->getName()));
    }
  }
}

void indie::HomeMenu::resumeGame(void) const {
}

void indie::HomeMenu::changeToPlayerSelect(void) const {
  _menu.changeCurrentMenu(Menu::PLAYER_SELECT);
}

void indie::HomeMenu::changeToOptions(void) const {
  _menu.changeCurrentMenu(indie::Menu::OPTIONS);
}

void indie::HomeMenu::changeToHighscores(void) const {
  _menu.changeCurrentMenu(indie::Menu::HIGHSCORES);
}

const std::vector<indie::Game::PlayerInfo> &indie::HomeMenu::getPlayerConfig() {
  return playerInfo;
}
