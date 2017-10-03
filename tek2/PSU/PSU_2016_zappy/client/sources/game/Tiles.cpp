/*
** Tiles.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/game/Tiles.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 22 08:59:00 2017 Vincent DUSAUTOIR
** Last update Thu Jun 22 08:59:00 2017 Vincent DUSAUTOIR
*/

#include <managers/Engine.hpp>
#include <iostream>
#include <utils/Random.hpp>
#include <drawable/Rect.hpp>
#include "game/Tiles.hpp"

zappy::Tiles::Tiles(const Position &position) : _pos(position), _sprite(Engine::get().getRessourcesManager().getRandomFloor(), Size(32, 32)), _display(false) {
  this->_food.setPosition(this->_pos);
  this->_linemate.setPosition(this->_pos);
  this->_deraumere.setPosition(this->_pos);
  this->_sibur.setPosition(this->_pos);
  this->_mendiane.setPosition(this->_pos);
  this->_phiras.setPosition(this->_pos);
  this->_thystame.setPosition(this->_pos);

  this->_materials.push_back(std::ref<Material>(this->_food));
  this->_materials.push_back(std::ref<Material>(this->_linemate));
  this->_materials.push_back(std::ref<Material>(this->_deraumere));
  this->_materials.push_back(std::ref<Material>(this->_sibur));
  this->_materials.push_back(std::ref<Material>(this->_mendiane));
  this->_materials.push_back(std::ref<Material>(this->_phiras));
  this->_materials.push_back(std::ref<Material>(this->_thystame));

  this->_last = std::chrono::system_clock::now();
  this->_incantation.setPosition(this->_pos);
}

zappy::Tiles::~Tiles() {

}

void zappy::Tiles::update() {
  this->_sprite.nextSprite();
  for (auto &material : this->_materials) {
    material.get().update();
  }
  if (this->_incantation.isActive())
    this->_incantation.update();
}

void zappy::Tiles::render(const Position &offset, const Size &scale) {
  Rect		selected(Size(32 * scale.width, 32 * scale.length), Position(0,0), Color(22, 160, 133, 80));

  this->_sprite.setScale(scale);
  this->_sprite.setPosition(Position(this->_pos.x * this->_sprite.getSize().width * scale.width + offset.x, this->_pos.y * this->_sprite.getSize().length * scale.length + offset.y));
  Engine::get().getWindowManager().draw(this->_sprite);
  if (this->_incantation.isActive())
    this->_incantation.render(offset, scale);
  for (auto &material : this->_materials) {
    if (material.get().available())
      material.get().render(offset, scale);
  }
  if (this->_display)
  {
    selected.setPosition(Position(this->_pos.x * selected.getSize().width + offset.x, this->_pos.y * selected.getSize().length + offset.y));
    Engine::get().getWindowManager().draw(selected);
  }
}

void zappy::Tiles::setDisplay(bool display) {
  this->_display = display;
}

void zappy::Tiles::renderMaterial() {
  size_t	size = static_cast<size_t>(std::count_if(this->_materials.begin(), this->_materials.end(), [](std::reference_wrapper<Material> &material){
    return (material.get().available());
  }));

  if (this->_display && size > 0) {
    Rect		rect(Size(300, 45 + (size - 1) * 29), Position(0,0), Color(22, 160, 133, 200));
    Position		offset(0, 0);
    Size		scale(0, 0);

    Engine::get().getWindowManager().draw(rect);
    size = 0;
    for (auto &material : this->_materials) {
      if (material.get().available())
	material.get().render(size++);
    }
  }
}

void zappy::Tiles::renderSelected() {
  this->renderMaterial();
  if (this->_incantation.isActive())
    this->_incantation.renderSelected();
  Rect		rect(Size(120, 30), Position(0,Engine::get().getWindowSize().length - 30), Color(22, 160, 133, 170));
  Text		text(std::to_string(static_cast<int>(this->_pos.x)) + ";" + std::to_string(static_cast<int>(this->_pos.y)), "pixeled", 14, true);

  text.setPosition(Position(60, Engine::get().getWindowSize().length - 9));
  text.setColor(Color(236, 240, 241));
  Engine::get().getWindowManager().draw(rect);
  Engine::get().getWindowManager().draw(text);
}

void zappy::Tiles::setMaterials(size_t food, size_t linemate, size_t deraumere,
				size_t sibur, size_t mendiane, size_t phiras,
				size_t thystame) {
  this->_food.setMaterial(food);
  this->_linemate.setMaterial(linemate);
  this->_deraumere.setMaterial(deraumere);
  this->_sibur.setMaterial(sibur);
  this->_mendiane.setMaterial(mendiane);
  this->_phiras.setMaterial(phiras);
  this->_thystame.setMaterial(thystame);
}

void zappy::Tiles::setIncantation(size_t level) {
  this->_incantation.setActive(true);
  this->_incantation.setLevel(level);
}

void zappy::Tiles::endIncantation(bool) {
  this->_incantation.setActive(false);
}
