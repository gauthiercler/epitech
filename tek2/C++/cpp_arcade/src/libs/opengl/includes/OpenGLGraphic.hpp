/*
** OpenGL.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/libs/opengl/OpenGL.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Mar 19 17:31:51 2017 Gauthier Cler
** Last update Sun Mar 19 17:31:51 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_OPENGL_HPP
#define CPP_ARCADE_OPENGL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include "IGraphic.hpp"
#include "OpenGLFrame.hpp"
#include "OpenGLEvent.hpp"

namespace arcade {
  class OpenGLGraphic : public IGraphic {

  public:
    OpenGLGraphic();
    virtual			~OpenGLGraphic();
    virtual bool		openWindow(const std::string &name, uint64_t width, uint64_t height);
    virtual void		closeWindow();
    virtual IFrame		&addFrame(const pos &positions, uint64_t width, uint64_t height, uint64_t depth = 0);
    virtual IPicture		*loadPicture(const std::string &path) const;
    virtual ISprite		*loadSprite(const std::string &path) const;
    virtual bool		display();
    virtual const IEvent	&getEvent(bool blocking = true);
    virtual void		resetStackEvents();
    virtual ISound		*loadSound(const std::string &path) const;
    virtual void		deleteFrame(uint64_t id);

  private:
    sf::RenderWindow		*_window;
    OpenGLEvent			_event;
    std::vector<std::pair<uint64_t, OpenGLFrame *>> _framesMap;
  };  
}

#endif //CPP_ARCADE_OPENGL_HPP
