/*
** MapManager.cpp for cpp_indie_studio in /home/gogo/rendu/tek2/cpp_indie_studio/sources/game/MapManager.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jun 07 10:44:21 2017 Gauthier Cler
** Last update Wed Jun 07 10:44:22 2017 Gauthier Cler
*/

#include <irrlicht/ISceneManager.h>
#include <game/MapManager.hpp>
#include <Error.hpp>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <list>
#include <core/Random.hpp>
#include <assert.h>
#include <entity/Brick.hpp>
#include <entity/Box.hpp>
#include <Engine.hpp>

indie::MapManager::MapManager(irr::scene::ISceneManager *smgr) :
    _root(smgr->addEmptySceneNode(nullptr))
    , _hasMap(false)
    , _attr()
    , _brickT(nullptr)
    , _boxT(nullptr)
{
  _root->setVisible(true);
}

indie::MapManager::~MapManager() {

}

void indie::MapManager::generate(irr::s32 sizeX, irr::s32 sizeY, double density) {
  _attr.infos.width = static_cast<irr::u32>(sizeX);
  _attr.infos.length = static_cast<irr::u32>(sizeY);
  _density = density;
  _brickT = Engine::get().getRessourceManager().getTexture("brick");
  _boxT = Engine::get().getRessourceManager().getTexture("cube");
  if (sizeY < _minMapSize || sizeY < _minMapSize) 	throw GameError("Map is too small");
  assert(density <= 1);
  assert(density >= 0);
  this->reset();
  this->generateBricks();
  this->generateBorders();
  this->generateBlocks();
  _attr.infos.spawns.push_back({1 , 1});
  _attr.infos.spawns.push_back({1 , static_cast<int>(_attr.infos.length) - 2});
  _attr.infos.spawns.push_back({static_cast<int>(_attr.infos.width) - 2 , static_cast<int>(_attr.infos.length) - 2});
  _attr.infos.spawns.push_back({static_cast<int>(_attr.infos.width) - 2 , 1});
  this->genPlayerSpawn();
  _hasMap = true;
}


void indie::MapManager::generateBricks() {
  uint64_t iteratorY = 0;
  for (auto &line : _mapi) {
    uint64_t iteratorX = 0;
    for (auto &cell : line) {
      if (iteratorX % 2 == 0 && iteratorY % 2 == 0)
        cell = MapTile::BRICK;
      iteratorX += 1;
    }
    iteratorY += 1;
  }
}

void indie::MapManager::displayMap() const {
  for (auto &line : _mapi) {
    for (auto &cell : line)
      std::cout << static_cast<int>(cell);
    std::cout << std::endl;
  }
}


bool indie::MapManager::isBorder(uint64_t posX, uint64_t posY) const {
  return posY == 0
	 || posY == _attr.infos.length - 1
	 || posX == 0
	 || posX == _attr.infos.width - 1;
}


void indie::MapManager::generateBlocks() {
  for (auto &line : _mapi) {
    double lineDensity = std::floor(this->getLineEmptyCells(line) * _density);
    while (lineDensity) {
      std::size_t idx = Random::get().generate() % line.size();
      if (line.at(idx) == MapTile::EMPTY) {
	line.at(idx) = MapTile::BLOCK;
	lineDensity -= 1;
      }
    }
  }
}

uint64_t indie::MapManager::getLineEmptyCells(const std::vector<MapTile > &line) const {
  return static_cast<uint64_t>(std::count(line.begin(), line.end(), MapTile::EMPTY));
}

void indie::MapManager::genPlayerSpawn() {
  _mapi[1][1] = MapTile::EMPTY;
  _mapi[1][2] = MapTile::EMPTY;
  _mapi[2][1] = MapTile::EMPTY;

  _mapi[1][_attr.infos.width - 2] = MapTile::EMPTY;
  _mapi[1][_attr.infos.width - 3] = MapTile::EMPTY;
  _mapi[2][_attr.infos.width - 2] = MapTile::EMPTY;

  _mapi[_attr.infos.length - 2][1] = MapTile::EMPTY;
  _mapi[_attr.infos.length - 3][1] = MapTile::EMPTY;
  _mapi[_attr.infos.length - 2][2] = MapTile::EMPTY;

  _mapi[_attr.infos.length - 2][_attr.infos.width - 2] = MapTile::EMPTY;
  _mapi[_attr.infos.length - 3][_attr.infos.width - 2] = MapTile::EMPTY;
  _mapi[_attr.infos.length - 2][_attr.infos.width - 3] = MapTile::EMPTY;
}

