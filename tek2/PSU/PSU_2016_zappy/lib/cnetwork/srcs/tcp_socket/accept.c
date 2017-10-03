/*
** accept.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/tcp_socket/accept.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 09:03:39 2017 Antoine FORET
** Last update Thu Apr 27 09:03:39 2017 Antoine FORET
*/

#include		"tcp_socket.h"

t_client		*tcp_socket_accept(t_tcp_socket *self)
{
  t_client		*client;
  SOCKET		new_socket;
  SOCKADDR_IN		sockaddr_in;
  socklen_t		size_sockaddr_in;

  size_sockaddr_in = sizeof(sockaddr_in);
  new_socket = accept(self->socket, (SOCKADDR *)&sockaddr_in,
		      &size_sockaddr_in);
  if (new_socket == INVALID_SOCKET)
    return (NULL);
  client = new_tcp_client(new_socket);
  if (client == NULL)
    closesocket(new_socket);
  else
    client->socket->connected = true;
  return (client);
}