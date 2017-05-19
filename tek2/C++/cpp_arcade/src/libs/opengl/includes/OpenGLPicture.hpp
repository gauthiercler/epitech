/*
** OpenGLPicture.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/libs/opengl/OpenGLPicture.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Mar 19 18:58:39 2017 Gauthier Cler
** Last update Sun Mar 19 18:58:39 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_OPENGLPICTURE_HPP
#define CPP_ARCADE_OPENGLPICTURE_HPP


#include <IPicture.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace arcade {
  class OpenGLPicture : public IPicture{

  public:
    OpenGLPicture();
    virtual		~OpenGLPicture();
    virtual bool	load(const std::string &path);
    virtual bool	rotate(float angle);
    virtual bool	setScale(float scaleX, float scaleY);
    virtual bool	isLoaded() const;
    virtual float	getRotate() const;
    virtual float	getXScale() const;
    virtual float	getYScale() const;
    virtual const pos	&getSize() const;
    virtual bool	setInnerPos(const pos &positions, uint64_t width, uint64_t height);
    sf::Texture		getImage() const;
    virtual void	setColor(const rgb &color);
    virtual const rgb	&getColor() const;

  private:
    bool		_loaded;
    float		_rotation;
    sf::Vector2f	_scale;
    pos			_positions;
    pos			_size;
    rgb			_color;
    sf::Texture		_image;
  };
}




#endif //CPP_ARCADE_OPENGLPICTURE_HPP
