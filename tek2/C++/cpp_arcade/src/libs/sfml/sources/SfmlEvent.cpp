/*
** SfmlEvent.cpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/sfml/sources/SfmlEvent.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Mar 20 09:18:52 2017 Vincent DUSAUTOIR
** Last update Mon Mar 20 09:18:53 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include "SfmlEvent.hpp"

arcade::SfmlEvent::SfmlEvent() : _eventType(ET_NONE), _eventValue(EV_UNKNOWN) {
  this->initMap();
}

arcade::SfmlEvent::~SfmlEvent() {

}

void arcade::SfmlEvent::setType(arcade::eventType type) {
  this->_eventType = type;
}

void arcade::SfmlEvent::setValue(arcade::eventValue value) {
  this->_eventValue = value;
}

arcade::eventType arcade::SfmlEvent::getType() const {
  return this->_eventType;
}

arcade::eventValue arcade::SfmlEvent::getValue() const {
  return this->_eventValue;
}

arcade::CommandType arcade::SfmlEvent::get() const {
  return arcade::CommandType::SHOOT;
}

void arcade::SfmlEvent::initMap() {
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

void arcade::SfmlEvent::setSfmlEvent(sf::Event &event) {
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
