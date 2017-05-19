/*
** SfmlSprite.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/sfml/includes/SfmlSprite.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Mar 20 09:16:06 2017 Vincent DUSAUTOIR
** Last update Mon Mar 20 09:16:07 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_SFMLSPRITE_HPP
#define CPP_ARCADE_SFMLSPRITE_HPP

#include <map>
#include <regex>
#include "ISprite.hpp"
#include "SfmlPicture.hpp"


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

  class					SfmlSprite : public arcade::ISprite
  {
    bool				_loaded;
    pos					_size;
    SfmlPicture				_picture;
    std::map<uint64_t , sprite>		_sprites;
    std::regex				_regexes[2];

  public:
    SfmlSprite();
    virtual ~SfmlSprite();
    void					setImage(const std::string &path);
    void					addSprite(std::string &line);
    virtual bool				load(const std::string &name);
    virtual const IPicture			&getPicture(uint64_t id);
    virtual const pos				&getSize(uint64_t id) const;

  };
}

#endif //CPP_ARCADE_SFMLSPRITE_HPP
