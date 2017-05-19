/*
** Event.cpp for cpp_d16 in /home/gogo/rendu/tek2/cpp_d16/ex02/Event.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 19 10:53:36 2017 Gauthier CLER
** Last update Thu Jan 19 10:53:36 2017 Gauthier CLER
*/

#include "Event.h"

Event::Event(void) : _time(0), _event(""){

}

Event::Event(unsigned int time, const std::string &event) : _time(time), _event(event){
}

Event::~Event(void) {

}

Event::Event(const Event &other) : _time(other.getTime()), _event(other.getEvent()){

}

Event &Event::operator=(const Event &other) {
  this->setEvent(other.getEvent());
  this->setTime(other.getTime());
  return *this;
}

unsigned int Event::getTime(void) const {
  return this->_time;
}

const std::string &Event::getEvent(void) const {
  return this->_event;
}

void Event::setTime(unsigned int time) {
  this->_time = time;
}

void Event::setEvent(const std::string &event) {
  this->_event = event;
}
