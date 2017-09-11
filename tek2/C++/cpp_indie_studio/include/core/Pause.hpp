/*
** Pause.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/Pause.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juin 18 01:03:56 2017 Anthony LECLERC
** Last update dim. juin 18 01:03:56 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_PAUSE_HPP
#define CPP_INDIE_STUDIO_PAUSE_HPP

#include <game/Game.hpp>
#include "menu/MenuButton.hpp"
#include "IController.hpp"

namespace indie {
  class Pause : public IController {
  private:

    std::vector<std::pair<std::pair<irr::EKEY_CODE, indie::keyStates>, std::function<void (void)>>>	_events;
    std::vector<std::pair<std::unique_ptr<MenuButton>, std::function<void (void)>>>			_buttons;
    std::vector<std::pair<std::unique_ptr<MenuButton>, std::function<void (void)>>>::iterator		_currentButton;

    indie::Core				&_core;
    std::unique_ptr<indie::Game>	*_game;

  public:
    Pause(indie::Core &core);

    virtual ~Pause();

    virtual void receiveEvent(const indie::EventManager &eventManager) override;

    virtual bool render() override;

    virtual bool clear() override;

    virtual bool update() override;

    virtual void setActive(bool b) override;

    void		setGame(std::unique_ptr<indie::Game> *game);

    void		jumpNext(void);
    void		jumpPrev(void);
    void		select(void);

    void		save(void);
    void		resume(void);
    void		quit(void);

    void		drawSelected(const std::string &selectedElement);
  };
}

#endif //CPP_INDIE_STUDIO_PAUSE_HPP
