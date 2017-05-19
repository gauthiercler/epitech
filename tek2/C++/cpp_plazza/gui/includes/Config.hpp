/*
** Config.hpp for cpp_plazza in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_plazza/includes/Config.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Apr 12 15:25:22 2017 Anas Buyumad
** Last update Wed Apr 12 15:25:22 2017 Anas Buyumad
*/

#ifndef CPP_PLAZZA_CONFIG_HPP
#define CPP_PLAZZA_CONFIG_HPP

#include <string>

namespace		plazza {

  const std::string		SERVER_FIFO = "serverFIFO";
  const std::string		OFFICE_SHUTDOWN = "OfficeShutDown";
  const std::string		TASK_COMPLETED = "TaskComplete";
  const std::string		DISPLAY = "Display";
  const unsigned int		CONTENT_MAX_LENGTH = 256;
  typedef struct s_Data		Data;

  enum			DataType
  {
    COMMAND,
    SIGNAL
  };

  struct __attribute__((packed))	s_Data
  {
    pid_t		sender_id;
    DataType		type;
    char		action[CONTENT_MAX_LENGTH];
    char		value[CONTENT_MAX_LENGTH];
  };
}

#endif //CPP_PLAZZA_CONFIG_HPP
