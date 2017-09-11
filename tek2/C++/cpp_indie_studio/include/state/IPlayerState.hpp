/*
** IPlayerState.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/IPlayerState.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 12 17:55:33 2017 Anthony LECLERC
** Last update lun. juin 12 17:55:33 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_IPLAYERSTATE_HPP
# define CPP_INDIE_STUDIO_IPLAYERSTATE_HPP

# include <managers/EventManager.hpp>
# include <game/Map.hpp>

namespace indie {

  /**
   * @brief IPlayerState
   */
  class IEntityState {
  public:

    virtual ~IEntityState() {}

    /**
 * @brief Handle input
 * @param events Events from last frame.
 */

    virtual void entry() = 0;
    /**
     * @brief Update method called at each frame of the game.
     * Handles collision, displacement and actions.
     * @param world Contains all informations related to the game map.
     * @return Transitions to the next state, return this if it doesn't change.
     */
    virtual IEntityState *update(Map&& world) = 0;

  };

  /**
   * @brief Specific interface for Human player
   * IA states *should* derives from IPlayerState
   */
  class IPlayerState : public IEntityState {
  public:
    virtual ~IPlayerState() {}

  };

  class IHumanPlayerState : public IPlayerState {

  };

}
#endif //CPP_INDIE_STUDIO_IPLAYERSTATE_HPP
