/*
** Map.hpp for indie in /home/sylvain/Documents/projets/tek2/c++/cpp_indie_studio/entityManager
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu May 25 17:45:19 2017 Sylvain Chaugny
** Last update Fri May 26 16:20:47 2017 Sylvain Chaugny
*/

#ifndef			CPP_INDIE_MAP_HPP_
# define		CPP_INDIE_MAP_HPP_

namespace		indie {
  class			ABomb;
  class			IEntity;
}

# include		<map>
# include               <irrlicht/IMeshSceneNode.h>
# include               <irrlicht/IAnimatedMeshSceneNode.h>
# include		<iostream>
# include		<memory>
#include                <queue>
#include                "CollisionManager.hpp"

namespace		indie
{

  class IEntity;
  class APlayer;
  class Brick;

  class			Map
  {
  public:
    typedef std::map<irr::core::vector2di, std::shared_ptr<IEntity>> t_map;

    static const irr::f32 Tilesize;
  private:
    irr::scene::IMeshSceneNode *_terrain;

    int			_width;
    int			_length;
    t_map		_map;
    std::vector<std::shared_ptr<APlayer> > _players;
    std::queue<std::pair<irr::core::vector2di, std::shared_ptr<IEntity> > > _addingQueue;

  public:
    Map(irr::scene::IMeshSceneNode *node, int width, int length);
    virtual		~Map();

    virtual void setTexture(irr::video::ITexture *texture);
    virtual void setVisible(bool state);
    virtual irr::scene::ISceneNode *getSceneNode() const;
    void		setWidth(int width);
    void		setLength(int length);
    int			getWidth() const ;
    int			getLength() const;
    void		addEntity(std::shared_ptr<IEntity> entity,
                                  irr::core::vector2di const &pos);
    void		addChild(IEntity *entity,
                                 irr::core::vector2di const &pos);
    void		removeEntity(irr::core::vector2di const &pos);
    IEntity		*getCell(irr::core::vector2di const &pos);
    void		clear();
    virtual irr::scene::ITriangleSelector *getCollisionTriangle() const;
    void		update(CollisionManager& collisions);
    irr::core::vector2di	getMapPosition(const irr::core::vector3df &pos) const;
    irr::core::vector3df	getRealPosition(const irr::core::vector2di &pos) const;
    void			explodeBomb(const ABomb *bomb);

    void                addSpawningQueue(std::shared_ptr<IEntity> entity,
                                         irr::core::vector2di const& pos);

    void		addPlayer(std::shared_ptr<APlayer> player,
                                  irr::core::vector2di const &pos);
    APlayer              *getPlayer(irr::core::vector2di const& pos);
    const t_map			&get() const;
    const std::vector<std::shared_ptr<APlayer>> &getPlayers() const;
    size_t		playerNbr() const;

  };
};

#endif			// CPP_INDIE_MAP_HPP_
