/*
** SoundManager.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/SoundManager.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:06:29 2017 Anthony LECLERC
** Last update jeu. mai 04 15:06:29 2017 Anthony LECLERC
*/

#include <iostream>
#include "managers/SoundManager.hpp"

indie::SoundManager::SoundManager() {
  this->load();
}

indie::SoundManager::~SoundManager() {

}

void indie::SoundManager::load(void) {
  this->loadSound("assets/Sounds/Musics/StageSelect.wav", "StageSelect");
  this->loadSound("assets/Sounds/Musics/Battle.wav", "Battle");
  this->loadSound("assets/Sounds/Musics/SpeedBattle.wav", "SpeedBattle");
  this->loadSound("assets/Sounds/Musics/HurryUp.wav", "HurryUp");
  this->loadSound("assets/Sounds/Musics/Winner.wav", "WinnerMusic");
  this->loadSound("assets/Sounds/Musics/SplashScreen.wav", "SplashSong");
  this->loadSound("assets/Sounds/SFX/se_t1/B_A012B_22K.wav", "Bomberman");
  this->loadSound("assets/Sounds/SFX/select.wav", "Select");
  this->loadSound("assets/Sounds/SFX/confirm.wav", "Confirm");
  this->loadSound("assets/Sounds/SFX/reset.wav", "Reset");
  this->loadSound("assets/Sounds/SFX/se_j1/ITEM_GET.wav", "PowerUp");
  this->loadSound("assets/Sounds/SFX/se_j1/B_A098.wav", "PlayerDeath");
  this->loadSound("assets/Sounds/SFX/se_j1/BOM_SET.wav", "BombSet");
  this->loadSound("assets/Sounds/SFX/se_j1/BOM_11_S.wav", "BombExplode");
  this->loadSound("assets/Sounds/SFX/se_b1/B_A019.wav", "GameStart");
  this->loadSound("assets/Sounds/SFX/se_b1/B_B092.wav", "TimeOver");
  this->loadSound("assets/Sounds/SFX/se_b1/B_A017W.wav", "ThisIsBad");
  this->loadSound("assets/Sounds/SFX/se_b1/B_A010W.wav", "Go");
  this->loadSound("assets/Sounds/SFX/se_b1/B_A011.wav", "Draw");
  this->loadSound("assets/Sounds/SFX/se_b1/B_A034.wav", "Winner");
}

void indie::SoundManager::loadSound(std::string const &path,
				    std::string const &name) {
  bufferPtr	buffer = std::make_shared<sf::SoundBuffer>(sf::SoundBuffer());
  soundPtr	sound = std::make_shared<sf::Sound>(sf::Sound());
  std::pair<bufferPtr, soundPtr> pair;

  if (!buffer->loadFromFile(path)) {
    throw IrrlichtError("Couldn't load " + path + ".");
  }
  sound->setBuffer(*buffer);
  pair.first = buffer;
  pair.second = sound;
  this->_sounds.insert( {name, pair} );
}

void indie::SoundManager::playSound(std::string const &name) {
  auto		sound = this->_sounds.at(name).second;

  sound->play();
}

void indie::SoundManager::pauseSound(std::string const &name) {
  this->_sounds.at(name).second->pause();
}

void indie::SoundManager::stopSound(std::string const &name) {
  this->_sounds.at(name).second->stop();
}

void indie::SoundManager::resetSound(std::string const &name) {
  this->stopSound(name);
  this->playSound(name);
}

void indie::SoundManager::enableSoundLoop(std::string const &name) {
  this->_sounds.at(name).second->setLoop(true);
}

void indie::SoundManager::disableSoundLoop(std::string const &name) {
  this->_sounds.at(name).second->setLoop(false);
}

void indie::SoundManager::setSoundVolume(std::string const &name, float volume) {
  this->_sounds.at(name).second->setVolume(volume);
}

void indie::SoundManager::switchGlobalVolume(void) {
  float		volume;

  volume = sf::Listener::getGlobalVolume();
  volume ? sf::Listener::setGlobalVolume(0) : sf::Listener::setGlobalVolume(100);
}

float indie::SoundManager::getGlobalVolume(void) {
  return sf::Listener::getGlobalVolume();
}
