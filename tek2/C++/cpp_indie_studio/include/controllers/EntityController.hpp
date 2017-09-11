/*
** EntityController.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/EntityController.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 08 22:12:35 2017 Anthony LECLERC
** Last update jeu. juin 08 22:12:35 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_ENTITYCONTROLLER_HPP
#define CPP_INDIE_STUDIO_ENTITYCONTROLLER_HPP

#include	<irrlicht/IEventReceiver.h>
#include	"managers/EventManager.hpp"

namespace indie {
  class IEventController
  {
  private:
    bool _state;
  public:

    /**
     * @brief Virtual function to override for processing events.
     * This function will not be called if the current active state is
     * set to false.
     * @return Return true if the event has been consumed, false otherwise.
     */
    virtual void execute(EventManager const&) = 0;

    IEventController();
    virtual ~IEventController();
    /**
     * @brief Set active state for controller to check if event should be processed.
     * @param state new active state
     */
    void setActive(bool state);

    /**
     * @brief Return the state of the current controller.
     * @return Current active state
     */
    bool isActive() const;
  };

  class IEntityController : public IEventController
  {
  public:
    IEntityController();
    virtual ~IEntityController();
  };
}

#endif //CPP_INDIE_STUDIO_ENTITYCONTROLLER_HPP
