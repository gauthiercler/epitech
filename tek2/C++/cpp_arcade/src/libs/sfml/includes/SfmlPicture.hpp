/*
** SfmlPicture.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/sfml/includes/SfmlPicture.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Mar 20 09:13:35 2017 Vincent DUSAUTOIR
** Last update Mon Mar 20 09:13:36 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_SFMLPICTURE_HPP
#define CPP_ARCADE_SFMLPICTURE_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "IPicture.hpp"

namespace arcade
{
  class				SfmlPicture : public arcade::IPicture
  {
    bool				_loaded;
    arcade::rgb			_color;
    float				_rotate;
    std::pair<float, float>	_scale;
    arcade::pos			_innerPos;
    arcade::pos			_innerSize;
    sf::Texture			_texture;

  public:
    SfmlPicture();
    virtual ~SfmlPicture();

    virtual bool			load(const std::string &path);
    virtual bool			rotate(float angle);
    virtual bool			setScale(float scale_x, float scale_y);
    virtual bool			isLoaded() const;
    virtual float			getRotate() const;
    virtual float			getXScale() const;
    virtual float			getYScale() const;
    virtual bool			setInnerPos(const arcade::pos &positions, uint64_t width, uint64_t height);
    virtual void			setColor(const arcade::rgb &color);
    virtual const arcade::rgb	&getColor() const;
    virtual const arcade::pos	&getSize() const;
    sf::Sprite			getSprite() const;
  };
}

#endif //CPP_ARCADE_SFMLPICTURE_HPP
