/*
** IPicture.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/interfaces/IPicture.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Mar 17 15:39:28 2017 Vincent DUSAUTOIR
** Last update Fri Mar 17 15:39:28 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_IPICTURE_HPP
#define CPP_ARCADE_IPICTURE_HPP

#include <string>
#include "Structures.hpp"

namespace arcade
{
  class			IPicture
  {
  public:
    virtual		~IPicture() {};
    virtual bool	load(const std::string &path) = 0;
    virtual bool	rotate(float angle) = 0;
    virtual bool	setScale(float scale_x, float scale_y) = 0;
    virtual bool	isLoaded() const = 0;
    virtual float	getRotate() const = 0;
    virtual float	getXScale() const = 0;
    virtual float	getYScale() const = 0;
    virtual bool	setInnerPos(const pos &positions, uint64_t width, uint64_t height) = 0;
    virtual void	setColor(const rgb &color) = 0;
    virtual const rgb	&getColor() const = 0;
    virtual const pos	&getSize() const = 0;
  };
}

#endif //CPP_ARCADE_IPICTURE_HPP
