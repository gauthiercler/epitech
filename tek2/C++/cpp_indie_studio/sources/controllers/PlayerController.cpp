/*
** PlayerController.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/PlayerController.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juin 11 01:28:45 2017 Anthony LECLERC
** Last update dim. juin 11 01:28:45 2017 Anthony LECLERC
*/

#include "Engine.hpp"
#include "controllers/PlayerController.hpp"

void indie::PlayerKeyboardController::execute(indie::EventManager const& event)
{
  bool  idle = true;
  if (event.isKeyDown(_bomb)) {
    _target->putBomb();
    idle = false;
  }
  for (auto&& key : _keymap)
  {
    if (event.isKeyDown(key.first))
    {
      key.second.second();
      idle = false;
    }
  }
  if (idle && !_target->isDropping())
    _target->stand();
}

indie::PlayerKeyboardController::PlayerKeyboardController(irr::EKEY_CODE Up,
							  irr::EKEY_CODE Down,
							  irr::EKEY_CODE Right,
							  irr::EKEY_CODE Left,
							  irr::EKEY_CODE Bomb) :
    _keymap()
{
  _keymap[Up] = {EPA_MOVE_UP, [this]() {
    _target->run();
    _target->move( {0, 0, 10} );
    _target->getSceneNode()->setRotation({0, 180, 0});
  } };
  _keymap[Down] = {EPA_MOVE_DOWN, [this]() {
    _target->run();
    _target->move( {0, 0, -10} );
    _target->getSceneNode()->setRotation({0, 0, 0});
  } };
  _keymap[Left] = {EPA_MOVE_LEFT, [this]() {
    _target->run();
    _target->move( {-10, 0, 0} );
    _target->getSceneNode()->setRotation({0, 90, 0});
  } };
  _keymap[Right] = {EPA_MOVE_RIGHT, [this]() {
    _target->run();
    _target->move( {10, 0, 0} );
    _target->getSceneNode()->setRotation({0, 270, 0});
  } };
   _bomb = Bomb;
}