/*
** Input.cpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/games/common/Input.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sat Apr 08 17:02:33 2017 Vincent DUSAUTOIR
** Last update Sat Apr 08 17:02:34 2017 Vincent DUSAUTOIR
*/

#include "Input.hpp"

arcade::Input::Input() {
  this->_charMap = {
    {EV_A, "a"},
    {EV_B, "b"},
    {EV_C, "c"},
    {EV_D, "d"},
    {EV_E, "e"},
    {EV_F, "f"},
    {EV_G, "g"},
    {EV_H, "h"},
    {EV_I, "i"},
    {EV_J, "j"},
    {EV_K, "k"},
    {EV_L, "l"},
    {EV_M, "m"},
    {EV_N, "n"},
    {EV_O, "o"},
    {EV_P, "p"},
    {EV_Q, "q"},
    {EV_R, "r"},
    {EV_S, "s"},
    {EV_T, "t"},
    {EV_U, "u"},
    {EV_V, "v"},
    {EV_W, "w"},
    {EV_X, "x"},
    {EV_Y, "y"},
    {EV_Z, "z"},
    {EV_SPACE, " "}
  };
}

arcade::Input::~Input() {

}

void arcade::Input::receiveEvent(const arcade::IEvent &event) {
  if (event.getType() == ET_KEYBOARD_CLICK)
  {
    if (event.getValue() == EV_BACKSPACE)
      this->_value = this->_value.substr(0, this->_value.size() - 1);
    else
    {
      auto charValue = this->_charMap.find(event.getValue());
      if (charValue != this->_charMap.end() && this->_value.size() < 40)
	this->_value += charValue->second;
    }
  }
}

std::string arcade::Input::getValue() const {
  return this->_value;
}
