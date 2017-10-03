/*
** Inventory.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/game/Inventory.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sat Jun 24 10:11:15 2017 Vincent DUSAUTOIR
** Last update Sat Jun 24 10:11:16 2017 Vincent DUSAUTOIR
*/

#include <managers/Engine.hpp>
#include <utils/Random.hpp>
#include "game/Inventory.hpp"

zappy::Inventory::Inventory() {
  this->_inventory = {
    {MaterialType::FOOD, 0},
    {MaterialType::LINEMATE, 0},
    {MaterialType::DERAUMERE, 0},
    {MaterialType::SIBUR, 0},
    {MaterialType::MENDIANE, 0},
    {MaterialType::PHIRAS, 0},
    {MaterialType::THYSTAME, 0}
  };

  this->_materialSprite = {
    {MaterialType::FOOD, "apple"},
    {MaterialType::LINEMATE, "linemate"},
    {MaterialType::DERAUMERE, "deraumere"},
    {MaterialType::SIBUR, "sibur"},
    {MaterialType::MENDIANE, "mendiane"},
    {MaterialType::PHIRAS, "phiras"},
    {MaterialType::THYSTAME, "thystame"}
  };
}

zappy::Inventory::~Inventory() {

}

void zappy::Inventory::setItemValues(zappy::MaterialType type, size_t nbr) {
  this->_inventory[type] = nbr;
}

size_t zappy::Inventory::get(zappy::MaterialType type) {
  return this->_inventory.at(type);
}

void zappy::Inventory::render() {
  size_t size;

  size = 0;
  for (auto &material : this->_materialSprite) {
    Sprite mate(material.second, Size(12, 12));
    Text text(std::to_string(this->_inventory[material.first]));

    text.setFont("pixeled", 22);
    text.setColor(Color(42, 62, 80));
    mate.setScale(Size(2, 2));
    mate.setPosition(Position(1180 + 130 * (size % 2), 315 + 50 * (size / 2)));
    text.setPosition(Position(1210 + 130 * (size % 2), 317 + 50 * (size / 2)));
    Engine::get().getWindowManager().draw(mate);
    Engine::get().getWindowManager().draw(text);
    size++;
  }
}
