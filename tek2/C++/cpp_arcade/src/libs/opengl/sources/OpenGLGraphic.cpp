/*
** OpenGLGraphic.cpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/libs/OpenGLGraphic/OpenGLGraphic.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Mar 19 17:31:57 2017 Gauthier Cler
// Last update Sat Mar 25 23:30:56 2017 Gauthier Cler
*/

#include <GL/gl.h>
#include <stdexcept>
#include <Error.hpp>
#include <memory>
#include <OpenGLSprite.hpp>
#include "OpenGLGraphic.hpp"
#include "OpenGLSound.hpp"

arcade::OpenGLGraphic::OpenGLGraphic() : _window(NULL){
}

arcade::OpenGLGraphic::~OpenGLGraphic() {

}

bool arcade::OpenGLGraphic::openWindow(const std::string &name, uint64_t width,
				       uint64_t height) {
  if (this->_window) {
    delete this->_window;
  }
  this->_window = new sf::RenderWindow(sf::VideoMode(width, height), name, sf::Style::Close);
  this->_window->setFramerateLimit(60);

  return true;
}

void arcade::OpenGLGraphic::closeWindow() {
  this->_window->close();
  delete this->_window;
}

arcade::IFrame &
arcade::OpenGLGraphic::addFrame(const arcade::pos &positions, uint64_t width,
				uint64_t height, uint64_t depth) {
  OpenGLFrame *frame;

  frame = new OpenGLFrame(positions, width, height, this->_framesMap.size());
  this->_framesMap.push_back({depth, frame});
  std::sort(this->_framesMap.begin(), this->_framesMap.end(),
	    [](std::pair<uint64_t, arcade::OpenGLFrame *> first, std::pair<uint64_t, arcade::OpenGLFrame *> second){ return second.first < first.first; });
  return *frame;
}

arcade::IPicture *
arcade::OpenGLGraphic::loadPicture(const std::string &path) const {
  IPicture		*picture = new OpenGLPicture();

  if (!picture->load(path))
    throw Error("File " + path + " does not exist");
  return picture;
}

arcade::ISprite *
arcade::OpenGLGraphic::loadSprite(const std::string &path) const {
  OpenGLSprite *sprite = new OpenGLSprite();

  if (!sprite->load(path))
    throw arcade::Error("Problem load sprite : " + path);
  return sprite;
}

bool arcade::OpenGLGraphic::display() {
  this->_window->clear();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for (auto it : this->_framesMap)
  {
    this->_window->pushGLStates();
    this->_window->draw(it.second->getSprite());
    this->_window->popGLStates();
  }
  this->_window->display();
  return true;
}

const arcade::IEvent &arcade::OpenGLGraphic::getEvent(bool blocking) {
  sf::Event	*event = new sf::Event();
  bool available = false;

  if (this->_window->isOpen())
  {
    if (blocking)
    {
      this->_window->waitEvent(*event);
      available = true;
    }
    else
      available = this->_window->pollEvent(*event);
    if (available)
      this->_event.setSfmlEvent(*event);
  }
  delete event;
  return this->_event;
}

void arcade::OpenGLGraphic::resetStackEvents() {
  sf::Event	event;

  while (this->_window->pollEvent(event));
}

arcade::ISound *
arcade::OpenGLGraphic::loadSound(const std::string &path) const {
  ISound	*sound = new OpenGLSound;
  sound->load(path);
  return sound;
}

void arcade::OpenGLGraphic::deleteFrame(uint64_t id) {
  std::vector<std::pair<uint64_t, OpenGLFrame *>>::iterator it;

  it = this->_framesMap.begin();
  while (it != this->_framesMap.end())
  {
    if (it->second->getId() == id)
    {
      delete it->second;
      it = this->_framesMap.erase(it);
    }
    else
      ++it;
  }
}

extern "C" arcade::IGraphic *createGraphic() {
  return new arcade::OpenGLGraphic();
}