/*
** PlayerController.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/PlayerController.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juin 11 01:24:48 2017 Anthony LECLERC
** Last update Fri Jun 16 17:17:39 2017 Sylvain Chaugny
*/

#ifndef CPP_INDIE_STUDIO_PLAYERCONTROLLER_HPP
#define CPP_INDIE_STUDIO_PLAYERCONTROLLER_HPP

#include	<functional>
#include	<map>
#include	"controllers/EntityController.hpp"
#include        "entity/HumanPlayer.hpp"

namespace indie {
  class IPlayerController : public IEntityController
  {
  protected:
    HumanPlayer	*_target;

  public:
    IPlayerController() : _target(nullptr) {}

    void setTarget(HumanPlayer *player) { _target = player; }
  };

  class PlayerKeyboardController : public IPlayerController {
  private:
    std::map<irr::EKEY_CODE,
	std::pair<EPlayerActions, std::function<void()> > >_keymap;
    irr::EKEY_CODE  _bomb;
  public:
    virtual void execute(EventManager const& event);

    PlayerKeyboardController(irr::EKEY_CODE Up, irr::EKEY_CODE Down,

			     irr::EKEY_CODE Right, irr::EKEY_CODE Left,
			     irr::EKEY_CODE Bomb);
    ~PlayerKeyboardController() {};
  };
}

#endif //CPP_INDIE_STUDIO_PLAYERCONTROLLER_HPP
