/*
** ISprite.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/interfaces/ISprite.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Mar 17 15:49:26 2017 Vincent DUSAUTOIR
** Last update Fri Mar 17 15:49:26 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_ISPRITE_HPP
#define CPP_ARCADE_ISPRITE_HPP

#include <string>
#include "IPicture.hpp"

namespace arcade
{
  class				ISprite
  {
  public:
    virtual			~ISprite() {};
    virtual bool		load(const std::string &name) = 0;
    virtual const pos		&getSize(uint64_t id) const = 0;
    virtual const IPicture	&getPicture(uint64_t id) = 0;
  };
}

#endif //CPP_ARCADE_ISPRITE_HPP
