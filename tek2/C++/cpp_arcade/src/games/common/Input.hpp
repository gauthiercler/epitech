/*
** Input.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/games/common/Input.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sat Apr 08 16:59:40 2017 Vincent DUSAUTOIR
** Last update Sat Apr 08 16:59:40 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_INPUT_HPP
#define CPP_ARCADE_INPUT_HPP

#include <map>
#include <sstream>
#include "IEvent.hpp"

namespace arcade
{

  class Input {
    std::map<arcade::eventValue, std::string>	_charMap;
    std::string					_value;

  public:
    Input();
    ~Input();
    void	receiveEvent(const arcade::IEvent &event);
    std::string	getValue() const;
  };

}

#endif //CPP_ARCADE_INPUT_HPP
