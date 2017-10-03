/*
** listen.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/tcp_socket/listen.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 08:59:46 2017 Antoine FORET
** Last update Thu Apr 27 08:59:46 2017 Antoine FORET
*/

#include	"tcp_socket.h"

bool		tcp_socket_listen(t_tcp_socket *self, int max_client)
{
  if (listen(self->socket, max_client) == SOCKET_ERROR)
    return (false);
  else
    return (true);
}