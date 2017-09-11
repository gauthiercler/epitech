/*
** APowerUp.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/APowerUp.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 14 17:47:41 2017 Anthony LECLERC
** Last update mer. juin 14 17:47:41 2017 Anthony LECLERC
*/

#include <Engine.hpp>
#include <entity/Fire.hpp>
#include "entity/APowerUp.hpp"

irr::scene::ISceneNode *indie::APowerUp::getSceneNode() const {
  return _node;
}

void indie::APowerUp::setTexture(irr::video::ITexture *texture) {
  _node->setMaterialTexture(0, texture);
  _node->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
}

void indie::APowerUp::setVisible(bool state) {
  _node->setVisible(state);
}

void indie::APowerUp::update(indie::Map &map) {
  APlayer *target = map.getPlayer(map.getMapPosition(_node->getPosition()));
  if (target)
  {
    power(*target);
    setDeath(true);
  }
}

void indie::APowerUp::onDeath(indie::Map &map) {
  Engine::get().getSoundManager().playSound("PowerUp");

  auto pos = map.getMapPosition(_node->getPosition());
  for (auto &player : map.getPlayers()) {
    if (pos == map.getMapPosition(player.get()->getSceneNode()->getPosition()))
      return ;
  }
  std::shared_ptr<IEntity> flame = std::make_shared<Fire>(Engine::get().getSceneManager(), "cube", "lava", 1,
							  nullptr);
  map.addSpawningQueue(flame, map.getMapPosition(_node->getPosition()));

}

bool indie::APowerUp::isDead() const {
  return _isDead;
}

bool indie::APowerUp::setDeath(bool death) {
  if (isKillable())
  {
    _isDead = death;
    return (isCrossable());
  }
  return (false);
}

bool indie::APowerUp::isKillable() const {
  return true;
}

bool indie::APowerUp::isCrossable() const {
  return true;
}

irr::scene::ITriangleSelector *indie::APowerUp::getCollisionTriangle() const {
  return _node->getTriangleSelector();
}

indie::APowerUp::APowerUp(irr::scene::ISceneManager *smgr,
                          std::string const &meshID) :
    _isDead(false),
    _type(EntityType::BONUS),
    _node(nullptr)
{
  _node = smgr->addAnimatedMeshSceneNode(Engine::get().getRessourceManager().getAnimatedMesh(meshID));
  _node->setScale({70, 70, 70});
  irr::scene::ISceneNodeAnimator *anim = smgr->createRotationAnimator({ 0, 2, 0});
  _node->addAnimator(anim);
  anim->drop();
}

indie::APowerUp::~APowerUp() {}

indie::EntityType indie::APowerUp::getType() const {
  return _type;
}

void indie::APowerUp::remove() {
  _node->remove();
  _node = nullptr;
}
