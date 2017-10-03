/*
** Map.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/game/Map.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 22 08:58:57 2017 Vincent DUSAUTOIR
** Last update Thu Jun 22 08:58:57 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include <drawable/Rect.hpp>
#include <managers/Engine.hpp>
#include <cmath>
#include "game/Map.hpp"

zappy::Map::Map(const zappy::Size &size) : _size(size), _scale(3, 3), _generated(false) {
  this->generate();
}

zappy::Map::~Map() {

}

void zappy::Map::update(const Position &mousePos, bool pressed) {
  this->_mousePos = this->getPosition(mousePos);
  this->_mousePress = pressed;
}

void zappy::Map::generate() {
  Position	pos(0, 0);

  while (pos.x != this->_size.width)
  {
    pos.y = 0;
    while (pos.y != this->_size.length)
    {
      this->_tiles.push_back({pos, std::make_shared<Tiles>(pos)});
      pos.y++;
    }
    pos.x++;
  }
  this->_generated = true;
}

void zappy::Map::render() {
  for (auto &tile : this->_tiles) {
    tile.second->render(this->_offset, this->_scale);
  }
  for (auto &player : this->_players) {
    player->render(this->_offset, this->_scale);
  }
  for (auto &egg : this->_eggs) {
    egg->render(this->_offset, this->_scale);
  }
  this->renderMouse();
  this->_chat.render();
}

void zappy::Map::move(const zappy::Position &pos) {
  this->_offset.y += pos.y * this->_scale.width;
  this->_offset.x += pos.x * this->_scale.length;
}

void zappy::Map::moveLeft() {
  this->move(Position(5, 0));
}

void zappy::Map::moveRight() {
  this->move(Position(-5, 0));
}

void zappy::Map::moveUp() {
  this->move(Position(0, 5));
}

void zappy::Map::moveDown() {
  this->move(Position(0, -5));
}

zappy::Position zappy::Map::getPosition(const zappy::Position &pos) {
  Position	mapPos(pos.x, pos.y);

  mapPos.x -= this->_offset.x;
  mapPos.y -= this->_offset.y;
  mapPos.x /= 32 * this->_scale.width;
  mapPos.y /= 32 * this->_scale.length;
  mapPos.x = std::floor(mapPos.x);
  mapPos.y = std::floor(mapPos.y);
  return mapPos;
}

void zappy::Map::renderMouse() {
  Rect		mouse(Size(32 * this->_scale.width, 32 * this->_scale.length));

  mouse.setPosition(Position(this->_mousePos.x * 32 * this->_scale.width + this->_offset.x, this->_mousePos.y * 32 * this->_scale.length + this->_offset.y));
  if (this->_mousePos.x < 0 || this->_mousePos.x >= this->_size.width || this->_mousePos.y < 0 || this->_mousePos.y >= this->_size.length)
    mouse.setColor(Color(255,0,0, ((this->_mousePress) ? 130 : 80)));
  else
    mouse.setColor(Color(255,255,255,((this->_mousePress) ? 130 : 80)));
  Engine::get().getWindowManager().draw(mouse);
}

zappy::Tiles *zappy::Map::getTileAtPos(const Position &pos, bool mousepos) {
  Position mapPos;

  if (mousepos)
    mapPos = this->getPosition(pos);
  else
    mapPos = pos;
  auto find = std::find_if(this->_tiles.begin(), this->_tiles.end(), [mapPos](const std::pair<Position, std::shared_ptr<Tiles>> &element){
    return (element.first == mapPos);
  });
  if (find != this->_tiles.end())
    return find->second.get();
  return nullptr;
}

void zappy::Map::addScale() {
  if (this->_scale.width <= 10 && this->_scale.length <= 10) {
    this->_scale.width += 1;
    this->_scale.length += 1;
  }
}

void zappy::Map::removeScale() {
  if (this->_scale.width > 1 && this->_scale.length > 1) {
    this->_scale.width -= 1;
    this->_scale.length -= 1;
  }
}

void zappy::Map::addPlayer(size_t id, const Position &pos, Orientation orientation, size_t level, const std::string &teamName) {
  if (this->isInMap(pos))
    this->_players.push_back(std::make_shared<Player>(id, pos, orientation, level, teamName));
}

void zappy::Map::addEgg(size_t id, const zappy::Position &pos, const std::string &teamName) {
  if (this->isInMap(pos))
    this->_eggs.push_back(std::make_shared<Egg>(id, pos, teamName));
}

bool zappy::Map::isInMap(const zappy::Position &pos) {
  return (pos.x >= 0 && pos.x < this->_size.width && pos.y >= 0 && pos.y < this->_size.length);
}

std::vector<std::shared_ptr<zappy::Player>> zappy::Map::getPlayersAtPos(const zappy::Position &pos) {
  std::vector<std::shared_ptr<zappy::Player>> players;
  Position					mapPos;

  mapPos = this->getPosition(pos);
  for (auto &player : this->_players) {
    if (player->getPos() == mapPos)
      players.push_back(player);
  }
  return players;
}

zappy::Map::Map() : _size(0, 0), _scale(3, 3), _generated(false) {

}void zappy::Map::setSize(const zappy::Size &size) {
  this->_size = size;
}

void zappy::Map::reset() {
  this->_players.clear();
  this->_tiles.clear();
  this->_eggs.clear();
  this->_chat.reset();
  this->resetOffset();
  this->resetScale();
  this->_generated = false;
}

bool zappy::Map::isGenerated() {
  return this->_generated;
}

zappy::Player *zappy::Map::getPlayerById(size_t id) {
  auto find = std::find_if(this->_players.begin(), this->_players.end(), [id](const std::shared_ptr<Player> &element){
    return (element->getId() == id);
  });

  return (find == this->_players.end()) ? nullptr : find->get();
}

zappy::Egg *zappy::Map::getEggById(size_t id) {
  auto find = std::find_if(this->_eggs.begin(), this->_eggs.end(), [id](const std::shared_ptr<Egg> &element){
    return (element->getId() == id);
  });

  return (find == this->_eggs.end()) ? nullptr : find->get();
}

void zappy::Map::removePlayer(size_t id) {
  this->_players.erase(std::remove_if(this->_players.begin(), this->_players.end(), [id](const std::shared_ptr<Player> &element){
    return element.get()->getId() == id;
  }), this->_players.end());
}

void zappy::Map::removeEgg(size_t id) {
  this->_eggs.erase(std::remove_if(this->_eggs.begin(), this->_eggs.end(), [id](const std::shared_ptr<Egg> &element){
    return element.get()->getId() == id;
  }), this->_eggs.end());
}

void zappy::Map::setTileContent(const zappy::Parser &parser) {
  Position	pos(std::stoi(parser[1]), std::stoi(parser[2]));
  Tiles		*tile = this->getTileAtPos(pos, false);

  if (tile != nullptr)
    tile->setMaterials(std::stoul(parser[3]),
		       std::stoul(parser[4]),
		       std::stoul(parser[5]),
		       std::stoul(parser[6]),
		       std::stoul(parser[7]),
		       std::stoul(parser[8]),
		       std::stoul(parser[9]));
}

void zappy::Map::spawnPlayer(const zappy::Parser &parser) {
  Orientation orientations[4] = {
    Orientation::NORTH,
    Orientation::EAST,
    Orientation::SOUTH,
    Orientation::WEST
  };

  this->addPlayer(std::stoul(parser[1]),
		  Position(std::stoi(parser[2]), std::stoi(parser[3])),
		  orientations[std::stoul(parser[4])],
		  std::stoul(parser[5]),
		  parser[6]);
}


void zappy::Map::changePlayerPosition(const zappy::Parser &parser) {
  Player *player = this->getPlayerById(std::stoul(parser[1]));
  Orientation orientations[4] = {
    Orientation::NORTH,
    Orientation::EAST,
    Orientation::SOUTH,
    Orientation::WEST
  };

  if (player != nullptr)
    player->move(Position(std::stoi(parser[2]), std::stoi(parser[3])), orientations[std::stoul(parser[4])]);
}

void zappy::Map::changePlayerLevel(const zappy::Parser &parser) {
  Player *player = this->getPlayerById(std::stoul(parser[1]));

  if (player != nullptr)
    player->setLevel(std::stoul(parser[2]));
}

void zappy::Map::changePlayerInventory(const zappy::Parser &parser) {
  Player *player = this->getPlayerById(std::stoul(parser[1]));

  if (player != nullptr)
    player->setInventory(std::stoul(parser[2]),
			 std::stoul(parser[3]),
			 std::stoul(parser[4]),
			 std::stoul(parser[5]),
			 std::stoul(parser[6]),
			 std::stoul(parser[7]),
			 std::stoul(parser[8]));
}

void zappy::Map::excludePlayer(const zappy::Parser &parser) {
  this->removePlayer(std::stoul(parser[1]));
}

void zappy::Map::spawnEgg(const zappy::Parser &parser) {
  this->addEgg(std::stoul(parser[1]), Position(std::stoi(parser[2]), std::stoi(parser[3])), parser[4]);
}

void zappy::Map::excludeEgg(const zappy::Parser &parser) {
  this->removeEgg(std::stoul(parser[1]));
}

void zappy::Map::spawnIncantation(const zappy::Parser &parser) {
  Tiles *tile = this->getTileAtPos(Position(std::stoi(parser[1]), std::stoi(parser[2])), false);

  if (tile != nullptr)
    tile->setIncantation(std::stoul(parser[3]));
}

void zappy::Map::endIncantation(const zappy::Parser &parser) {
  Tiles *tile = this->getTileAtPos(Position(std::stoi(parser[1]), std::stoi(parser[2])), false);

  if (tile != nullptr)
    tile->endIncantation((parser[3] == "1"));
}

void zappy::Map::update() {
  this->_chat.update();
  for (auto &tile : this->_tiles) {
    tile.second->update();
  }
  for (auto &player : this->_players) {
    player->update();
  }
  for (auto &egg : this->_eggs) {
    egg->update();
  }
}

void zappy::Map::resetOffset() {
  this->_offset.x = 0;
  this->_offset.y = 0;
}

void zappy::Map::broadcastPlayer(const zappy::Parser &parser) {
  Player *player = this->getPlayerById(std::stoul(parser[1]));

  if (player != nullptr) {
    player->sendBroadcast();
    std::string message;
    const std::vector<std::string> args = parser.getArgs();
    size_t pos;

    pos = 0;
    for (auto &arg : args) {
      if (pos > 1)
	message = ((pos > 2) ? (message + " ") : (message)) + arg;
      pos++;
    }
    this->_chat.addMessage(Message("Player " + std::to_string(player->getId()), message));
  }
}

void zappy::Map::openChat() {
  this->_chat.setActive(!this->_chat.isActive());
}

void zappy::Map::serverMessage(const zappy::Parser &parser) {
  std::string message;
  const std::vector<std::string> args = parser.getArgs();
  size_t pos;

  pos = 0;
  for (auto &arg : args) {
    if (pos > 0)
      message = ((pos > 1) ? (message + " ") : (message)) + arg;
    pos++;
  }
  this->_chat.addMessage(Message("SERVER", message, MessageType::SERVER));
}

void zappy::Map::resetScale() {
  this->_scale.width = 3;
  this->_scale.length = 3;
}
