/*
** SfmlFrame.cpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/sfml/sources/SfmlFrame.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Mar 20 09:11:33 2017 Vincent DUSAUTOIR
** Last update Mon Mar 20 09:11:33 2017 Vincent DUSAUTOIR
*/

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Structures.hpp"
#include "SfmlFrame.hpp"

arcade::SfmlFrame::SfmlFrame(const arcade::pos &pos, uint64_t width, uint64_t height, uint64_t id) : _id(id){
  this->_texture.create(width, height);
  this->_pos = pos;
  this->_font.loadFromFile("ressources/font/roboto.ttf");
}

arcade::SfmlFrame::~SfmlFrame() {

}

bool arcade::SfmlFrame::draw(const arcade::pos &pos, const arcade::IPicture &picture)
{
  const SfmlPicture &sfPicture = static_cast<const SfmlPicture &>(picture);
  sf::Sprite sprite;

  sprite = sfPicture.getSprite();
  sprite.setPosition(sf::Vector2f(pos.x, pos.y));
  this->_texture.draw(sprite);
  return true;
}

bool arcade::SfmlFrame::draw(const arcade::pos &pos, const arcade::rectangle &rectangle) {
  sf::RectangleShape rect(sf::Vector2f(rectangle.size.x, rectangle.size.y));

  rect.setPosition(sf::Vector2f(pos.x, pos.y));
  if (rectangle.full)
    rect.setFillColor(sf::Color(rectangle.color.argb[1],
				rectangle.color.argb[2],
				rectangle.color.argb[3],
				rectangle.color.argb[0]));
  else
    rect.setFillColor(sf::Color(rectangle.color.argb[1],
				rectangle.color.argb[2],
				rectangle.color.argb[3], 0));
  rect.setOutlineThickness(rectangle.thickness);
  rect.setOutlineColor(sf::Color(rectangle.color.argb[1],
				 rectangle.color.argb[2],
				 rectangle.color.argb[3],
				 rectangle.color.argb[0]));
  rect.setRotation(rectangle.rotate);
  this->_texture.draw(rect);
  return true;
}

bool arcade::SfmlFrame::draw(const arcade::pos &pos, const std::string &str, const arcade::text &text) {
  sf::Text sfText;

  sfText.setFont(this->_font);
  sfText.setPosition(pos.x, pos.y);
  sfText.setString(str);
  sfText.setCharacterSize(text.fontSize);
  sfText.setColor(sf::Color(text.color.argb[1],
			    text.color.argb[2],
			    text.color.argb[3],
			    text.color.argb[0]));
  sfText.setRotation(text.rotate);
  this->_texture.draw(sfText);
  return true;
}

bool arcade::SfmlFrame::draw(const arcade::rgb &color) {
  sf::Color sfColor(color.argb[1], color.argb[2], color.argb[3], color.argb[0]);
  this->_texture.clear(sfColor);
  return true;
}

sf::Sprite arcade::SfmlFrame::getSprite() const {
  const_cast<sf::RenderTexture &>(this->_texture).display();
  const sf::Texture &texture = this->_texture.getTexture();
  sf::Sprite sprite(texture);
  sprite.setPosition(this->_pos.x, this->_pos.y);
  sprite.setOrigin(0, 0);
  return sprite;
}

bool arcade::SfmlFrame::draw(const arcade::pos &pos, const arcade::circle &circle) {
  sf::CircleShape	sfCircle(circle.radius);

  sfCircle.setPosition(pos.x - circle.radius, pos.y - circle.radius);
  if (circle.full)
    sfCircle.setFillColor(sf::Color(circle.color.argb[1],
				    circle.color.argb[2],
				    circle.color.argb[3],
				    circle.color.argb[0]));
  else
    sfCircle.setFillColor(sf::Color(circle.color.argb[1],
				    circle.color.argb[2],
				    circle.color.argb[3], 0));
  sfCircle.setOutlineThickness(circle.thickness);
  sfCircle.setOutlineColor(sf::Color(circle.color.argb[1],
				     circle.color.argb[2],
				     circle.color.argb[3],
				     circle.color.argb[0]));
  this->_texture.draw(sfCircle);
  return true;
}

bool arcade::SfmlFrame::draw(const arcade::pos &start, const arcade::pos &end, const arcade::rgb &color, uint64_t thickness) {
  sf::ConvexShape line;
  line.setPointCount(2);
  line.setPoint(0, sf::Vector2f(start.x, start.y));
  line.setPoint(1, sf::Vector2f(end.x, end.y));
  line.setOutlineThickness(thickness);
  line.setFillColor(sf::Color(color.argb[1], color.argb[2], color.argb[3], color.argb[0]));
  this->_texture.draw(line);
  return true;
}

uint64_t arcade::SfmlFrame::getId() const {
  return this->_id;
}

