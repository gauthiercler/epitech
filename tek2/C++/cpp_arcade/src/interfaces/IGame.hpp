/*
** IGame.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/interfaces/IGame.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Mar 17 15:27:20 2017 Vincent DUSAUTOIR
** Last update Fri Mar 17 15:27:20 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_IGAME_HPP
#define CPP_ARCADE_IGAME_HPP

#include "IEvent.hpp"
#include "IGraphic.hpp"
#include "../games/common/ProtocolHandler.hpp"

namespace arcade
{
  class			IGame
  {
  public:
    virtual		~IGame() {};
    virtual void	Play() = 0;
    virtual void	init(IGraphic &glib) = 0;
    virtual void	close() = 0;
    virtual void	reload(IGraphic &glib) = 0;
    virtual void	receiveEvent(const IEvent &event) = 0;
    virtual void	dumpMap() const = 0;

  };

}

#endif //CPP_ARCADE_IGAME_HPP
