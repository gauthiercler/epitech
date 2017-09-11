/*
** CollisionManager.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/CollisionManager.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 13 16:53:33 2017 Anthony LECLERC
** Last update mar. juin 13 16:53:33 2017 Anthony LECLERC
*/

#include	<irrlicht/ISceneManager.h>
#include	<irrlicht/ISceneNodeAnimatorCollisionResponse.h>
#include <irrlicht/ISceneNodeAnimatorCameraFPS.h>
#include "game/CollisionManager.hpp"
#include "entity/ACube.hpp"
#include "entity/IMutableEntity.hpp"


void indie::CollisionManager::addEntity(indie::IMutableEntity *) {

}

void indie::CollisionManager::addTerrain(indie::ACube *wall) {
  _world->addTriangleSelector(wall->getCollisionTriangle());
}

indie::CollisionManager::CollisionManager(irr::scene::ISceneManager *smgr) :
    _world(nullptr)
{
  _world = smgr->createMetaTriangleSelector();
}

void indie::CollisionManager::setWorld(irr::scene::ITriangleSelector *world) {
  _world->removeAllTriangleSelectors();
  _world->addTriangleSelector(world);
}

indie::CollisionManager::~CollisionManager() {
  if (_world)
    _world->drop();
}

void
indie::CollisionManager::setEntityWorldResponse(indie::IMutableEntity *entity) {
  irr::scene::ISceneNodeAnimatorCollisionResponse *collision;

  collision = entity->getSceneNode()->getSceneManager()->
      createCollisionResponseAnimator(_world, entity->getSceneNode(),
                                      {50, 1, 50},
                                      {0, -5, 0});
  entity->getSceneNode()->addAnimator(collision);
  collision->drop();
}

void indie::CollisionManager::removeEntity(indie::IEntity *entity) {
  this->_world->removeTriangleSelector(entity->getCollisionTriangle());
}

