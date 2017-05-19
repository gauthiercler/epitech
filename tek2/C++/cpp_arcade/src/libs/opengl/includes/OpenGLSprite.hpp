/*
** OpenGLSprite.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/libs/opengl/includes/OpenGLSprite.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Apr 03 23:17:36 2017 Gauthier Cler
** Last update Mon Apr 03 23:17:36 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_OPENGLSPRITE_HPP
#define CPP_ARCADE_OPENGLSPRITE_HPP

#include <map>
#include <regex>
#include "ISprite.hpp"
#include "OpenGLPicture.hpp"


namespace arcade
{
  typedef struct s_sprite			sprite;

  struct					s_sprite
  {
    s_sprite(pos p, pos s, rgb c) : position(p), size(s), color(c) {};
    pos				position;
    pos				size;
    rgb				color;
  };

  class					OpenGLSprite : public arcade::ISprite
  {
    bool				_loaded;
    pos					_size;
    OpenGLPicture			_picture;
    std::map<uint64_t , sprite>		_sprites;
    std::regex				_regexes[2];

  public:
    OpenGLSprite();
    virtual ~OpenGLSprite();
    void					setImage(const std::string &path);
    void					addSprite(std::string &line);
    virtual bool				load(const std::string &name);
    virtual const IPicture			&getPicture(uint64_t id);
    virtual const pos				&getSize(uint64_t id) const;

  };
}

#endif //CPP_ARCADE_OPENGLSPRITE_HPP
