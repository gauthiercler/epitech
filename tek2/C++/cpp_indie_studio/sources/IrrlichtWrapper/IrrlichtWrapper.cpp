/*
** IrrlichtWrapper.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/IrrlichtWrapper.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 14:53:32 2017 Anthony LECLERC
** Last update jeu. mai 04 14:53:32 2017 Anthony LECLERC
*/

#include "IrrlichtWrapper.hpp"

indie::IrrlichtWrapper::IrrlichtWrapper() :
    _windowManager(SCREEN_WIDTH, SCREEN_HEIGHT, L"Indie Studio", false)
    , _sceneManager(_windowManager.getDevice().getSceneManager())
    , _ressourceManager(_sceneManager.get(), _windowManager.getDevice())
{
  this->getWindowManager().getDevice().getVideoDriver()->enableMaterial2D();
  this->getWindowManager().getDevice().setEventReceiver(&_eventManager);
}

indie::IrrlichtWrapper::~IrrlichtWrapper() {
}

indie::RessourceManager &indie::IrrlichtWrapper::getRessourceManager() {
  return this->_ressourceManager;
}

irr::scene::ISceneManager *indie::IrrlichtWrapper::getSceneManager() {
  return this->_sceneManager.get();
}

indie::WindowManager &indie::IrrlichtWrapper::getWindowManager() {
  return this->_windowManager;
}

indie::SoundManager &indie::IrrlichtWrapper::getSoundManager() {
  return this->_soundManager;
}

indie::ScriptManager &indie::IrrlichtWrapper::getScriptManager() {
  return this->_scriptManager;
}

indie::EventManager &indie::IrrlichtWrapper::getEventManager() {
  return this->_eventManager;
}

bool indie::IrrlichtWrapper::isRunning() {
  return this->_windowManager.run();
}