/*
** Rect.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/drawable/Rect.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed Jun 21 09:50:03 2017 Vincent DUSAUTOIR
** Last update Wed Jun 21 09:50:03 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_RECT_HPP
#define PSU_2016_ZAPPY_RECT_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include "utils/Color.hpp"
#include "utils/Position.hpp"
#include "utils/Size.hpp"
#include "IDrawable.hpp"

namespace zappy{
  class		Rect : public IDrawable{
    Size		_size;
    Position		_pos;
    Color		_color;
    Size		_scale;
    bool		_centered;
    sf::RectangleShape	_drawable;
  public:
    virtual sf::Drawable &get();

  public:
    Rect(const Size &size = Size(30, 30), const Position &pos = Position(0, 0), const Color &color = Color(0), bool centered = false);
    virtual ~Rect();

    void		setColor(const Color &color);
    void		setPosition(const Position &pos);
    void		setSize(const Size &size);
    void		setCentered(bool centered);
    void		setScale(const Size &scale);
    const Size		&getSize() const;
    Position		getPosition() const;
    const Color		&getColor() const;
  };

}

#endif //PSU_2016_ZAPPY_RECT_HPP
