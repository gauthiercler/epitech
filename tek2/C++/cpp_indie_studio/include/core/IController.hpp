/*
** Controller.hpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/include/core/Controller.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed May 24 14:45:52 2017 Vincent DUSAUTOIR
** Last update Wed May 24 14:45:53 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_INDIE_STUDIO_CONTROLLER_HPP
#define CPP_INDIE_STUDIO_CONTROLLER_HPP

#include <irrlicht/IEventReceiver.h>
#include "managers/EventManager.hpp"

namespace indie
{

  /**
   * @brief Abstraction class for Game & Menu
   */
  class			IController {
  public:

    /**
     * @brief Destructor
     */
    virtual ~IController() {};

    /**
     * @brief Receive an event from the eventManager
     * @param eventManager
     */
    virtual void	receiveEvent(const indie::EventManager &eventManager) = 0;

    /**
     * @brief render the scene
     * @return bool
     */
    virtual bool	render() = 0;

    /**
     * @brief clear the scene
     * @return bool
     */
    virtual bool	clear() = 0;

    /**
     * @brief update the scene
     * @return bool
     */
    virtual bool	update() = 0;

    virtual void        setActive(bool) = 0;
  };
}

#endif //CPP_INDIE_STUDIO_CONTROLLER_HPP
