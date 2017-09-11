/*
** APlayer.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/APlayer.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 15 20:44:41 2017 Anthony LECLERC
** Last update jeu. juin 15 20:44:41 2017 Anthony LECLERC
*/

#include        <iostream>
#include 	<entity/AquaBomb.hpp>
#include <entity/Fire.hpp>
#include 	"entity/BasicBomb.hpp"
#include        "controllers/PlayerController.hpp"
#include	"entity/APlayer.hpp"

indie::APlayer::APlayer(irr::scene::ISceneManager *smgr,
		      std::string const& meshID,
		      std::string const& textureID,
		      std::string const& name,
			bool visible) :
  _node(smgr->addAnimatedMeshSceneNode(
    Engine::get().getRessourceManager().getAnimatedMesh(meshID)
  ))
  , _textureID(textureID)
  , _bombSpawn(this, std::make_unique<BasicBomb>(smgr, *this))
  , _name(name)
  , _running(false)
  , _dropping(false)
  , _goDrop(false)
  , _isDead(false)
  , _speed(0)
{
  _node->setMaterialTexture(0, Engine::get().getRessourceManager().getTexture(textureID));
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
  _node->setVisible(visible);
  _node->setScale({75, 75, 75});
}

indie::APlayer::~APlayer()
{
}

void indie::APlayer::move(irr::core::vector3df const& v)
{
  irr::core::vector3df pos;

  pos = _node->getPosition();
  _node->setPosition( {pos.X + (v.X * (1 + this->_speed / 100)),
		       pos.Y + (v.Y * (1 + this->_speed / 100)),
		       pos.Z + (v.Z * (1 + this->_speed / 100)) } );
}

irr::scene::ISceneNode *indie::APlayer::getSceneNode() const
{
  return _node;
}

void indie::APlayer::setTexture(irr::video::ITexture *texture)
{
  _node->setMaterialTexture(0, texture);
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

void indie::APlayer::putBomb()
{
  if (this->_bombSpawn.leftBombs() > 0 && !_goDrop)
  {
    Engine::get().getSoundManager().playSound("BombSet");
    this->_goDrop = true;
  }
}

irr::scene::ITriangleSelector *indie::APlayer::getCollisionTriangle() const
{
  return _node->getTriangleSelector();
}

void indie::APlayer::onDeath(indie::Map &) {
  Engine::get().getSoundManager().playSound("PlayerDeath");
}

bool indie::APlayer::isDead() const {
  return _isDead;
}

void indie::APlayer::setMesh(irr::scene::IAnimatedMesh *mesh) {
  _node->setMesh(mesh);
}

void indie::APlayer::run() {
  if (!this->isRunning() && !this->isDropping()) {
    _node->setLoopMode(true);
    _node->setAnimationSpeed(25);
    this->setMesh(Engine::get().getRessourceManager().getAnimatedMesh("bomberman_run"));
    this->setTexture(Engine::get().getRessourceManager().getTexture(_textureID));
    _running = true;
    _dropping = false;
  }
}

void indie::APlayer::stand() {
  if ((this->isRunning() || this->isDropping()) && _node) {
    _node->setLoopMode(true);
    _node->setAnimationSpeed(25);
    this->setMesh(Engine::get().getRessourceManager().getAnimatedMesh("bomberman_stand"));
    this->setTexture(Engine::get().getRessourceManager().getTexture(_textureID));
    _running = false;
    _dropping = false;
  }
}

bool indie::APlayer::isRunning() const {
  return _running;
}

void indie::APlayer::updateDropAnimation() {
  if (_dropping)
  {
    this->stand();
  }
}

bool indie::APlayer::isDropping() const {
  return _dropping;
}

void indie::APlayer::setBombType(std::unique_ptr<indie::ABomb> proto) {
  proto->setPower(_bombSpawn.getProtoype().getPower());
  _bombSpawn.setPrototype(std::move(proto));
}

bool indie::APlayer::setDeath(bool death) {
  this->_isDead = death;
  return (true);
}

bool indie::APlayer::isKillable() const {
  return true;
}

bool indie::APlayer::isCrossable() const {
  return true;
}

indie::EntityType indie::APlayer::getType() const {
  return EntityType::PLAYER;
}

void indie::APlayer::addBomb() {
  ++this->_bombSpawn;
}

void indie::APlayer::addPower(int value) {
  this->_bombSpawn.getProtoype().setPower(this->_bombSpawn.getProtoype().getPower() + value);
}

indie::Score &indie::APlayer::getScore() {
  return this->_score;
}

void indie::APlayer::addMalus(int value) {
  irr::u64 power = this->_bombSpawn.getProtoype().getPower();
  --this->_bombSpawn;
  _bombSpawn.setPrototype(std::make_unique<BasicBomb>(_node->getSceneManager(), *this,
						      static_cast<int>(power) > value ? static_cast<int>(power) - value : 1));
}

void indie::APlayer::addSpeed(int value) {
  this->_speed += value;
  if (this->_speed > 100)
    this->_speed = 100;
}

indie::BombSpawner &indie::APlayer::getSpawner()  {
  return _bombSpawn;
}

const std::string &indie::APlayer::getName() const {
  return _name;
}

void indie::APlayer::remove() {
  _node->remove();
  _node = nullptr;
}

size_t indie::APlayer::getSpeed() const {
  return _speed;
}

