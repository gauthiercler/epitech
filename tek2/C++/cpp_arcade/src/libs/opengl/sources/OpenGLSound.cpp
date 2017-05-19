/*
** OpenGLSound.cpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/libs/opengl/OpenGLSound.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Mar 19 18:58:42 2017 Gauthier Cler
** Last update Sun Mar 19 18:58:43 2017 Gauthier Cler
*/

#include <Error.hpp>
#include "OpenGLSound.hpp"

arcade::OpenGLSound::OpenGLSound() {

}

arcade::OpenGLSound::~OpenGLSound() {

}

void arcade::OpenGLSound::load(const std::string &name) {
  sf::SoundBuffer	audioBuffer;

  if (!audioBuffer.loadFromFile(name))
    throw Error("Can't find file " + name);
  this->_player.setBuffer(audioBuffer);
}

void arcade::OpenGLSound::play() {
  this->_player.play();
}

void arcade::OpenGLSound::pause() {
  this->_player.pause();
}

void arcade::OpenGLSound::replay() {
  this->_player.stop();
  this->play();
}

void arcade::OpenGLSound::loop() {
  this->_player.stop();
  this->_player.setLoop(true);
  this->play();
}
