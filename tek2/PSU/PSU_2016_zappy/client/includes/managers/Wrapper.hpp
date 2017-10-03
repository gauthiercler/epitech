/*
** SfmlWrapper.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/managers/SfmlWrapper.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 11:35:21 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 11:35:21 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_SFMLWRAPPER_HPP
#define PSU_2016_ZAPPY_SFMLWRAPPER_HPP

#include "server/Socket.hpp"
#include "WindowManager.hpp"
#include "EventManager.hpp"
#include "RessourcesManager.hpp"
#include "SoundManager.hpp"

namespace zappy {
  class			Wrapper{
    WindowManager	_windowManager;
    EventManager	_eventManager;
    RessourcesManager	_ressourcesManager;
    SoundManager	_soundManager;
    Socket		_socket;

  public:
    Wrapper();
    ~Wrapper();

    WindowManager	&getWindowManager();
    EventManager	&getEventManager();
    RessourcesManager	&getRessourcesManager();
    SoundManager	&getSoundManager();
    const Size		&getWindowSize() const;
    Socket		&getSocket();
  };
}

#endif //PSU_2016_ZAPPY_SFMLWRAPPER_HPP
