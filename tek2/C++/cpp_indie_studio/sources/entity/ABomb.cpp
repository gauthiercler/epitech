/*
** ABomb.cpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/sources/entity/ABomb.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue May 23 15:26:42 2017 Vincent DUSAUTOIR
** Last update Tue May 23 15:26:42 2017 Vincent DUSAUTOIR
*/

#include <Engine.hpp>
#include <entity/Fire.hpp>
#include "entity/ABomb.hpp"
#include "entity/HumanPlayer.hpp"
#include "entity/IEntity.hpp"

void indie::ABomb::setPower(irr::u64 power) {
  this->_power = power;
}

irr::u64 indie::ABomb::getPower() const {
  return this->_power;
}

indie::ABomb::ABomb(irr::scene::ISceneManager *smgr,
		    std::string const& meshID,
		    std::string const& textureID,
		    APlayer &player,
		    irr::u64 power,
		    irr::f32 timer, irr::u64 attackTime) :
  _node(smgr->addAnimatedMeshSceneNode(Engine::get().getRessourceManager().getAnimatedMesh(meshID)))
  , _player(player)
  , _power(power)
  , _timer(timer)
  , _attackTime(attackTime)
  , _isDead(false)
{
  _node->setScale({10, 10, 10});
  _node->setMaterialTexture(0, Engine::get().getRessourceManager().getTexture(textureID));
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  _node->setVisible(false);

}

irr::f32 indie::ABomb::getTimer() const
{
  return _timer;
}

irr::u64 indie::ABomb::getAttackTime() const
{
  return _attackTime;
}

irr::scene::ISceneNode *indie::ABomb::getSceneNode() const
{
  return _node;
}

void indie::ABomb::setTexture(irr::video::ITexture *texture)
{
  _node->setMaterialTexture(0, texture);
}

indie::ABomb::ABomb(indie::ABomb const &cpy) :
  _node(Engine::get().getSceneManager()->addAnimatedMeshSceneNode(
	cpy._node->getMesh(),
	cpy._node->getParent(),
	cpy._node->getID(),
	cpy._node->getPosition(),
	cpy._node->getRotation(),
	cpy._node->getScale())
    )
  , _player(cpy._player)
  , _power(cpy._power)
  , _timer(cpy._timer)
  , _attackTime(cpy._attackTime)
  , _isDead(cpy._isDead)
  , _type(EntityType::BOMB)
{
  this->_beginTime = Engine::get().getWindowManager().getDevice().getTimer()->getTime();
  _node->setMaterialTexture(0, cpy._node->getMaterial(0).getTexture(0));
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  _node->addShadowVolumeSceneNode();
  irr::scene::IParticleSystemSceneNode* ps = _node->getSceneManager()->addParticleSystemSceneNode(false, _node, -1, {0, 10, 0});

  irr::scene::IParticleEmitter* em = ps->createBoxEmitter(
    irr::core::aabbox3d<irr::f32>(-1,0,-1,1,1,1),
    irr::core::vector3df(0.0f,0.06f,0.0f),
    40,100,
    irr::video::SColor(0,255,0,0),
    irr::video::SColor(0,255,255,255),
    800,2000,100,
    irr::core::dimension2df(10.f,10.f),
    irr::core::dimension2df(20.f,20.f));

  ps->setEmitter(em);
  em->drop();

  irr::scene::IParticleAffector* paf = ps->createFadeOutParticleAffector();

  ps->addAffector(paf);
  paf->drop();
  ps->setPosition(irr::core::vector3df(0,10,0));
  ps->setScale(irr::core::vector3df(2,5,2));
  ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
  ps->setMaterialTexture(0, Engine::get().getRessourceManager().getTexture("fire"));
  ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
}

indie::ABomb &indie::ABomb::operator=(indie::ABomb const &cpy)
{
  if (this != &cpy)
  {
    _beginTime = cpy._beginTime;
    _node = Engine::get().getSceneManager()->addAnimatedMeshSceneNode(
	cpy._node->getMesh(), cpy._node->getParent(),
	cpy._node->getID(), cpy._node->getPosition(),
	cpy._node->getRotation(), cpy._node->getScale());
    _power = cpy._power;
    _attackTime = cpy._attackTime;
    _timer = cpy._timer;
    _isDead = cpy._isDead;
  }
  return (*this);
}

