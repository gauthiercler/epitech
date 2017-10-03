/*
** connect.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/common/socket/connect.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue May 30 10:22:25 2017 Gauthier Cler
** Last update Tue May 30 10:22:25 2017 Gauthier Cler
*/

#include		"common/error.h"
#include		"common/structures.h"

bool			connect_socket(t_socket * socket)
{
  if (operational)
  {
    if (connect(socket->fd, (struct sockaddr *)&socket->address,
		sizeof(socket->address)) == SYSCALL_FAIL)
    {
      throw_error("connect", __func__,  &operational, MINOR);
      return (false);
    }
  }
  return (true);
}