/*
** CoreControllers.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/CoreControllers.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juin 11 01:22:49 2017 Anthony LECLERC
** Last update Sun Jun 18 14:26:11 2017 Sylvain Chaugny
*/

#define NOMINMAX 1

#include <netinet/in.h>
#include        "state/core/ACoreState.hpp"
#include	"controllers/CoreControllers.hpp"

indie::ICoreController::ICoreController(indie::Core &core) :
    IEventController(),
    _core(core)
{}

void indie::ICoreInGameController::execute(indie::EventManager const &manager)
{
  if (manager.isKeyPressed(irr::EKEY_CODE::KEY_ESCAPE)) {
    _core.changeToPause();
  }
}

indie::ICoreInGameController::ICoreInGameController(indie::Core &core) :
    ICoreController(core)
{}

void indie::CoreInPauseController::execute(indie::EventManager const &manager) {
  if (manager.isKeyPressed(irr::EKEY_CODE::KEY_ESCAPE))
  {
    _pause.nextState(Core::MenuState);
  }
  else if (manager.isKeyPressed(irr::EKEY_CODE::KEY_SPACE))
    _pause.nextState(Core::GameState);
}

indie::CoreInPauseController::CoreInPauseController(indie::Core &core, PauseCoreState& pause) :
    ICoreController(core),
    _pause(pause)
{

}
