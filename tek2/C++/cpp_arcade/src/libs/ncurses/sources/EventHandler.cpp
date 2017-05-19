/*
** EventHandler.cpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/src/libs/ncurses/sources/EventHandler.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Apr 03 16:50:06 2017 Anas Buyumad
** Last update Mon Apr 03 16:50:06 2017 Anas Buyumad
*/

#include	<unistd.h>
#include <iostream>
#include <term.h>
#include <memory>
#include	"EventHandler.hpp"
#include	"Error.hpp"

Curses::EventHandler::EventHandler() {
  this->setUpKeypad();
  this->loadSequences();
}

Curses::EventHandler::~EventHandler() {

}

const arcade::IEvent &Curses::EventHandler::getEvent(bool blocking) const {
  arcade::eventType 	eventType;
  arcade::eventValue 	eventValue;
  char			buffer[128];
  ssize_t		bytes;

  if (blocking)
    while (!(bytes = read(0, buffer, sizeof(buffer))));
  else
    bytes = read(0, buffer, sizeof(buffer));
  buffer[bytes] = '\0';

  if (this->keymap.find(buffer) == this->keymap.end()) {
    eventType = arcade::ET_NONE;
    eventValue = arcade::EV_UNKNOWN;
  }
  else {
    eventType = arcade::ET_KEYBOARD_CLICK;
    eventValue = this->keymap.at(buffer);
  }
  Curses::Event *event;
  event = new Curses::Event(eventType, eventValue);
  return *event;
}

void Curses::EventHandler::setUpKeypad(void) const {
  int		termReturn;
  char		*keypad;

  setupterm(getenv("TERM"), 1, &termReturn);
  if (termReturn <= 0) {
    throw arcade::Error("Failed to setupTerm.");
  }
  if ((keypad = tigetstr("smkx")) == NULL)
  {
    throw arcade::Error("Failed to retrieve keypad.");
  }
  putp(keypad);
  std::cout << std::endl;
}

void Curses::EventHandler::loadSequences(void) {
  char		Escape[1];

  Escape[0] = 27;
  this->keymap.insert( {" ", arcade::eventValue::EV_SPACE} );
  this->keymap.insert( {Escape , arcade::eventValue::EV_ESCAPE} );
  this->keymap.insert( {"a", arcade::eventValue::EV_A} );
  this->keymap.insert( {"b", arcade::eventValue::EV_B} );
  this->keymap.insert( {"c", arcade::eventValue::EV_C} );
  this->keymap.insert( {"d", arcade::eventValue::EV_D} );
  this->keymap.insert( {"e", arcade::eventValue::EV_E} );
  this->keymap.insert( {"f", arcade::eventValue::EV_F} );
  this->keymap.insert( {"g", arcade::eventValue::EV_G} );
  this->keymap.insert( {"h", arcade::eventValue::EV_H} );
  this->keymap.insert( {"i", arcade::eventValue::EV_I} );
  this->keymap.insert( {"j", arcade::eventValue::EV_J} );
  this->keymap.insert( {"k", arcade::eventValue::EV_K} );
  this->keymap.insert( {"l", arcade::eventValue::EV_L} );
  this->keymap.insert( {"m", arcade::eventValue::EV_M} );
  this->keymap.insert( {"n", arcade::eventValue::EV_N} );
  this->keymap.insert( {"o", arcade::eventValue::EV_O} );
  this->keymap.insert( {"p", arcade::eventValue::EV_P} );
  this->keymap.insert( {"q", arcade::eventValue::EV_Q} );
  this->keymap.insert( {"r", arcade::eventValue::EV_R} );
  this->keymap.insert( {"s", arcade::eventValue::EV_S} );
  this->keymap.insert( {"t", arcade::eventValue::EV_T} );
  this->keymap.insert( {"u", arcade::eventValue::EV_U} );
  this->keymap.insert( {"v", arcade::eventValue::EV_V} );
  this->keymap.insert( {"w", arcade::eventValue::EV_W} );
  this->keymap.insert( {"x", arcade::eventValue::EV_X} );
  this->keymap.insert( {"y", arcade::eventValue::EV_Y} );
  this->keymap.insert( {"z", arcade::eventValue::EV_Z} );
  Escape[0] = 13;
  this->keymap.insert( {Escape, arcade::eventValue::EV_ENTER} );
  this->keymap.insert( {tigetstr("kbs"), arcade::eventValue::EV_BACKSPACE} );
  this->keymap.insert( {tigetstr("kcuu1"), arcade::eventValue::EV_UP} );
  this->keymap.insert( {tigetstr("kcud1"), arcade::eventValue::EV_DOWN} );
  this->keymap.insert( {tigetstr("kcuf1"), arcade::eventValue::EV_RIGHT} );
  this->keymap.insert( {tigetstr("kcub1"), arcade::eventValue::EV_LEFT} );
  this->keymap.insert( {"à", arcade::eventValue::EV_0} );
  this->keymap.insert( {"&", arcade::eventValue::EV_1} );
  this->keymap.insert( {"é", arcade::eventValue::EV_2} );
  this->keymap.insert( {"\"", arcade::eventValue::EV_3} );
  this->keymap.insert( {"'", arcade::eventValue::EV_4} );
  this->keymap.insert( {"(", arcade::eventValue::EV_5} );
  this->keymap.insert( {"-", arcade::eventValue::EV_6} );
  this->keymap.insert( {"è", arcade::eventValue::EV_7} );
  this->keymap.insert( {"_", arcade::eventValue::EV_8} );
  this->keymap.insert( {"ç", arcade::eventValue::EV_9} );
  this->keymap.insert( {"0", arcade::eventValue::EV_0} );
  this->keymap.insert( {"1", arcade::eventValue::EV_1} );
  this->keymap.insert( {"2", arcade::eventValue::EV_2} );
  this->keymap.insert( {"3", arcade::eventValue::EV_3} );
  this->keymap.insert( {"4", arcade::eventValue::EV_4} );
  this->keymap.insert( {"5", arcade::eventValue::EV_5} );
  this->keymap.insert( {"6", arcade::eventValue::EV_6} );
  this->keymap.insert( {"7", arcade::eventValue::EV_7} );
  this->keymap.insert( {"8", arcade::eventValue::EV_8} );
  this->keymap.insert( {"9", arcade::eventValue::EV_9} );
}
