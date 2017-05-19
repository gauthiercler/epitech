/*
** SfmlSound.cpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/sfml/sources/SfmlSound.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Apr 03 23:09:15 2017 Vincent DUSAUTOIR
** Last update Mon Apr 03 23:09:15 2017 Vincent DUSAUTOIR
*/

#include <SFML/Audio/SoundBuffer.hpp>
#include "Error.hpp"
#include "SfmlSound.hpp"

arcade::SfmlSound::SfmlSound() {

}

arcade::SfmlSound::~SfmlSound() {

}

void arcade::SfmlSound::load(const std::string &name) {
  sf::SoundBuffer	audioBuffer;

  if (!audioBuffer.loadFromFile(name))
    throw Error("Can't find file " + name);
  this->_player.setBuffer(audioBuffer);
}

void arcade::SfmlSound::play() {
  this->_player.play();
}

void arcade::SfmlSound::pause() {
  this->_player.pause();
}

void arcade::SfmlSound::replay() {
  this->_player.stop();
  this->play();
}

void arcade::SfmlSound::loop() {
  this->_player.stop();
  this->_player.setLoop(true);
  this->play();
}
