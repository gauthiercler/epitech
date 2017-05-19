/*
** NamedPipe.hpp for cpp_plazza in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_plazza/includes/NamedPipe.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Apr 12 15:29:12 2017 Anas Buyumad
** Last update Wed Apr 12 15:29:13 2017 Anas Buyumad
*/

#ifndef CPP_PLAZZA_NAMEDPIPE_HPP
#define CPP_PLAZZA_NAMEDPIPE_HPP

#include <string>
#include "Config.hpp"

namespace		plazza {



  class			ConnectorPipe {

  public:

    enum		Fmode {
      IN,
      OUT
    };

    ConnectorPipe();
    ~ConnectorPipe();

    void			setFd(const int fd);
    int				getFd(void) const;
    void			setName(const std::string &name);
    const std::string		&getName(void) const;
    void			setMode(const Fmode mode);
    const Fmode			&getMode(void) const;

    void			create(const std::string &name);
    void			connect(const std::string &name, const Fmode mode);
    void			disconnect();
    void			destroy();

    ssize_t 			transfertData(Data &data) const;
    ssize_t			sendData(const Data &data, const int callback_depth) const;
    ssize_t			receiveData(Data &data) const;

  private:

    int			_fd;
    std::string		_name;
    Fmode 		_mode;

  };

}

#endif //CPP_PLAZZA_NAMEDPIPE_HPP
