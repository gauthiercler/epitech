/*
** OpenGLSound.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/libs/opengl/OpenGLSound.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Mar 19 18:59:15 2017 Gauthier Cler
** Last update Sun Mar 19 18:59:15 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_OPENGLSOUND_HPP
#define CPP_ARCADE_OPENGLSOUND_HPP


#include <SFML/Audio.hpp>
#include <ISound.hpp>

namespace arcade {
  class OpenGLSound : public ISound{

  public:
    OpenGLSound();
    virtual		~OpenGLSound();
    virtual void	load(const std::string &name);
    virtual void	play();
    virtual void	pause();
    virtual void	replay();
    virtual void	loop();

  private:
    sf::Sound		_player;
  };  
}

#endif //CPP_ARCADE_OPENGLSOUND_HPP
