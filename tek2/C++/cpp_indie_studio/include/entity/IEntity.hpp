/*
** IEntity.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/IEntity.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:15:44 2017 Anthony LECLERC
** Last update jeu. mai 04 15:15:44 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_IENTITY_HPP
#define CPP_INDIE_STUDIO_IENTITY_HPP


#include <irrlicht/vector3d.h>
#include <irrlicht/ITexture.h>
#include <irrlicht/ISceneNode.h>
#include "game/Map.hpp"

namespace indie {

  /**
   * @brief IEntity interface
   */
  enum class EntityType {
    EMPTY,
    BONUS,
    MALUS,
    BOX,
    BRICK,
    BOMB,
    FIRE,
    FUTURE_FIRE,
    PLAYER,
    POWER_UP,
    BOMB_UP,
    SPEED_UP
  };

  class IEntity {
  public:

    virtual ~IEntity() {}

    /**
     * @brief Get scene node of entity
     * @return Scene node
     */
    virtual irr::scene::ISceneNode *getSceneNode() const = 0;

    /**
     * @brief Set texture entity.
     * @param texture
     */
    virtual void setTexture(irr::video::ITexture *texture) = 0;

    /**
     * @brief Set Entity visible in SceneManager
     * @param state
     */
    virtual void setVisible(bool state) = 0;

    virtual void update(Map &map) = 0;

    /**
     * @brief Called when the Entity will die.
     * @param map
     */
    virtual void onDeath(Map &map) = 0;

    /**
     * @brief Check if entity will die.
     * @return Death status
     */
    virtual bool isDead() const = 0;

    /**
     * @brief Set death status of Entity
     * @param next death status
     * @return If the entity is killable, it returns false and doesn't modify death status.
     * Else, set the death status and return crossable state (see isCrossable() )
     */
    virtual bool setDeath(bool death) = 0;

    /**
     * @brief Checks if the entity can be killed by bombs.
     * @return
     */
    virtual bool isKillable() const = 0;

    /**
     * @brief Checks if the entity blocks the bombs projectiles.
     * @return return false if the entity blocks, true otherwise
     */
    virtual bool isCrossable() const = 0;

    virtual irr::scene::ITriangleSelector *getCollisionTriangle() const = 0;

    virtual EntityType getType() const = 0;

    virtual void remove() = 0;
  };
}

#endif //CPP_INDIE_STUDIO_IENTITY_HPP
