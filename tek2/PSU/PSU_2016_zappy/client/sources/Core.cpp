/*
** Core.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/Core.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 11:03:12 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 11:03:12 2017 Vincent DUSAUTOIR
*/

#include <utils/Position.hpp>
#include <iostream>
#include <utils/Utils.hpp>
#include "managers/Engine.hpp"
#include "Core.hpp"

zappy::Core::Core() : _wrapper(Engine::get()), _menu(*this), _game(*this), _coreState(zappy::CoreState::MENU) {

}

zappy::Core::~Core() {

}

void zappy::Core::run() {
  while (this->_wrapper.getWindowManager().isOpen()){
    this->update();
    this->render();
  }
}

void zappy::Core::update() {
  this->handleSocket(Engine::get().getSocket());
  if (this->_coreState == CoreState::GAME)
    this->_game.update();
  while (this->_wrapper.getEventManager().update())
  {
    if (this->_wrapper.getEventManager().isClosed())
      this->close();
    if (this->_coreState == CoreState::MENU)
      this->_menu.update(this->_wrapper.getEventManager());
    else if (this->_coreState == CoreState::GAME)
      this->_game.update(this->_wrapper.getEventManager());
  }
}

void zappy::Core::render() {
  if (this->_coreState == CoreState::MENU)
    this->_menu.render();
  else if (this->_coreState == CoreState::GAME)
    this->_game.render();
  this->_wrapper.getWindowManager().display();
}

void zappy::Core::close() {
  this->_wrapper.getWindowManager().close();
}

void zappy::Core::setCoreState(zappy::CoreState state) {
  this->_coreState = state;
}

void zappy::Core::handleSocket(zappy::Socket &socket) {
  if (socket.isConnected())
    this->_buffer.add(socket.receive(4096, false));

  auto line = this->_buffer.getLine();
  while (line.size() > 0)
  {
    this->_parser.reset();
    this->_parser.parse(line);
    if (this->_coreState == CoreState::GAME && this->_parser.getType() != ParseType::UNKNOWN)
    {
      if (this->_parser.getType() == ParseType::END_OF_THEGAME)
      {
	this->_game.disconnect();
	this->_menu.setWinner(this->_parser[1]);
      } else
	this->_game.update(this->_parser);
    }
    line = this->_buffer.getLine();
  }
}
