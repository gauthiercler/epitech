/*
** OpenGLEvent.cpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/libs/opengl/OpenGLEvent.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Mar 19 18:58:19 2017 Gauthier Cler
** Last update Sun Mar 19 18:58:19 2017 Gauthier Cler
*/

#include <iostream>
#include "Protocol.hpp"
#include "OpenGLEvent.hpp"


arcade::OpenGLEvent::OpenGLEvent() : _type(ET_NONE), _value(EV_UNKNOWN) {
  this->initMap();
}

arcade::OpenGLEvent::~OpenGLEvent() {

}

void arcade::OpenGLEvent::setType(arcade::eventType type) {
  this->_type = type;
}

void arcade::OpenGLEvent::setValue(arcade::eventValue value) {
  this->_value = value;
}

arcade::eventType arcade::OpenGLEvent::getType() const {
  return this->_type;
}

arcade::eventValue arcade::OpenGLEvent::getValue() const {
  return this->_value;
}

arcade::CommandType arcade::OpenGLEvent::get() const {

  return arcade::CommandType::SHOOT;
}

void arcade::OpenGLEvent::initMap() {
  this->_eventsMap.insert({sf::Keyboard::Space, EV_SPACE});
  this->_eventsMap.insert({sf::Keyboard::Escape, EV_ESCAPE});
  this->_eventsMap.insert({sf::Keyboard::Return, EV_ENTER});
  this->_eventsMap.insert({sf::Keyboard::BackSpace, EV_BACKSPACE});
  this->_eventsMap.insert({sf::Keyboard::A, EV_A});
  this->_eventsMap.insert({sf::Keyboard::B, EV_B});
  this->_eventsMap.insert({sf::Keyboard::C, EV_C});
  this->_eventsMap.insert({sf::Keyboard::D, EV_D});
  this->_eventsMap.insert({sf::Keyboard::E, EV_E});
  this->_eventsMap.insert({sf::Keyboard::F, EV_F});
  this->_eventsMap.insert({sf::Keyboard::G, EV_G});
  this->_eventsMap.insert({sf::Keyboard::H, EV_H});
  this->_eventsMap.insert({sf::Keyboard::I, EV_I});
  this->_eventsMap.insert({sf::Keyboard::J, EV_J});
  this->_eventsMap.insert({sf::Keyboard::K, EV_K});
  this->_eventsMap.insert({sf::Keyboard::L, EV_L});
  this->_eventsMap.insert({sf::Keyboard::M, EV_M});
  this->_eventsMap.insert({sf::Keyboard::N, EV_N});
  this->_eventsMap.insert({sf::Keyboard::O, EV_O});
  this->_eventsMap.insert({sf::Keyboard::P, EV_P});
  this->_eventsMap.insert({sf::Keyboard::Q, EV_Q});
  this->_eventsMap.insert({sf::Keyboard::R, EV_R});
  this->_eventsMap.insert({sf::Keyboard::S, EV_S});
  this->_eventsMap.insert({sf::Keyboard::T, EV_T});
  this->_eventsMap.insert({sf::Keyboard::U, EV_U});
  this->_eventsMap.insert({sf::Keyboard::V, EV_V});
  this->_eventsMap.insert({sf::Keyboard::W, EV_W});
  this->_eventsMap.insert({sf::Keyboard::X, EV_X});
  this->_eventsMap.insert({sf::Keyboard::Y, EV_Y});
  this->_eventsMap.insert({sf::Keyboard::Z, EV_Z});
  this->_eventsMap.insert({sf::Keyboard::Up, EV_UP});
  this->_eventsMap.insert({sf::Keyboard::Down, EV_DOWN});
  this->_eventsMap.insert({sf::Keyboard::Right, EV_RIGHT});
  this->_eventsMap.insert({sf::Keyboard::Left, EV_LEFT});
  this->_eventsMap.insert({sf::Keyboard::Num0, EV_0});
  this->_eventsMap.insert({sf::Keyboard::Num1, EV_1});
  this->_eventsMap.insert({sf::Keyboard::Num2, EV_2});
  this->_eventsMap.insert({sf::Keyboard::Num3, EV_3});
  this->_eventsMap.insert({sf::Keyboard::Num4, EV_4});
  this->_eventsMap.insert({sf::Keyboard::Num5, EV_5});
  this->_eventsMap.insert({sf::Keyboard::Num6, EV_6});
  this->_eventsMap.insert({sf::Keyboard::Num7, EV_7});
  this->_eventsMap.insert({sf::Keyboard::Num8, EV_8});
  this->_eventsMap.insert({sf::Keyboard::Num9, EV_9});
}

void arcade::OpenGLEvent::setSfmlEvent(sf::Event &event) {
  switch (event.type)
  {
    case sf::Event::Closed:
      this->setType(ET_WINDOW_CLOSED); break;
    case sf::Event::KeyPressed:
      this->setType(ET_KEYBOARD_CLICK); break;
    case sf::Event::KeyReleased:
      this->setType(ET_KEYBOARD_RELEASE); break;
    default:
      this->setType(ET_NONE);
  }
  if (this->getType() == ET_KEYBOARD_CLICK ||
      this->getType() == ET_KEYBOARD_RELEASE)
  {
    auto search = this->_eventsMap.find(event.key.code);

    if (search != this->_eventsMap.end())
      this->setValue(search->second);
    else
      this->setValue(arcade::eventValue::EV_UNKNOWN);
  }
}
