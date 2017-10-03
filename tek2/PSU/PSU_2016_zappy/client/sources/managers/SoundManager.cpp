/*
** SoundManager.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/managers/SoundManager.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 29 10:41:24 2017 Vincent DUSAUTOIR
** Last update Thu Jun 29 10:41:24 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include <utils/Error.hpp>
#include "managers/SoundManager.hpp"

zappy::SoundManager::SoundManager() {
  this->load();
}

zappy::SoundManager::~SoundManager() {

}

void zappy::SoundManager::load(void) {
  this->loadSound("assets/sounds/menu.wav", "menu");
  this->loadSound("assets/sounds/select.wav", "select");
  this->loadSound("assets/sounds/up.wav", "up");
  this->loadSound("assets/sounds/down.wav", "down");
  this->loadSound("assets/sounds/incantation.wav", "incantation");
  this->loadSound("assets/sounds/broadcast.wav", "broadcast");
  this->loadSound("assets/sounds/teleport.wav", "teleport");

  this->setSoundVolume("menu", 10);
}

void zappy::SoundManager::loadSound(std::string const &path,
				    std::string const &name) {
  bufferPtr	buffer = std::make_shared<sf::SoundBuffer>(sf::SoundBuffer());
  soundPtr	sound = std::make_shared<sf::Sound>(sf::Sound());
  std::pair<bufferPtr, soundPtr> pair;

  if (!buffer->loadFromFile(path)) {
    throw SoundError("Couldn't load " + path + ".");
  }
  std::clog << "Sound loaded \"" << path << "\"" << std::endl;
  sound->setBuffer(*buffer);
  pair.first = buffer;
  pair.second = sound;
  this->_sounds.insert( {name, pair} );
}

void zappy::SoundManager::playSound(std::string const &name) {
  auto		sound = this->_sounds.at(name).second;

  sound->play();
}

void zappy::SoundManager::pauseSound(std::string const &name) {
  this->_sounds.at(name).second->pause();
}

void zappy::SoundManager::stopSound(std::string const &name) {
  this->_sounds.at(name).second->stop();
}

void zappy::SoundManager::resetSound(std::string const &name) {
  this->stopSound(name);
  this->playSound(name);
}

void zappy::SoundManager::enableSoundLoop(std::string const &name) {
  this->_sounds.at(name).second->setLoop(true);
}

void zappy::SoundManager::disableSoundLoop(std::string const &name) {
  this->_sounds.at(name).second->setLoop(false);
}

void zappy::SoundManager::setSoundVolume(std::string const &name, float volume) {
  this->_sounds.at(name).second->setVolume(volume);
}

void zappy::SoundManager::switchGlobalVolume(void) {
  float		volume;

  volume = sf::Listener::getGlobalVolume();
  volume ? sf::Listener::setGlobalVolume(0) : sf::Listener::setGlobalVolume(100);
}

float zappy::SoundManager::getGlobalVolume(void) {
  return sf::Listener::getGlobalVolume();
}
