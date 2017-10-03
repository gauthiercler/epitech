/*
** Buffer.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/server/Buffer.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Jun 26 17:32:20 2017 Vincent DUSAUTOIR
** Last update Mon Jun 26 17:32:20 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_BUFFER_HPP
#define PSU_2016_ZAPPY_BUFFER_HPP

#include <string>

namespace zappy {
  class		Buffer {
    std::string		_buffer;

  public:
    Buffer();
    ~Buffer();

    void		add(const std::string &sentence);
    const std::string	&getBuffer() const;
    std::string		getLine();
  };
}

#endif //PSU_2016_ZAPPY_BUFFER_HPP
