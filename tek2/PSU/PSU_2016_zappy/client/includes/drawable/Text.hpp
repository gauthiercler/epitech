/*
** Text.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/drawable/Text.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed Jun 21 09:08:51 2017 Vincent DUSAUTOIR
** Last update Wed Jun 21 09:08:51 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_TEXT_HPP
#define PSU_2016_ZAPPY_TEXT_HPP

#include <SFML/Graphics/Text.hpp>
#include <utils/Color.hpp>
#include <utils/Position.hpp>
#include "IDrawable.hpp"

namespace zappy {
  class		Text : public IDrawable {
    bool		_centered;
    unsigned int	_fontSize;
    std::string		_fontName;
    std::string		_text;
    Color		_color;
    Position		_pos;
    sf::Text		_drawable;

  public:
    Text(const std::string &text, const std::string &font = "roboto", const unsigned int size = 18, bool centered = false);
    Text();
    virtual ~Text();

    void	setCentered(bool centered);
    void	setString(const std::string &text);
    void	setColor(const Color &color);
    void	setPosition(const Position &pos);
    void	setFont(const std::string &name, const unsigned int size = 18);

    virtual sf::Drawable &get();
  };
}

#endif //PSU_2016_ZAPPY_TEXT_HPP
