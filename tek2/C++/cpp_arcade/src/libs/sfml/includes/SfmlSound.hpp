/*
** SfmlSound.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/sfml/includes/SfmlSound.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Apr 03 23:08:20 2017 Vincent DUSAUTOIR
** Last update Mon Apr 03 23:08:20 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_SFMLSOUND_HPP
#define CPP_ARCADE_SFMLSOUND_HPP

#include <SFML/Audio/Sound.hpp>
#include "ISound.hpp"

namespace arcade
{
  class SfmlSound : public ISound
  {
    sf::Sound		_player;

  public:
    SfmlSound();
    virtual		~SfmlSound();
    virtual void	load(const std::string &name);
    virtual void	play();
    virtual void	pause();
    virtual void	replay();
    virtual void	loop();
  };
}

#endif //CPP_ARCADE_SFMLSOUND_HPP
