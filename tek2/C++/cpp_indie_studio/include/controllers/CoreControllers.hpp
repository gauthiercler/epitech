/*
** CoreControllers.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/CoreControllers.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juin 11 01:23:52 2017 Anthony LECLERC
** Last update dim. juin 11 01:23:52 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_CORECONTROLLERS_HPP
# define CPP_INDIE_STUDIO_CORECONTROLLERS_HPP

#include 	"EntityController.hpp"
#include	"core/Core.hpp"

namespace indie {
  class ICoreController : public IEventController
  {
  protected:
    Core& _core;
  public:
    ICoreController(Core& core);
  };

  class ICoreInGameController : public ICoreController
  {
  public:
    ICoreInGameController(Core& core);
    virtual void execute(EventManager const& manager);
  };

  class CoreInPauseController : public ICoreController
  {
  private:
    PauseCoreState &_pause;
  public:
    CoreInPauseController(Core&, PauseCoreState&);

    virtual void execute(EventManager const &manager) override;
  };
}


#endif //CPP_INDIE_STUDIO_CORECONTROLLERS_HPP
