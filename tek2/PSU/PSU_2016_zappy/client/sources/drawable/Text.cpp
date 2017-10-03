/*
** Text.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/drawable/Text.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed Jun 21 09:14:24 2017 Vincent DUSAUTOIR
** Last update Wed Jun 21 09:14:25 2017 Vincent DUSAUTOIR
*/

#include <managers/Engine.hpp>
#include "drawable/Text.hpp"

zappy::Text::Text() : _centered(false), _fontSize(18), _fontName("roboto") {

}

zappy::Text::~Text() {

}

void zappy::Text::setCentered(bool centered) {
  this->_centered = centered;
}

void zappy::Text::setString(const std::string &text) {
  this->_text = text;
}

void zappy::Text::setColor(const zappy::Color &color) {
  this->_color = color;
}

void zappy::Text::setPosition(const zappy::Position &pos) {
  this->_pos = pos;
}

void zappy::Text::setFont(const std::string &name, const unsigned int size) {
  this->_fontName = name;
  this->_fontSize = size;
}

sf::Drawable &zappy::Text::get() {
  this->_drawable.setString(this->_text);
  this->_drawable.setFont(*Engine::get().getRessourcesManager().getFont(this->_fontName));
  this->_drawable.setCharacterSize(this->_fontSize);
  this->_drawable.setColor(this->_color.inSfml());
  if (this->_centered)
  {
    this->_drawable.setOrigin(this->_drawable.getLocalBounds().left + this->_drawable.getLocalBounds().width/2.0f,
		    this->_drawable.getLocalBounds().top + this->_drawable.getLocalBounds().height);
  }
  this->_drawable.setPosition(this->_pos.inSfml());
  return this->_drawable;
}

zappy::Text::Text(const std::string &text, const std::string &font,
		  const unsigned int size, bool centered)
  : _centered(centered), _fontSize(size), _fontName(font), _text(text) {

}
