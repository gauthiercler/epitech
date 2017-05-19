/*
** OpenGLFrame.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/libs/opengl/OpenGLFrame.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Mar 19 18:58:26 2017 Gauthier Cler
** Last update Sun Mar 19 18:58:26 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_OPENGLFRAME_HPP
#define CPP_ARCADE_OPENGLFRAME_HPP


#include <IFrame.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>

namespace arcade {
  class OpenGLFrame : public IFrame{

  public:
    OpenGLFrame(const pos &positions, uint64_t width, uint64_t height, uint64_t id = 0);
    virtual		~OpenGLFrame();
    virtual bool	draw(const pos &pos, const IPicture &picture);
    virtual bool	draw(const pos &pos, const rectangle &rectangle);
    virtual bool	draw(const pos &pos, const std::string &str, const arcade::text &text);
    virtual bool	draw(const pos &pos, const arcade::circle &circle);
    virtual bool	draw(const pos &start, const pos &end, const rgb &color, uint64_t thickness = 1);
    virtual bool	draw(const rgb &color);
    void		setGLColor(const rgb &color) const;
    sf::Sprite		getSprite() const;
    virtual uint64_t	getId() const;


  private:
    pos			_pos;
    sf::Font		_font;
    sf::RenderTexture	_texture;
    uint64_t		_id;
  };
}



#endif //CPP_ARCADE_OPENGLFRAME_HPP