void indie::ABomb::setVisible(bool state)
{
  _node->setVisible(state);
}

irr::scene::ITriangleSelector *indie::ABomb::getCollisionTriangle() const
{
  return _node->getTriangleSelector();
}

indie::ABomb::~ABomb() {
}

void indie::ABomb::update(indie::Map &) {
  const irr::u32 now = Engine::get().getWindowManager().getDevice().getTimer()->getTime();
  const irr::f32 deltaTime = static_cast<irr::f32>(now - _beginTime) / 1000.0f;

  irr::f32 	scale;

  if (deltaTime == 0) {
    scale = 0;
  }
  else {
    scale = 2.0f * deltaTime;
  }
  _node->setScale({10 + scale, 10 + scale, 10 + scale});
  if (deltaTime >= this->_timer)
    this->setDeath(true);
}

void indie::ABomb::onDeath(indie::Map &map) {
  irr::core::vector2di pos = map.getMapPosition(this->getSceneNode()->getPosition());

  std::shared_ptr<IEntity> flame = std::make_shared<Fire>(Engine::get().getSceneManager(), "cube", "lava", 1, nullptr);

  map.addEntity(flame, pos);

  Engine::get().getSoundManager().setSoundVolume("BombExplode", 1000.0);
  Engine::get().getSoundManager().playSound("BombExplode");

  for (irr::s32 range = 1 ; range < static_cast<int>(this->_power + 1); ++range) {
    if (this->killAtPos(map, {pos.X + range, pos.Y}))
      break;
  }

  for (irr::s32 range = 1 ; range < static_cast<int>(this->_power + 1); ++range) {
    if (this->killAtPos(map, {pos.X - range, pos.Y}))
      break;
  }

  for (irr::s32 range = 1 ; range < static_cast<int>(this->_power + 1); ++range) {
    if (this->killAtPos(map, {pos.X, pos.Y + range}))
      break;
  }

  for (irr::s32 range = 1 ; range < static_cast<int>(this->_power + 1); ++range) {
    if (this->killAtPos(map, {pos.X, pos.Y - range}))
      break;
  }
}

bool indie::ABomb::isDead() const {
  return this->_isDead;
}

bool indie::ABomb::setDeath(bool death) {
  if (this->isKillable()) {
    this->_isDead = death;
    return this->isCrossable();
  }
  return false;
}

bool indie::ABomb::isKillable() const {
  return true;
}

bool indie::ABomb::isCrossable() const {
  return false;
}

indie::EntityType indie::ABomb::getType() const {
  return _type;
}

bool indie::ABomb::killAtPos(indie::Map &map, irr::core::vector2di pos) {

  auto cell = map.getCell({pos.X, pos.Y});
  if (cell != nullptr) {
    if (cell->getType() == EntityType::FIRE)
      return false;
    if (!cell->setDeath(true)) {
      if (cell->isKillable())
	this->_player.getScore().addScore(cell->getType());
      return true;
    }
    if (cell->isKillable())
      this->_player.getScore().addScore(cell->getType());
  } else {
    map.addEntity(std::make_shared<Fire>(Engine::get().getSceneManager(),
					 "cube", "lava", 1, nullptr), pos);
  }
  return false;
}

indie::ABomb::ABomb(indie::ABomb &&cpy) :
  _node(cpy._node)
      , _player(cpy._player)
      , _power(cpy._power)
      , _timer(cpy._timer)
      , _attackTime(cpy._attackTime)
      , _isDead(cpy._isDead)
      , _type(EntityType::BOMB)
{
  this->_beginTime = Engine::get().getWindowManager().getDevice().getTimer()->getTime();
}

void indie::ABomb::remove() {
  _node->remove();
  _node = nullptr;
}
