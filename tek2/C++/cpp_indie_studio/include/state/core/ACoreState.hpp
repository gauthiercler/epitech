/*
** ICoreState.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/ICoreState.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 12 19:05:24 2017 Anthony LECLERC
** Last update lun. juin 12 19:05:24 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_ICORESTATE_HPP
# define CPP_INDIE_STUDIO_ICORESTATE_HPP

#include <core/Pause.hpp>
#include "core/Core.hpp"
#include "state/IPlayerState.hpp"
#include "controllers/CoreControllers.hpp"

namespace indie {
  class ICoreState {
  public:
    virtual ~ICoreState() {}
    virtual ICoreState *update(Core& core) = 0;

    virtual void entry(Core& core) = 0;
    virtual void quit(Core& core) = 0;
  };

  class MenuCoreState : public ICoreState {
  private:
     std::unique_ptr<Menu> _controller;
  public:
    MenuCoreState(Core& core);
    virtual ~MenuCoreState() {}

    virtual ICoreState *update(Core &core);

    virtual void entry(Core& core) override;
    virtual void quit(Core &core) override;
  };

  class GameCoreState : public ICoreState {
  private:
    std::unique_ptr<Game> _controller;
    std::shared_ptr<ICoreController> _callbacks;
  public:
    GameCoreState(Core& core);
    virtual ~GameCoreState() {}

    virtual ICoreState *update(Core &core) override;
    virtual void entry(Core& core) override;
    virtual void quit(Core &core) override;

  };

  class PauseCoreState : public ICoreState {
  private:
    std::unique_ptr<Pause> _controller;
    std::unique_ptr<ICoreController> _callbacks;
    std::unique_ptr<Game> *_handle;
    ICoreState *_nextState;

  public:
    PauseCoreState(Core &);
    virtual ~PauseCoreState() {}
    virtual void entry(Core &core) override;
    virtual void quit(Core &core) override;

    void settingBackgroundGame(std::unique_ptr<Game>* game);

    virtual ICoreState *update(Core &core) override;

    void nextState(ICoreState *state);
  };
}

#endif //CPP_INDIE_STUDIO_ICORESTATE_HPP
