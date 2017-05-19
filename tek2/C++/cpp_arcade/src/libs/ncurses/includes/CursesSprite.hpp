/*
** CursesSprite.hpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/src/libs/ncurses/includes/CursesSprite.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Apr 09 02:15:21 2017 Anas Buyumad
** Last update Sun Apr 09 02:15:21 2017 Anas Buyumad
*/

#ifndef CPP_ARCADE_CURSESSPRITE_HPP
#define CPP_ARCADE_CURSESSPRITE_HPP

#include <regex>
#include <ISprite.hpp>
#include "CursesPicture.hpp"

namespace Curses
{
  typedef struct s_sprite			sprite;

  struct					s_sprite
  {
    s_sprite(arcade::pos p, arcade::pos s, arcade::rgb c) : position(p), size(s), color(c) {};
    arcade::pos				position;
    arcade::pos				size;
    arcade::rgb				color;
  };

  class		CursesSprite : public arcade::ISprite
  {
    bool				_loaded;
    arcade::pos				_size;
    Curses::Picture				_picture;
    std::map<uint64_t , Curses::sprite>		_sprites;
    std::regex				_regexes[2];

  public:

    CursesSprite();
    virtual			~CursesSprite();
    void			setImage(const std::string &path);
    void			addSprite(std::string &line);
    virtual bool		load(const std::string &name);
    virtual const arcade::pos		&getSize(uint64_t id) const;
    virtual const arcade::IPicture	&getPicture(uint64_t id);
  };
}

#endif //CPP_ARCADE_CURSESSPRITE_HPP
