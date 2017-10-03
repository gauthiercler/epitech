/*
** SfmlManager.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/managers/SfmlManager.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 11:26:46 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 11:26:46 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_SFMLMANAGER_HPP
#define PSU_2016_ZAPPY_SFMLMANAGER_HPP


#include "Wrapper.hpp"

namespace zappy{

  class			Engine{
    static std::unique_ptr<Wrapper> _sfmlWrapper;

  public :
    static Wrapper	&get();
  };

}


#endif //PSU_2016_ZAPPY_SFMLMANAGER_HPP
