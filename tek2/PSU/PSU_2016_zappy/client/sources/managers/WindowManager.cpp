/*
** WindowManager.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/managers/WindowManager.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 10:55:48 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 10:55:48 2017 Vincent DUSAUTOIR
*/

#include <managers/WindowManager.hpp>

zappy::WindowManager::WindowManager(const Size &size, const std::string &name) : _size(size) {
  this->_window.create(sf::VideoMode(static_cast<unsigned int>(size.width),
				     static_cast<unsigned int>(size.length)), name);
}

zappy::WindowManager::~WindowManager() {

}

bool zappy::WindowManager::isOpen() {
  return this->_window.isOpen();
}

sf::RenderWindow &zappy::WindowManager::getWindow() {
  return this->_window;
}

void zappy::WindowManager::close() {
  this->_window.close();
}

void zappy::WindowManager::display() {
  this->_window.display();
}

void zappy::WindowManager::draw(const sf::Drawable &drawable,
				const sf::RenderStates &states) {
  this->_window.draw(drawable, states);
}

void zappy::WindowManager::clear(const sf::Color &color) {
  this->_window.clear(color);
}

const zappy::Size &zappy::WindowManager::getSize() const {
  return this->_size;
}

void zappy::WindowManager::draw(zappy::IDrawable &drawable) {
  this->draw(drawable.get());
}



