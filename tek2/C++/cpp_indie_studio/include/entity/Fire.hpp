/*
** Fire.hpp for cpp_indie_studio in /home/gogo/rendu/tek2/cpp_indie_studio/include/entity/Fire.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Jun 18 03:40:58 2017 Gauthier Cler
** Last update Sun Jun 18 03:40:58 2017 Gauthier Cler
*/

#ifndef CPP_INDIE_STUDIO_FIRE_HPP
# define CPP_INDIE_STUDIO_FIRE_HPP


#include "IEntity.hpp"

namespace indie {

  class Fire : public IEntity {

  public:
    Fire(irr::scene::ISceneManager *smgr,
	 std::string const& meshID,
	 std::string const& textureID,
	 irr::f32 timer,
	 std::shared_ptr<IEntity> powerUp);

    virtual ~Fire();

    virtual void onDeath(Map &map) override;

    virtual irr::scene::ISceneNode *getSceneNode() const;

    virtual void setTexture(irr::video::ITexture *texture);

    virtual void setVisible(bool state);

    virtual void update(Map &map);

    virtual bool isDead() const;

    virtual irr::scene::ITriangleSelector *getCollisionTriangle() const;

    virtual EntityType getType() const;

    virtual void remove();

    virtual bool isKillable() const;

    virtual bool setDeath(bool death);

    virtual bool isCrossable() const;

  private:
    irr::scene::IAnimatedMeshSceneNode	*_node;
    std::shared_ptr<IEntity>		_powerUp;
    bool				_isDead;
    irr::f32				_timer;
    irr::u32				_beginTime;
  };
}

#endif /* !CPP_INDIE_STUDIO_FIRE_HPP*/
