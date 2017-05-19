/*
** ProtocolHandler.cpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/src/games/common/ProtocolHandler.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Apr 05 16:40:15 2017 Anas Buyumad
** Last update Wed Apr 05 16:40:16 2017 Anas Buyumad
*/

#include <iostream>
#include "ProtocolHandler.hpp"

arcade::ProtocolHandler::ProtocolHandler() {

}

arcade::ProtocolHandler::~ProtocolHandler() {

}

bool arcade::ProtocolHandler::getCommand() {

  uint16_t 		command;

  int c = std::cin.peek();
  if (c == EOF) {
    if (std::cin.eof()) {
      return false;
    }
  }

  std::cin.read(reinterpret_cast<char *>(&command), sizeof(uint16_t));
  this->setCommandType(static_cast<arcade::CommandType>(command));

  return true;
}

void arcade::ProtocolHandler::setCommandType(arcade::CommandType commandType) {
  this->_commandType = commandType;
}

arcade::CommandType arcade::ProtocolHandler::getCommandType(void) {
  return this->_commandType;
}

arcade::IEvent &arcade::ProtocolHandler::getEvent() {
  arcade::IEvent	*event = new arcade::ProtocolEvent();

  switch (this->getCommandType()) {
    case arcade::CommandType::GO_UP:
      event->setValue(arcade::eventValue::EV_UP);
      break;
    case arcade::CommandType::GO_DOWN:
      event->setValue(arcade::eventValue::EV_DOWN);
      break;
    case arcade::CommandType::GO_LEFT:
      event->setValue(arcade::eventValue::EV_LEFT);
      break;
    case arcade::CommandType::GO_RIGHT:
      event->setValue(arcade::eventValue::EV_RIGHT);
      break;
    default:
      break;
  }

  if (this->getCommandType() == arcade::CommandType::GO_UP
      || this->getCommandType() == arcade::CommandType::GO_DOWN
      || this->getCommandType() == arcade::CommandType::GO_LEFT
      || this->getCommandType() == arcade::CommandType::GO_RIGHT) {
    event->setType(arcade::eventType::ET_KEYBOARD_CLICK);
  }
  else {
    event->setType(ET_NONE);
    event->setValue(EV_UNKNOWN);
  }

  return *event;
}

void arcade::ProtocolHandler::setMap(
  const std::vector<std::vector<arcade::TileType>> &map) {
  this->_map = map;
}

void arcade::ProtocolHandler::setHead(std::pair<int, int> head) {
  this->_head = head;
}

void arcade::ProtocolHandler::setTail(std::vector<std::pair<int, int>> tail) {
  this->_tail = tail;
}

void arcade::ProtocolHandler::setLength(uint16_t length) {
  this->_length = length;
}

void arcade::ProtocolHandler::dumpToLittle(uint16_t value) {
  unsigned char			low;
  unsigned char			high;

  low = value & 0xFF;
  high = value >> 8;
  std::cout << low << high;
}

void arcade::ProtocolHandler::dumpMap(void) {
  struct arcade::GetMap		mapInfo;

  mapInfo.type = arcade::CommandType::GET_MAP;
  mapInfo.width = static_cast<uint16_t >(this->_map.size());
  mapInfo.height = static_cast<uint16_t >(this->_map.at(0).size());

  this->dumpToLittle(static_cast<uint16_t >(mapInfo.type));
  this->dumpToLittle(static_cast<uint16_t >(mapInfo.width));
  this->dumpToLittle(static_cast<uint16_t >(mapInfo.height));

  for (auto &it : this->_map) {
    for (auto &sub_it : it) {
      this->dumpToLittle(static_cast<uint16_t >(sub_it));
    }
  }
}

void arcade::ProtocolHandler::dumpPosition(void) {
  struct arcade::WhereAmI	posInfo;

  posInfo.type = arcade::CommandType::WHERE_AM_I;
  posInfo.lenght = this->_length;

/*  std::cout << "Length : " << posInfo.lenght;
  std::cout << "Head : " << this->_head.first << " / " << this->_head.second;*/
  this->dumpToLittle(static_cast<uint16_t >(posInfo.type));
  this->dumpToLittle(static_cast<uint16_t >(posInfo.lenght));
  this->dumpToLittle(static_cast<uint16_t >(this->_head.first));
  this->dumpToLittle(static_cast<uint16_t >(this->_head.second));

  if (this->_length > 1) {
    for (std::vector<std::pair<int,int>>::reverse_iterator it = this->_tail.rbegin() ; it != this->_tail.rend() ; ++it) {
      this->dumpToLittle(static_cast<uint16_t >(it->first));
      this->dumpToLittle(static_cast<uint16_t >(it->second));
    }
  }
}

arcade::ProtocolEvent::ProtocolEvent() {

}

arcade::ProtocolEvent::~ProtocolEvent() {

}

void arcade::ProtocolEvent::setType(arcade::eventType type) {
  this->_type = type;
}


void arcade::ProtocolEvent::setValue(arcade::eventValue value) {
  this->_value = value;
}

arcade::eventType arcade::ProtocolEvent::getType() const {
  return this->_type;
}

arcade::eventValue arcade::ProtocolEvent::getValue() const {
  return this->_value;
}

arcade::CommandType arcade::ProtocolEvent::get() const {
  return arcade::CommandType::SHOOT;
}