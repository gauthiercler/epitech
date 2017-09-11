/*
** Core.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/Core.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:48:44 2017 Anthony LECLERC
** Last update jeu. mai 04 15:48:44 2017 Anthony LECLERC
*/

#include <iostream>
#include "state/core/ACoreState.hpp"
#include "Engine.hpp"

indie::MenuCoreState* indie::Core::MenuState(nullptr);
indie::GameCoreState* indie::Core::GameState(nullptr);
indie::PauseCoreState* indie::Core::PauseState(nullptr);

indie::Core::Core() : _wrapper(Engine::get()),
                      _state(nullptr)
{
  _wrapper.getWindowManager().getDevice().setEventReceiver(&_wrapper.getEventManager());
  _wrapper.getEventManager().setNewSceneManager(_wrapper.getSceneManager());
  _filesManager.load("maps.json");
  auto first = _filesManager.getFiles().begin();
  if (first != _filesManager.getFiles().end())
  {
    std::cout << "From file: " << first->first.c_str() << std::endl;
  }
  if (Core::MenuState == nullptr)
    Core::MenuState = new MenuCoreState(*this);
  if (Core::GameState == nullptr)
    Core::GameState = new GameCoreState(*this);
  if (Core::PauseState == nullptr)
    Core::PauseState = new PauseCoreState(*this);
  _state = Core::MenuState;
}

indie::Core::~Core() {
  delete MenuState;
  delete GameState;
  delete PauseState;
  MenuState = nullptr;
  GameState = nullptr;
  PauseState = nullptr;
}

void indie::Core::run() {

  _splashScreen.render();

  _state->entry(*this);

  while (this->_wrapper.isRunning())
  {
    this->_wrapper.getEventManager().startProcess();
    this->_wrapper.getEventManager().execute();
    this->_state->update(*this);
    this->_wrapper.getEventManager().endProcess();
  }
  _state->quit(*this);
}

bool indie::Core::clear() {
  this->_wrapper.getWindowManager().getDevice().getGUIEnvironment()->clear();
  return false;
}

void indie::Core::close() {
  this->_wrapper.getWindowManager().getDevice().closeDevice();
}

void indie::Core::changeToGame(MapAttributes const &map, const std::vector<indie::Game::PlayerInfo> &playerInfos ) {


  _map = map;
  _playersInfo = playerInfos;
  _mapLoaded = true;
  changeState(Core::GameState);
}

void indie::Core::changeToGame(const std::vector<indie::Game::PlayerInfo> &playerInfos) {
  _playersInfo = playerInfos;
  _mapLoaded = false;
  changeState(Core::GameState);
}

void indie::Core::changeToMenu() {
  changeState(Core::MenuState);
}

void indie::Core::changeState(indie::ICoreState *nextState) {
  if (nextState != this->_state)
  {
    _state->quit(*this);
    Engine::get().getEventManager().endProcess();
    nextState->entry(*this);
    this->_state = nextState;
  }
}

const std::vector<std::pair<irr::io::path, indie::MapAttributes>> &
indie::Core::getMaps() const {
  return _filesManager.getFiles();
}

void indie::Core::changeToPause() {
  changeState(Core::PauseState);
}

bool indie::Core::isMapLoaded(void) const {
  return _mapLoaded;
}

const indie::MapAttributes &indie::Core::getMap() const {
  return _map;
}

std::vector<indie::Game::PlayerInfo> const &
indie::Core::getPlayersInfo(void) const {
  return _playersInfo;
}
