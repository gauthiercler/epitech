/*
** ACoreState.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/ACoreState.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 12 19:12:41 2017 Anthony LECLERC
** Last update lun. juin 12 19:12:41 2017 Anthony LECLERC
*/

#include	"Engine.hpp"
#include	"state/core/ACoreState.hpp"

indie::ICoreState *indie::GameCoreState::update(indie::Core &) {
  _controller->receiveEvent(Engine::get().getEventManager());
  Engine::get().getWindowManager().beginScene();
  _controller->update();
  _controller->render();
  Engine::get().getWindowManager().endScene();
  return this;
}

indie::MenuCoreState::MenuCoreState(Core &core)
{
  _controller = std::make_unique<Menu>(core);
}

indie::ICoreState *indie::MenuCoreState::update(indie::Core &) {
  irr::gui::IGUIElement const* el = Engine::get().getEventManager().lastGUIEvent();
  if (el != nullptr && el->getName() == std::string("Battle")) {
    return Core::GameState;
  }
  _controller->receiveEvent(Engine::get().getEventManager());
  Engine::get().getWindowManager().beginScene();
  _controller->render();
  Engine::get().getWindowManager().endScene();
  return this;
}


void indie::MenuCoreState::entry(indie::Core &) {
  Engine::get().getSoundManager().stopSound("SplashSong");
  Engine::get().getSoundManager().stopSound("Battle");
  Engine::get().getSoundManager().stopSound("SpeedBattle");
  Engine::get().getSoundManager().enableSoundLoop("StageSelect");
  Engine::get().getSoundManager().playSound("StageSelect");
  _controller->setActive(true);
  Engine::get().getEventManager().setNewSceneManager(Engine::get().getSceneManager());
}

void indie::MenuCoreState::quit(indie::Core &) {
  _controller->setActive(false);
  _controller->clear();
}

indie::GameCoreState::GameCoreState(indie::Core &core) :
    _callbacks(std::make_shared<ICoreInGameController>(core))
{
  Engine::get().getEventManager().registerController(_callbacks.get());
}

void indie::GameCoreState::entry(indie::Core &core) {
  if (Engine::get().getWindowManager().getDevice().getTimer()->isStopped())
    Engine::get().getWindowManager().getDevice().getTimer()->start();
  _callbacks->setActive(true);
  if (!_controller) {
    if (core.isMapLoaded()) {
      _controller = std::make_unique<Game>(core, core.getMap(), core.getPlayersInfo());
    }
    else {
      _controller = std::make_unique<Game>(core, core.getPlayersInfo());
    }
  }
  _controller->setActive(true);
}

void indie::GameCoreState::quit(indie::Core &) {
  Engine::get().getWindowManager().getDevice().getTimer()->stop();
  Core::PauseState->settingBackgroundGame(&_controller);
  _controller->setActive(false);
  _callbacks->setActive(false);
}

void indie::PauseCoreState::entry(indie::Core &) {
  _nextState = this;
  _callbacks->setActive(true);
  _controller->setActive(true);
}

void indie::PauseCoreState::quit(indie::Core &) {
  if (_nextState == Core::MenuState)
  {
    _handle->reset(nullptr);
    _handle = nullptr;
  }
  _nextState = this;
  _callbacks->setActive(false);
}

indie::ICoreState *indie::PauseCoreState::update(indie::Core& core) {
  _controller->receiveEvent(Engine::get().getEventManager());
  _controller->update();
  Engine::get().getWindowManager().beginScene();
  (*_handle)->render();
  _controller->render();
  Engine::get().getWindowManager().endScene();
  if (_nextState != this)
    core.changeState(_nextState);
  return this;
}

void indie::PauseCoreState::settingBackgroundGame(
    std::unique_ptr<indie::Game> *game)
{
  _handle = game;
  _controller->setGame(game);
}

indie::PauseCoreState::PauseCoreState(indie::Core &core) :
    _controller(std::make_unique<Pause>(core)),
    _callbacks(std::make_unique<CoreInPauseController>(core, *this)),
    _handle(nullptr)
{
  Engine::get().getEventManager().registerController(_callbacks.get());

}

void indie::PauseCoreState::nextState(indie::ICoreState *state) {
  _nextState = state;
}
