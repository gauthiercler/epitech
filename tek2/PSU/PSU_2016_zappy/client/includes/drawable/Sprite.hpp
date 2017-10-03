/*
** Sprite.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/drawable/Sprite.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 22 09:56:53 2017 Vincent DUSAUTOIR
** Last update Thu Jun 22 09:56:53 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_SPRITE_HPP
#define PSU_2016_ZAPPY_SPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <utils/Color.hpp>
#include "utils/Position.hpp"
#include "utils/Size.hpp"
#include "IDrawable.hpp"

namespace	zappy{

  class			Sprite : public IDrawable{
    Size		_size;
    Position		_pos;
    Size		_scale;
    size_t		_sprite;
    size_t		_orientation;
    Color		_color;
    sf::Sprite		_drawable;
    sf::Texture		*_texture;

  public:
    Sprite(const std::string &name, const Size &size, const Position &pos = Position(0, 0));
    ~Sprite();

    virtual sf::Drawable &get();
    void		setPosition(const Position &pos);
    void		setTexture(const std::string &name);
    void		setSize(const Size &size);
    void		setScale(const Size &size);
    bool		setSprite(const size_t &sprite);
    void		setOrientation(const size_t &orientation);
    void		nextSprite();
    void		setColor(const Color &color);
    const Position	&getPosition() const;
    const Size		&getSize() const;
    const Size		&getScale() const;
  };

}

#endif //PSU_2016_ZAPPY_SPRITE_HPP
