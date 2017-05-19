/*
** SfmlFrame.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/sfml/includes/SfmlFrame.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Mar 20 09:11:07 2017 Vincent DUSAUTOIR
** Last update Mon Mar 20 09:11:07 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_SFMLFRAME_HPP
#define CPP_ARCADE_SFMLFRAME_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Font.hpp>
#include "IFrame.hpp"
#include "SfmlPicture.hpp"

namespace arcade
{
  class SfmlFrame : public arcade::IFrame
  {
    sf::RenderTexture		_texture;
    sf::Font			_font;
    arcade::pos			_pos;
    uint64_t			_id;

  public:
    SfmlFrame(const arcade::pos &pos, uint64_t width, uint64_t height, uint64_t id = 0);
    virtual ~SfmlFrame();

    virtual bool	draw(const arcade::pos &pos, const arcade::IPicture &picture);
    virtual bool	draw(const arcade::pos &pos, const arcade::rectangle &rectangle);
    virtual bool	draw(const arcade::pos &pos, const std::string &str, const arcade::text &text);
    virtual bool	draw(const arcade::pos &pos, const arcade::circle &circle);
    virtual bool	draw(const arcade::pos &start, const arcade::pos &end, const arcade::rgb &color, uint64_t thickness = 1);
    virtual bool	draw(const arcade::rgb &color);
    virtual uint64_t	getId() const;
    sf::Sprite	getSprite() const;
  };
}

#endif //CPP_ARCADE_SFMLFRAME_HPP
