/*
** CursesPicture.hpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/src/libs/ncurses/includes/CursesPicture.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Apr 08 23:15:53 2017 Anas Buyumad
** Last update Sat Apr 08 23:15:53 2017 Anas Buyumad
*/

#ifndef CPP_ARCADE_CURSESPICTURE_HPP
#define CPP_ARCADE_CURSESPICTURE_HPP

#include <IPicture.hpp>

namespace Curses
{
  class			Picture : public arcade::IPicture
  {
  public:

    Picture();
    virtual		~Picture();
    virtual bool	load(const std::string &path);
    virtual bool	rotate(float angle);
    virtual bool	setScale(float scale_x, float scale_y);
    virtual bool	isLoaded() const;
    virtual float	getRotate() const;
    virtual float	getXScale() const;
    virtual float	getYScale() const;
    virtual bool	setInnerPos(const arcade::pos &positions, uint64_t width, uint64_t height);
    virtual void	setColor(const arcade::rgb &color);
    virtual const arcade::rgb	&getColor() const;
    virtual const arcade::pos	&getSize() const;

  private:

    float		rotation;
    float		scale_x;
    float		scale_y;
    arcade::pos		size;
    arcade::rgb		color;
  };
}

#endif //CPP_ARCADE_CURSESPICTURE_HPP
