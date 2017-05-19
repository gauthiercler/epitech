/*
** SFML.cpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/sfml/sources/SFML.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sun Mar 19 20:29:02 2017 Vincent DUSAUTOIR
** Last update Sun Mar 19 20:29:02 2017 Vincent DUSAUTOIR
*/

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include "Error.hpp"
#include <iostream>
#include "Sfml.hpp"

arcade::Sfml::Sfml() : _window(NULL)
{

}

arcade::Sfml::~Sfml() {

}

bool	arcade::Sfml::openWindow(const std::string &name, uint64_t width, uint64_t height) {

  if (this->_window)
    delete this->_window;
  this->_window = new sf::RenderWindow(sf::VideoMode(width, height), name, sf::Style::Close);
  this->_window->setFramerateLimit(60);
  return true;
}

void arcade::Sfml::closeWindow() {
  for (auto frame : this->_frames)
    delete frame.second;
  this->_window->close();
  delete _window;
}

arcade::IFrame &arcade::Sfml::addFrame(const arcade::pos &positions, uint64_t width, uint64_t height, uint64_t depth) {
  SfmlFrame *frame;

  frame = new SfmlFrame(positions, width, height, this->_frames.size());
  this->_frames.push_back({depth, frame});
  std::sort(this->_frames.begin(), this->_frames.end(),
	    [](std::pair<uint64_t, arcade::SfmlFrame *> first, std::pair<uint64_t, arcade::SfmlFrame *> second){ return second.first < first.first; });
  return *frame;
}

arcade::IPicture *arcade::Sfml::loadPicture(const std::string &path) const {
  SfmlPicture	*picture = new SfmlPicture();
  if (!picture->load(path))
    throw arcade::Error("Problem load picture : " + path);
  return picture;
}

arcade::ISprite *arcade::Sfml::loadSprite(const std::string &path) const {
  SfmlSprite *sprite = new SfmlSprite();

  if (!sprite->load(path))
    throw arcade::Error("Problem load sprite : " + path);
  return sprite;
}

bool arcade::Sfml::display() {
  if (this->_window->isOpen())
  {
    this->_window->clear();
    for (auto it : this->_frames)
      this->_window->draw(it.second->getSprite());
    this->_window->display();
  }
  return true;
}

const arcade::IEvent &arcade::Sfml::getEvent(bool blocking) {
  sf::Event	*event = new sf::Event();
  bool		available = false;

  if (this->_window->isOpen())
  {
    if (blocking)
    {
      this->_window->waitEvent(*event);
      available = true;
    }
    else
    {
      available = this->_window->pollEvent(*event);
    }
    if (available)
      this->_event.setSfmlEvent(*event);
  }
  delete event;
  return this->_event;
}

void arcade::Sfml::resetStackEvents() {
  sf::Event	event;
  while (this->_window->pollEvent(event));
}

arcade::ISound *arcade::Sfml::loadSound(const std::string &path) const {
  SfmlSound	*sound;

  sound = new SfmlSound;
  sound->load(path);
  return (sound);
}

void arcade::Sfml::deleteFrame(uint64_t id) {
  std::vector<std::pair<uint64_t, SfmlFrame *>>::iterator it;

  it = this->_frames.begin();
  while (it != this->_frames.end())
  {
    if (it->second->getId() == id)
    {
      delete it->second;
      it = this->_frames.erase(it);
    }
    else
      ++it;
  }
}

extern "C" arcade::IGraphic *createGraphic() {
  return new arcade::Sfml();
}