std::vector<std::vector<indie::MapManager::MapTile> > const& indie::MapManager::get() const {
  return _mapi;
}

void indie::MapManager::set(uint64_t x, uint64_t y,
			    indie::MapManager::MapTile item) {
  if (_hasMap && x < _attr.infos.width && y < _attr.infos.length && !this->isBorder(x, y))
    _mapi[y][x] = item;
}

void indie::MapManager::reset() {
  _mapi.clear();
  _mapi.resize(_attr.infos.length, std::vector<MapTile>(_attr.infos.width));
}

void indie::MapManager::generate(indie::MapAttributes const &attr)
{
  _attr = attr;
  _attr.infos.width += 1;
  _attr.infos.length += 1;
  std::vector<TileInfo>::iterator wall;
  wall = std::find_if(_attr.data.walls.begin(), _attr.data.walls.end(),
                      [] (TileInfo& tileType) {
                          return tileType.name == "Brick"; });
  if (wall == _attr.data.walls.end())
    throw IrrlichtError("No brick type found");

  std::vector<TileInfo>::iterator boxes;
  boxes = std::find_if(_attr.data.walls.begin(), _attr.data.walls.end(),
                       [] (TileInfo& tileType) { return tileType.name == "Box"; });
  if (boxes == _attr.data.walls.end())
    throw IrrlichtError("No Box type found");
  try {
    _brickT = Engine::get().getRessourceManager().getTexture(
        wall->texturePath);
    _boxT = Engine::get().getRessourceManager().getTexture(boxes->texturePath);
  }
  catch (IrrlichtError const& err) {
    std::cerr << "Cannot load texture: " << err.what() << std::endl;
  }
  _mapi.resize(_attr.infos.width);
  for (auto& line: _mapi)
    line.resize(_attr.infos.length);
  for (irr::core::vector2di& tile: wall->pos)
  {
    _mapi[tile.Y][tile.X] = MapTile::BRICK;
  }

  for (irr::core::vector2di &tile: boxes->pos) {
    _mapi[tile.Y][tile.X] = MapTile::BLOCK;
  }
  generateBorders();
  _hasMap = true;
}

bool indie::MapManager::setPlayer(std::shared_ptr<APlayer> player) {
  if (_attr.infos.spawns.size() > 0)
  {
    irr::core::vector2di spawn = _attr.infos.spawns.front();
    _map->addPlayer(player, spawn);
    _attr.infos.spawns.pop_front();
    return (true);
  }
  return (false);
}

std::shared_ptr<indie::Map> indie::MapManager::getMap() {
  return _map;
}

std::shared_ptr<indie::Map> indie::MapManager::create(indie::CollisionManager &collMgr) {
  _map = std::make_unique<Map>(_root->getSceneManager()->addMeshSceneNode(
      _root->getSceneManager()->getGeometryCreator()->
          createPlaneMesh({indie::Map::Tilesize, indie::Map::Tilesize },
			  {_attr.infos.width, _attr.infos.length}, 0,
			  {static_cast<irr::f32>(_attr.infos.width), static_cast<irr::f32>(_attr.infos.length)})),
			       _attr.infos.width, _attr.infos.length);

  _map->setTexture(Engine::get().getRessourceManager().getTexture("Grass"));

  collMgr.setWorld(_map->getCollisionTriangle());
  std::shared_ptr<ACube> entity(nullptr);
  irr::u32 posY = 0;
  for (auto& line : _mapi) {
    irr::u32 posX = 0;
    for (MapTile cellType : line) {
      entity.reset();
      switch (cellType) {
        case MapTile::BRICK:
          entity = std::make_shared<Brick>(_root->getSceneManager());
          entity->setTexture(_brickT);
          break;
        case MapTile::BLOCK:
          entity = std::make_shared<Box>(_root->getSceneManager());
          entity->setTexture(_boxT);
          break;
        default: break;
      }
      if (entity) {
        _map->addEntity(entity, {static_cast<irr::s32>(posX),
                                 static_cast<irr::s32>(posY)});
        collMgr.addTerrain(entity.get());
      }
      ++posX;
    }
    ++posY;
  }
  return _map;
}

void indie::MapManager::generateBorders() {
  uint64_t iteratorY = 0;
  for (auto &line : _mapi) {
    uint64_t iteratorX = 0;
    for (auto &cell : line) {
      if (isBorder(iteratorX, iteratorY))
        cell = MapTile::BRICK;
      iteratorX += 1;
    }
    iteratorY += 1;
  }
}
