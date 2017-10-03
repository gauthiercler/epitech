/*
** EventManager.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/managers/EventManager.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 11:13:33 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 11:13:33 2017 Vincent DUSAUTOIR
*/

#include	<iostream>
#include	"managers/Engine.hpp"
#include	"utils/Position.hpp"
#include	"managers/EventManager.hpp"

zappy::EventManager::EventManager() {

}

zappy::EventManager::~EventManager() {

}

bool zappy::EventManager::update() {
  return (Engine::get().getWindowManager().getWindow().pollEvent(this->_event));
}

bool zappy::EventManager::isClosed() {
  return (this->_event.type == sf::Event::Closed);
}

bool zappy::EventManager::isKeyPressed() {
  return (this->_event.type == sf::Event::KeyPressed);
}

bool zappy::EventManager::isKeyReleased() {
  return (this->_event.type == sf::Event::KeyReleased);
}

bool zappy::EventManager::isTextEntered() {
  return (this->_event.type == sf::Event::TextEntered);
}

bool zappy::EventManager::isButtonPressed() {
  return (this->_event.type == sf::Event::MouseButtonPressed);
}

bool zappy::EventManager::isButtonReleased() {
  return (this->_event.type == sf::Event::MouseButtonReleased);
}

zappy::Position zappy::EventManager::getMousePositionPressed() {
  return Position(this->_event.mouseButton.x, this->_event.mouseButton.y);
}

zappy::Position zappy::EventManager::getMousePosition() {
  return Position(this->_event.mouseMove.x, this->_event.mouseMove.y);
}

bool zappy::EventManager::isMouseMoving() {
  return (this->_event.type == sf::Event::MouseMoved);
}

sf::Event::KeyEvent &zappy::EventManager::getKey() {
  return this->_event.key;
}

sf::Event::EventType zappy::EventManager::getType() {
  return this->_event.type;
}

bool zappy::EventManager::isMouseEvent() {
  return (this->isMouseMoving() || this->isButtonPressed() || this->isButtonReleased());
}

bool zappy::EventManager::isKeyboardEvent() {
  return (this->isKeyPressed() || this->isKeyReleased() || this->isTextEntered());
}

bool
zappy::EventManager::isButtonPressed(const Position &pos, const Size &size) {
  if (this->isButtonPressed()) {
    return (this->_event.mouseButton.x >= pos.x &&
	    this->_event.mouseButton.x <= pos.x + size.width &&
	    this->_event.mouseButton.y >= pos.y &&
	    this->_event.mouseButton.y <= pos.y + size.length);
  }
  return false;
}

bool
zappy::EventManager::isButtonReleased(const Position &pos, const Size &size) {
  if (this->isButtonReleased()) {
    return (this->_event.mouseButton.x >= pos.x &&
	    this->_event.mouseButton.x <= pos.x + size.width &&
	    this->_event.mouseButton.y >= pos.y &&
	    this->_event.mouseButton.y <= pos.y + size.length);
  }
  return false;
}

bool zappy::EventManager::isMouseMoving(const Position &pos, const Size &size) {
  if (this->isMouseMoving()) {
    return (this->_event.mouseMove.x >= pos.x &&
	    this->_event.mouseMove.x <= pos.x + size.width &&
	    this->_event.mouseMove.y >= pos.y &&
	    this->_event.mouseMove.y <= pos.y + size.length);
  }
  return false;
}

char zappy::EventManager::getTextEntered() {
  return static_cast<char>(this->_event.text.unicode);
}

bool zappy::EventManager::isKeyboardEvent(sf::Event::EventType type,
					  sf::Keyboard::Key keyboard) {
  return (this->_event.type == type && this->_event.key.code == keyboard);
}

bool zappy::EventManager::isMouseEvent(sf::Event::EventType type) {
  return (this->_event.type == type);
}
