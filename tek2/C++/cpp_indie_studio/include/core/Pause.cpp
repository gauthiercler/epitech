/*
** Pause.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/Pause.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juin 18 01:03:56 2017 Anthony LECLERC
** Last update dim. juin 18 01:03:56 2017 Anthony LECLERC
*/

#include "Engine.hpp"
#include "Pause.hpp"
#include "Core.hpp"
#include "maps/MapSaver.hpp"
#include "state/core/ACoreState.hpp"

void indie::Pause::receiveEvent(const indie::EventManager &eventManager) {
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

bool indie::Pause::render() {
  for (auto button = _buttons.begin() ; button != _buttons.end() ; ++button) {
    button->first.get()->draw();
  }
  return false;
}

bool indie::Pause::clear() {
  return false;
}

bool indie::Pause::update() {
  return false;
}

void indie::Pause::setActive(bool) {
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->clear();
  Engine::get().getWindowManager().setGUITransparency(0);

  _buttons.clear();

  _buttons.push_back({std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("PauseSaveGameButton"), indie::MenuButton::Position::XCenter, indie::MenuButton::Position::YUpperCenter, "PauseSaveGameButton"), std::bind(&indie::Pause::save, this)});
  _buttons.push_back({std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("PauseResumeButton"), indie::MenuButton::Position::XCenter, indie::MenuButton::Position::YCenter, "PauseResumeButton"), std::bind(&indie::Pause::resume, this)});
  _buttons.push_back({std::make_unique<MenuButton>(Engine::get().getWindowManager().getDevice().getGUIEnvironment(), Engine::get().getRessourceManager().getTexture("PauseQuitButton"), indie::MenuButton::Position::XCenter, indie::MenuButton::Position::YLowerCenter, "PauseQuitButton"), std::bind(&indie::Pause::quit, this)});

  _currentButton = _buttons.begin();
  this->drawSelected(_currentButton->first->getName());
}

indie::Pause::Pause(indie::Core &core) :_core(core), _game(nullptr) {
  _events.push_back({{irr::KEY_UP, PRESSED}, std::bind(&indie::Pause::jumpPrev, this)});
  _events.push_back({{irr::KEY_DOWN, PRESSED}, std::bind(&indie::Pause::jumpNext, this)});
  _events.push_back({{irr::KEY_RETURN, PRESSED}, std::bind(&indie::Pause::select, this)});
}

indie::Pause::~Pause() {

}

void indie::Pause::jumpNext(void) {
  Engine::get().getSoundManager().playSound("Select");
  _currentButton = std::next(_currentButton);
  if (_currentButton == _buttons.end())
    _currentButton = _buttons.begin();
  this->drawSelected(_currentButton->first->getName());
}

void indie::Pause::jumpPrev(void) {
  Engine::get().getSoundManager().playSound("Select");
  if (_currentButton == _buttons.begin())
    _currentButton = std::prev(_buttons.end());
  else
    _currentButton = std::prev(_currentButton);
  this->drawSelected(_currentButton->first->getName());
}

void indie::Pause::select(void) {
  Engine::get().getSoundManager().playSound("Confirm");
  _currentButton->second();
}

void indie::Pause::save(void) {
}

void indie::Pause::resume(void) {
  Core::PauseState->nextState(Core::GameState);
}

void indie::Pause::quit(void) {
  Core::PauseState->nextState(Core::MenuState);
}

void indie::Pause::drawSelected(const std::string &selectedElement) {
  for (auto button = _buttons.begin() ; button != _buttons.end() ; ++button) {
    if (selectedElement == (*button->first).getName()) {
      button->first->setImage(Engine::get().getRessourceManager().getTexture("Selected" + button->first->getName()));
    }
    else {
      button->first->setImage(Engine::get().getRessourceManager().getTexture(button->first->getName()));
    }
  }
}

void indie::Pause::setGame(std::unique_ptr<indie::Game> *game) {
  _game = game;
}
