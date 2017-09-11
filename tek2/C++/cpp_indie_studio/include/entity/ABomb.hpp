/*
** IBomb.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/IBomb.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:16:29 2017 Anthony LECLERC
** Last update jeu. mai 04 15:16:29 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_IBOMB_HPP
#define CPP_INDIE_STUDIO_IBOMB_HPP


#include <string>
#include <irrlicht/IAnimatedMeshSceneNode.h>
#include "IEntity.hpp"

namespace indie {

  class APlayer;

  class ABomb : public IEntity {
  protected:
    irr::scene::IAnimatedMeshSceneNode *_node;

    APlayer &_player;
    irr::u64 _power;
    irr::f32 _timer;
    irr::u32 _beginTime;
    irr::u64 _attackTime;
    bool _isDead;
    EntityType _type;
  public:
    ABomb(irr::scene::ISceneManager *smgr,
	  std::string const& meshID,
	  std::string const& textureID,
	  APlayer &player,
	  irr::u64 power = 1,
	  irr::f32 timer = 2.5,
	  irr::u64 _attackTime = 2);
    ABomb(ABomb const& cpy);
    ABomb(ABomb &&cpy);
    ABomb& operator=(ABomb const& cpy);
    virtual ~ABomb();
    virtual ABomb *clone() = 0;

    irr::u64  getPower() const;
    void setPower(irr::u64 power);
    irr::f32 getTimer() const;
    irr::u64 getAttackTime() const;
    virtual irr::scene::ISceneNode *getSceneNode() const;
    virtual void setTexture(irr::video::ITexture *texture);
    virtual void setVisible(bool state);
    virtual void onDeath(Map &map);
    virtual bool isDead() const;
    virtual bool setDeath(bool death);
    virtual bool isKillable() const;
    virtual bool isCrossable() const;
    virtual irr::scene::ITriangleSelector *getCollisionTriangle() const;
    virtual void update(Map &map);
    virtual void remove();

    virtual EntityType getType() const;

  protected:
    virtual bool	killAtPos(Map &map, irr::core::vector2di pos);
  };
  /**
   * @brief Bomb class
   */
}

#endif //CPP_INDIE_STUDIO_IBOMB_HPP
