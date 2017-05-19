/*
** ISound.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/interfaces/ISound.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Mar 17 15:45:41 2017 Vincent DUSAUTOIR
** Last update Fri Mar 17 15:45:41 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_ISOUND_HPP
#define CPP_ARCADE_ISOUND_HPP

#include <string>

namespace arcade
{
  class			ISound
  {
  public:
    virtual		~ISound() {};
    virtual void	load(const std::string &name) = 0;
    virtual void	play() = 0;
    virtual void	pause() = 0;
    virtual void	replay() = 0;
    virtual void	loop() = 0;
  };
}

#endif //CPP_ARCADE_ISOUND_HPP
