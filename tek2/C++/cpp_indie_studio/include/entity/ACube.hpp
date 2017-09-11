/*
** IWall.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/IWall.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:17:34 2017 Anthony LECLERC
** Last update jeu. mai 04 15:17:34 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_IWALL_HPP
#define CPP_INDIE_STUDIO_IWALL_HPP

#include <irrlicht/IMeshSceneNode.h>
#include <string>
#include "IEntity.hpp"

namespace indie {
  /**
   * @brief IWall interface
   */
  class ACube : public IEntity {
  private:
    bool			_isDead;
    bool			_killable;
    bool			_crossable;
    EntityType			_type;
  protected:
    irr::scene::IMeshSceneNode *_node;
  public:
    ACube(irr::scene::ISceneManager *smgr, std::string const& meshID, bool killable, bool crossable, EntityType type);
    virtual ~ACube();

    virtual irr::scene::ISceneNode *getSceneNode() const override;
    virtual irr::core::vector3df const &getPosition() const;
    virtual void setPosition(irr::core::vector3df const &pos);
    virtual void setTexture(irr::video::ITexture *texture) override;
    virtual void setVisible(bool state) override;
    virtual void update(Map &map);
    virtual bool isDead() const;
    virtual bool setDeath(bool death);
    virtual bool isKillable() const;
    virtual bool isCrossable() const;
    virtual void onDeath(Map &map);
    virtual irr::scene::ITriangleSelector *getCollisionTriangle() const;
    virtual void remove();

    virtual EntityType getType() const;
  };
}

#endif //CPP_INDIE_STUDIO_IWALL_HPP
