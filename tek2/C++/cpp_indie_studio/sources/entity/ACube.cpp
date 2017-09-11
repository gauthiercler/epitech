/*
** ACube.cpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/sources/entity/ACube.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Jun 12 17:10:33 2017 Vincent DUSAUTOIR
** Last update Mon Jun 12 17:10:33 2017 Vincent DUSAUTOIR
*/

#include	"Engine.hpp"
#include	"entity/ACube.hpp"

irr::scene::ISceneNode *indie::ACube::getSceneNode() const {
  return this->_node;
}

irr::core::vector3df const &indie::ACube::getPosition() const {
  return this->_node->getPosition();
}

void indie::ACube::setPosition(irr::core::vector3df const &pos) {
  this->_node->setPosition(pos);
}

void indie::ACube::setTexture(irr::video::ITexture *texture) {
  this->_node->setMaterialTexture(0, texture);
}

void indie::ACube::setVisible(bool state) {
  this->_node->setVisible(state);
}

indie::ACube::~ACube() {}

indie::ACube::ACube(irr::scene::ISceneManager *smgr,
		    const std::string &meshID, bool killable, bool crossable, EntityType type) :
  _isDead(false),
  _killable(killable),
  _crossable(crossable),
  _type(type),
  _node(smgr->addMeshSceneNode(Engine::get().getRessourceManager().getStaticMesh(meshID)))
{
  irr::scene::ITriangleSelector *selector;

  this->_node->setScale({75,50,75});
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
  _node->addShadowVolumeSceneNode();
  selector = smgr->createTriangleSelector(_node->getMesh(), _node);
  _node->setTriangleSelector(selector);
  selector->drop();
}

irr::scene::ITriangleSelector *indie::ACube::getCollisionTriangle() const {
  return _node->getTriangleSelector();
}

void indie::ACube::update(indie::Map &) {

}

bool indie::ACube::isDead() const {
  return this->_isDead;
}

bool indie::ACube::setDeath(bool death) {
  if (this->isKillable()) {
    this->_isDead = death;
    return this->isCrossable();
  }
  return false;
}

void indie::ACube::onDeath(indie::Map &) {
}

bool indie::ACube::isKillable() const {
  return this->_killable;
}

bool indie::ACube::isCrossable() const {
  return this->_crossable;
}

indie::EntityType indie::ACube::getType() const {
  return _type;
}

void indie::ACube::remove() {
  _node->remove();
  _node = nullptr;
}
