/*
** CollisionManager.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/CollisionManager.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 13 16:53:33 2017 Anthony LECLERC
** Last update mar. juin 13 16:53:33 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_COLLISIONMANAGER_HPP
#define CPP_INDIE_STUDIO_COLLISIONMANAGER_HPP

#include <irrlicht/ITriangleSelector.h>
#include <irrlicht/IMetaTriangleSelector.h>

namespace indie {

  class ACube;
  class IEntity;
  class IMutableEntity;
  class CollisionManager {
  private:
    irr::scene::IMetaTriangleSelector *_world;
  public:
    CollisionManager(irr::scene::ISceneManager *world);
    ~CollisionManager();
    void setWorld(irr::scene::ITriangleSelector *world);
    void addEntity(IMutableEntity *entity);
    void removeEntity(IEntity *entity);
    void addTerrain(ACube *wall);

    void setEntityWorldResponse(IMutableEntity *entity);
  };
}


#endif //CPP_INDIE_STUDIO_COLLISIONMANAGER_HPP
