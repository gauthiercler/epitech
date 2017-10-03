/*
** Broadcast.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/classes/Broadcast.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jun 30 14:53:20 2017 Anas Buyumad
** Last update Fri Jun 30 14:53:20 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_BROADCAST_HPP
#define PSU_2016_ZAPPY_BROADCAST_HPP

#include <cstddef>

namespace ai {

  struct Broadcast {

  public:

    enum type {
      START = 0,
      END
    };

    std::string	teamName;
    size_t	level;
    size_t	origin;
    type	type;

    Broadcast	&operator=(const Broadcast &other) {
      teamName = other.teamName;
      level = other.level;
      origin = other.origin;
      type = other.type;
      return *this;
    }

  };
}

#endif //PSU_2016_ZAPPY_BROADCAST_HPP
