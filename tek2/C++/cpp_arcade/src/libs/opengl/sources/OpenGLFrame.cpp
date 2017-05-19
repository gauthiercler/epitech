/*
** OpenGLFrame.cpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/libs/opengl/OpenGLFrame.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Mar 19 18:58:23 2017 Gauthier Cler
** Last update Sun Mar 19 18:58:23 2017 Gauthier Cler
*/

#include <GL/gl.h>
#include <iostream>
#include <GL/glu.h>
#include <SFML/Graphics/Text.hpp>
#include <Error.hpp>
#include "OpenGLFrame.hpp"
#include "OpenGLPicture.hpp"

arcade::OpenGLFrame::OpenGLFrame(const arcade::pos &positions, uint64_t width,
				 uint64_t height, uint64_t id) :
  _pos(positions) , _id(id){
  this->_texture.create(width, height);
  sf::Texture::bind(&this->_texture.getTexture());
  this->_texture.draw(sf::Sprite(this->_texture.getTexture()));
  sf::Texture::bind(NULL);
  if (!this->_font.loadFromFile("ressources/font/roboto.ttf"))
    throw arcade::Error("Can't load font.");
}

arcade::OpenGLFrame::~OpenGLFrame() {

}

bool arcade::OpenGLFrame::draw(const arcade::pos &pos,
			       const arcade::IPicture &picture) {

  //Working Picture Draw but removed cause of weird behavior
/*  sf::Texture	texture = static_cast<const OpenGLPicture&>(picture).getImage();

  sf::Texture::bind(&texture, sf::Texture::CoordinateType::Pixels);
  glPushMatrix();
  glRotatef(picture.getRotate(), 0, 0, 1);
  glScalef(picture.getXScale(), picture.getYScale(), 1);
  glMatrixMode(GL_MODELVIEW);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex2f(pos.x, pos.y);
  glTexCoord2f(picture.getSize().x, 0);
  glVertex2f(pos.x + texture.getSize().x, pos.y);
  glTexCoord2f(picture.getSize().x, picture.getSize().y);
  glVertex2f(pos.x + texture.getSize().x, pos.y + texture.getSize().y);
  glTexCoord2f(0, picture.getSize().y);
  glVertex2f(pos.x, pos.y + texture.getSize().y);
  glEnd();
  glPopMatrix();
  sf::Texture::bind(NULL);*/

  this->draw(pos, rectangle(picture.getSize(), picture.getColor()));

  return true;
}

bool arcade::OpenGLFrame::draw(const arcade::pos &pos,
			       const arcade::rectangle &rectangle) {

  sf::Texture::bind(&this->_texture.getTexture());
  this->_texture.draw(sf::Sprite(this->_texture.getTexture()));
  this->setGLColor(rectangle.color);
  GLfloat thickness = (rectangle.thickness < 10) ? rectangle.thickness : 10;

  if (thickness == 0)
    thickness = 1;
  glLineWidth(thickness);
  glPushMatrix();

  glRotated(rectangle.rotate, 0, 0, 1);
  if (rectangle.full)
    glRecti(pos.x, pos.y, pos.x + rectangle.size.x, pos.y + rectangle.size.y);
  else {
    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
    glRecti(pos.x, pos.y, pos.x + rectangle.size.x, pos.y + rectangle.size.y);
    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
  }
  glPopMatrix();
  glLineWidth(1);

  sf::Texture::bind(NULL);
  this->setGLColor(rgb(255, 255, 255, 255));
  return true;
}

bool arcade::OpenGLFrame::draw(const arcade::rgb &color) {
  sf::Texture::bind(&this->_texture.getTexture());
  this->_texture.draw(sf::Sprite(this->_texture.getTexture()));
  glBegin(GL_QUADS);
  this->setGLColor(color);
  glVertex2d(0, 0);
  glVertex2d(0, this->_texture.getSize().y);
  glVertex2d(this->_texture.getSize().x, this->_texture.getSize().y);
  glVertex2d(this->_texture.getSize().x, 0);
  this->setGLColor(rgb(255, 255, 255, 255));
  glEnd();
  sf::Texture::bind(NULL);
  return true;
}

sf::Sprite arcade::OpenGLFrame::getSprite() const {
  const_cast<sf::RenderTexture &>(this->_texture).display();
  const sf::Texture &texture = this->_texture.getTexture();
  sf::Sprite sprite(texture);
  sprite.setPosition(this->_pos.x, this->_pos.y);
  sprite.setOrigin(0, 0);
  return sprite;
}

bool arcade::OpenGLFrame::draw(const arcade::pos &pos, const std::string &str,
			       const arcade::text &text) {
  sf::Text sfmlText;

  sfmlText.setFont(this->_font);
  sfmlText.setPosition(pos.x, pos.y);
  sfmlText.setString(str);
  sfmlText.setCharacterSize(text.fontSize);
  sfmlText.setColor(sf::Color(text.color.argb[1],
			      text.color.argb[2],
			      text.color.argb[3],
			      text.color.argb[0]));
  this->_texture.draw(sfmlText);
  return true;
}

bool arcade::OpenGLFrame::draw(const arcade::pos &pos,
			       const arcade::circle &circle) {

  sf::Texture::bind(&this->_texture.getTexture());
  this->_texture.draw(sf::Sprite(this->_texture.getTexture()));
  this->setGLColor(circle.color);
  GLfloat twicePi = 2.0f * 3.14159265359;
  if (circle.full) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(pos.x, pos.y); // center of circle
  } else {
    glLineWidth((circle.thickness > 0) ? circle.thickness : 1);
    glBegin(GL_LINE_LOOP);
  }

  for(int i = 0; i <= 100;i++) {
    glVertex2f(
      pos.x + (circle.radius * cos(i *  twicePi / 100)),
	pos.y + (circle.radius * sin(i * twicePi / 100))
    );
  }
  this->setGLColor(rgb(255, 255, 255, 255));
  glEnd();
  glLineWidth(1);

  sf::Texture::bind(NULL);
  return true;
}

bool arcade::OpenGLFrame::draw(const arcade::pos &start, const arcade::pos &end,
			       const arcade::rgb &color, uint64_t thickness) {

  sf::Texture::bind(&this->_texture.getTexture());
  this->_texture.draw(sf::Sprite(this->_texture.getTexture()));
  glLineWidth(thickness);
  glBegin(GL_LINES);
  this->setGLColor(color);
  glVertex2f(start.x, start.y);
  glVertex2f(end.x, end.y);
  this->setGLColor(rgb(255, 255, 255, 255));
  glEnd();
  glLineWidth(1);
  sf::Texture::bind(NULL);
  return true;
}

void arcade::OpenGLFrame::setGLColor(const arcade::rgb &color) const {
  glColor4ub(color.argb[1],
	     color.argb[2],
	     color.argb[3],
	     color.argb[0]);
}

uint64_t arcade::OpenGLFrame::getId() const {
  return this->_id;
}
