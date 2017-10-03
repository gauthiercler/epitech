/*
** Player.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/game/Player.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 22 09:02:41 2017 Vincent DUSAUTOIR
** Last update Thu Jun 22 09:02:41 2017 Vincent DUSAUTOIR
*/

#include <drawable/Rect.hpp>
#include <managers/Engine.hpp>
#include <iostream>
#include "game/Player.hpp"

zappy::Player::Player(size_t id, const Position &pos, Orientation orientation, size_t level, const std::string &teamName)
  : _id(id),
    _pos(pos),
    _orientation(orientation),
    _level(level),
    _teamName(teamName),
    _sprite("player", Size(24, 40)),
    _broadcasting(false) {
  Engine::get().getSoundManager().playSound("up");
}

zappy::Player::~Player() {
  Engine::get().getSoundManager().playSound("down");
}

void zappy::Player::update() {
  this->_sprite.nextSprite();

  if (this->_broadcasting) {
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_last).count() > 500)
      this->_broadcasting = false;
  }
}

void zappy::Player::render(const Position &offset, const Size &scale) {
  this->_sprite.setScale(scale);
  this->_sprite.setPosition(Position(this->_pos.x * 32 * scale.width + offset.x + 4 * scale.width, this->_pos.y * 32 * scale.length + offset.y - 18 * scale.length));
  this->_sprite.setOrientation(static_cast<int>(this->_orientation));
  Engine::get().getWindowManager().draw(this->_sprite);
  if (this->_broadcasting)
  {
    Sprite	broadcast("broadcast", Size(18, 14));
    broadcast.setScale(scale);
    broadcast.setPosition(Position(this->_pos.x * 32 * scale.width + offset.x + 15 * scale.width, this->_pos.y * 32 * scale.length + offset.y - 26 * scale.length));
    Engine::get().getWindowManager().draw(broadcast);
  }
}

void zappy::Player::move(const zappy::Position &position, const Orientation &orientation) {
  this->_pos = position;
  this->_orientation = orientation;
  Engine::get().getSoundManager().playSound("teleport");
}

void zappy::Player::renderSelected(size_t current, size_t total) {
  Rect		rect(Size(300, 520), Position(1140,0), Color(22, 160, 133, 200));
  Text		text("ID " + std::to_string(this->_id), "pixeled", 14);
  Text		pos(std::to_string(current + 1) + "/" + std::to_string(total), "pixeled", 14);
  Text		info;

  Engine::get().getWindowManager().draw(rect);
  text.setPosition(Position(1290, 30));
  text.setColor(Color(255,255,255));
  text.setCentered(true);
  pos.setPosition(Position(1290, 510));
  pos.setColor(Color(255,255,255));
  pos.setCentered(true);
  info.setString("Level " + std::to_string(this->_level));
  info.setFont("pixeled", 18);
  info.setCentered(true);
  info.setColor(Color(42, 62, 80));
  info.setPosition(Position(1290, 220));
  this->_sprite.setPosition(Position(1244, 30));
  this->_sprite.setOrientation(static_cast<int>(Orientation::SOUTH));
  this->_sprite.setScale(Size(4, 4));
  Engine::get().getWindowManager().draw(info);
  info.setString("(" + std::to_string(static_cast<size_t>(this->_pos.x)) + ";" + std::to_string(static_cast<size_t>(this->_pos.y)) + ")");
  info.setPosition(Position(1290, 250));
  Engine::get().getWindowManager().draw(info);
  info.setString(this->_teamName);
  info.setPosition(Position(1290, 280));
  Engine::get().getWindowManager().draw(info);
  Engine::get().getWindowManager().draw(text);
  Engine::get().getWindowManager().draw(pos);
  Engine::get().getWindowManager().draw(this->_sprite);
  this->_inventory.render();
}

const zappy::Position &zappy::Player::getPos() const {
  return this->_pos;
}

const size_t &zappy::Player::getId() const {
  return this->_id;
}

void zappy::Player::setLevel(size_t level) {
  this->_level = level;
}

void zappy::Player::setInventory(size_t food, size_t linemate, size_t deraumere,
				 size_t sibur, size_t mendiane, size_t phiras,
				 size_t thystame) {
  this->_inventory.setItemValues(MaterialType::FOOD, food);
  this->_inventory.setItemValues(MaterialType::LINEMATE, linemate);
  this->_inventory.setItemValues(MaterialType::DERAUMERE, deraumere);
  this->_inventory.setItemValues(MaterialType::SIBUR, sibur);
  this->_inventory.setItemValues(MaterialType::MENDIANE, mendiane);
  this->_inventory.setItemValues(MaterialType::PHIRAS, phiras);
  this->_inventory.setItemValues(MaterialType::THYSTAME, thystame);
}

void zappy::Player::sendBroadcast() {
  this->_last = std::chrono::system_clock::now();
  this->_broadcasting = true;
}
