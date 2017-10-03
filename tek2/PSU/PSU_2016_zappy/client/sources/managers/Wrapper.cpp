/*
** SfmlWrapper.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/managers/SfmlWrapper.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 11:35:56 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 11:35:56 2017 Vincent DUSAUTOIR
*/

#include "managers/Wrapper.hpp"

zappy::Wrapper::Wrapper() {

}

zappy::Wrapper::~Wrapper() {

}

zappy::WindowManager &zappy::Wrapper::getWindowManager() {
  return this->_windowManager;
}

zappy::EventManager &zappy::Wrapper::getEventManager() {
  return this->_eventManager;
}

zappy::RessourcesManager &zappy::Wrapper::getRessourcesManager() {
  return this->_ressourcesManager;
}

const zappy::Size &zappy::Wrapper::getWindowSize() const {
  return this->_windowManager.getSize();
}

zappy::Socket &zappy::Wrapper::getSocket() {
  return this->_socket;
}

zappy::SoundManager &zappy::Wrapper::getSoundManager() {
  return this->_soundManager;
}

