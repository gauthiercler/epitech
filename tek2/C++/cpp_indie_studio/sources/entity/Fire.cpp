/*
** Fire.cpp for cpp_indie_studio in /home/gogo/rendu/tek2/cpp_indie_studio/sources/entity/Fire.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Jun 18 03:42:06 2017 Gauthier Cler
** Last update Sun Jun 18 03:42:06 2017 Gauthier Cler
*/

#include <entity/Fire.hpp>
#include <Engine.hpp>


indie::Fire::Fire(irr::scene::ISceneManager *smgr,
		  std::string const &meshID,
		  std::string const &textureID,
		  irr::f32 timer,
		  std::shared_ptr<indie::IEntity> powerUp) :
  _node(smgr->addAnimatedMeshSceneNode(Engine::get().getRessourceManager().getAnimatedMesh(meshID))),
  _powerUp(powerUp),
  _isDead(false),
  _timer(timer)
{
  if (_powerUp)
    _powerUp->setVisible(false);
  _beginTime = Engine::get().getWindowManager().getDevice().getTimer()->getTime();
  _node->setScale({75,50,75});
  _node->setMaterialTexture(0, Engine::get().getRessourceManager().getTexture(textureID));
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
  _node->setVisible(true);
}

indie::Fire::~Fire() {

}

void indie::Fire::onDeath(indie::Map &map) {
  if (_powerUp) {
    _powerUp->setVisible(true);
    map.addSpawningQueue(_powerUp,
			 map.getMapPosition(getSceneNode()->getPosition()));
  }
}

irr::scene::ISceneNode *indie::Fire::getSceneNode() const {
  return _node;
}

void indie::Fire::setTexture(irr::video::ITexture *texture) {
  _node->setMaterialTexture(0, texture);
}

void indie::Fire::setVisible(bool state) {
  _node->setVisible(state);
}

void indie::Fire::update(indie::Map &) {
  const irr::u32 now = Engine::get().getWindowManager().getDevice().getTimer()->getTime();
  const irr::f32 deltaTime = static_cast<irr::f32>(now - _beginTime) / 1000.0f;
  if (deltaTime >= _timer)
    this->setDeath(true);
}

bool indie::Fire::isDead() const {
  return _isDead;
}

irr::scene::ITriangleSelector *indie::Fire::getCollisionTriangle() const {
  return _node->getTriangleSelector();
}

indie::EntityType indie::Fire::getType() const {
  return EntityType::FIRE;
}

void indie::Fire::remove() {
  _node->remove();
  _node = nullptr;
}

bool indie::Fire::isKillable() const {
  return true;
}

bool indie::Fire::setDeath(bool death) {
  if (this->isKillable()) {
    _isDead = death;
    return this->isCrossable();
  }
  return false;
}

bool indie::Fire::isCrossable() const {
  return false;
}
