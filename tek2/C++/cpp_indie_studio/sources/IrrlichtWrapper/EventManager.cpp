/*
** EventManager.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/EventManager.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:08:04 2017 Anthony LECLERC
** Last update jeu. mai 04 15:08:04 2017 Anthony LECLERC
*/

#include <Engine.hpp>
#include <iostream>
#include "managers/EventManager.hpp"
#include "controllers/EntityController.hpp"

indie::EventManager::EventManager() :
_processState(ENDED),
_smgr(nullptr),
_lastGUI(nullptr)
{
  for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
    this->_keyState[i] = UP;
}

indie::EventManager::~EventManager() {

}

bool indie::EventManager::OnEvent(const irr::SEvent &event) {
 bool eventprocessed = false;

  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
  {
    if (this->_processState == STARTED)
    {
      if (event.KeyInput.PressedDown)
      {
	if (this->_keyState[event.KeyInput.Key] != DOWN)
	  this->_keyState[event.KeyInput.Key] = PRESSED;
	else
	  this->_keyState[event.KeyInput.Key] = DOWN;
      }
      else
      {
	if (this->_keyState[event.KeyInput.Key] != UP)
	  this->_keyState[event.KeyInput.Key] = RELEASED;
      }
    }
    eventprocessed = true;
  }
  if (_smgr != Engine::get().getSceneManager())
    return _smgr->postEventFromUser(event);
  return eventprocessed;
}

bool indie::EventManager::isKeyDown(irr::EKEY_CODE keyCode) const {
  return (this->_keyState[keyCode] == DOWN || this->_keyState[keyCode] == PRESSED);
}

bool indie::EventManager::isKeyPressed(irr::EKEY_CODE keyCode) const {
  return (this->_keyState[keyCode] == PRESSED);
}

bool indie::EventManager::isKeyUp(irr::EKEY_CODE keyCode) const {
  return (this->_keyState[keyCode] == UP || this->_keyState[keyCode] == RELEASED);
}

bool indie::EventManager::isKeyReleased(irr::EKEY_CODE keyCode) const {
  return (this->_keyState[keyCode] == RELEASED);
}

void indie::EventManager::endProcess() {
  this->_processState = STARTED;
  for (int i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
  {
    if (this->_keyState[i] == RELEASED)
      this->_keyState[i] = UP;
    if (this->_keyState[i] == PRESSED)
      this->_keyState[i] = DOWN;
  }
}

void indie::EventManager::startProcess() {
  this->_processState = ENDED;
}

void indie::EventManager::execute()
{
  for (auto &&obj : _controllers)
  {
    if (obj->isActive())
      obj->execute(*this);
  }
}

void indie::EventManager::setNewSceneManager(irr::scene::ISceneManager *smgr)
{
  _smgr = smgr;
}

irr::gui::IGUIElement const *indie::EventManager::lastGUIEvent() const {
  return _lastGUI;
}
