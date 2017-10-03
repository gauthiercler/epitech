/*
** RessourcesManager.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/managers/RessourcesManager.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 17:45:23 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 17:45:23 2017 Vincent DUSAUTOIR
*/

#include <utils/Error.hpp>
#include <utils/Random.hpp>
#include <iostream>
#include "managers/RessourcesManager.hpp"

zappy::RessourcesManager::RessourcesManager() {
  this->_floors.push_back({10, "buisson"});
  this->_floors.push_back({15, "grassflowers"});
  this->_floors.push_back({15, "grassflowers2"});
  this->_floors.push_back({5, "dirt"});
  this->_floors.push_back({55, "grass"});
  this->load();
}

zappy::RessourcesManager::~RessourcesManager() {

}

void zappy::RessourcesManager::load() {
  //Tiles
  this->loadTexture("assets/tiles/grass.png", "grass");
  this->loadTexture("assets/tiles/buisson.png", "buisson");
  this->loadTexture("assets/tiles/grasswithflowers.png", "grassflowers");
  this->loadTexture("assets/tiles/grasswithflowers2.png", "grassflowers2");
  this->loadTexture("assets/tiles/dirt.png", "dirt");

  //Materials
  this->loadTexture("assets/tiles/food.png", "apple");
  this->loadTexture("assets/tiles/newlinemate.png", "linemate");
  this->loadTexture("assets/tiles/newderaumere.png", "deraumere");
  this->loadTexture("assets/tiles/newmendiane.png", "mendiane");
  this->loadTexture("assets/tiles/newphiras.png", "phiras");
  this->loadTexture("assets/tiles/newsibur.png", "sibur");
  this->loadTexture("assets/tiles/newthystame.png", "thystame");

  //Incantations
  this->loadTexture("assets/tiles/incan1.png", "incantation1");
  this->loadTexture("assets/tiles/incan2.png", "incantation2");
  this->loadTexture("assets/tiles/incan3.png", "incantation3");
  this->loadTexture("assets/tiles/incan4.png", "incantation4");
  this->loadTexture("assets/tiles/incan5.png", "incantation5");
  this->loadTexture("assets/tiles/incan6.png", "incantation6");
  this->loadTexture("assets/tiles/incan7.png", "incantation7");
  this->loadTexture("assets/tiles/incan8.png", "incantation8");

  //Sprites
  this->loadTexture("assets/sprites/player.png", "player");
  this->loadTexture("assets/sprites/egg.png", "egg");
  this->loadTexture("assets/tiles/broadcast.png", "broadcast");

  // LOAD FONTS
  this->loadFont("assets/fonts/roboto.ttf", "roboto");
  this->loadFont("assets/fonts/pixeled.ttf", "pixeled");

  // Image
  this->loadTexture("assets/tiles/help.png", "help");
}

void zappy::RessourcesManager::loadFont(const std::string &path,
					const std::string &name) {
  auto font = std::make_shared<sf::Font>();

  if (!font->loadFromFile(path)) {
    throw zappy::RessourcesManagerError("Couldn't load font path " + path + ".");
  }
  std::clog << "Font loaded \"" << path << "\"" << std::endl;
  this->_fonts.insert({name, font});
}

std::shared_ptr<sf::Font> zappy::RessourcesManager::getFont(const std::string &name) {
  return this->_fonts.at(name);
}

void zappy::RessourcesManager::loadTexture(const std::string &path,
					 const std::string &name) {
  auto image = std::make_shared<sf::Texture>();

  if (!image->loadFromFile(path)) {
    throw zappy::RessourcesManagerError("Couldn't load image path " + path + ".");
  }
  std::clog << "Texture loaded \"" << path << "\"" << std::endl;
  this->_textures.insert({name, image});
}

std::shared_ptr<sf::Texture> zappy::RessourcesManager::getTexture(const std::string &name) {
  return this->_textures.at(name);
}

std::string zappy::RessourcesManager::getRandomFloor() {
  double		percent;
  double		percentTotal;

  percent = Random::get().generate() % 100 + 1;
  percentTotal = 0;
  for (auto floor : this->_floors) {
    percentTotal += floor.first;
    if (percentTotal >= percent)
      return floor.second;
  }
  return "grass";
}
