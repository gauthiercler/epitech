/*
** new.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/tcp_socket/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 08:21:57 2017 Antoine FORET
** Last update Thu Apr 27 08:21:57 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"tcp_socket.h"

static void	tcp_socket_methods(t_tcp_socket *socket)
{
  socket->connect = tcp_socket_connect;
  socket->send = tcp_socket_send;
  socket->get_ip = tcp_socket_get_ip;
  socket->get_port = tcp_socket_get_port;
  socket->get_foreign_ip = tcp_socket_get_foreign_ip;
  socket->get_foreign_port = tcp_socket_get_foreign_port;
  socket->is_connected = tcp_socket_is_connected;
  socket->receive = tcp_socket_receive;
  socket->receive_until = tcp_socket_receive_until;
  socket->bind = tcp_socket_bind;
  socket->listen = tcp_socket_listen;
  socket->accept = tcp_socket_accept;
  socket->disconnect = tcp_socket_disconnect;
  socket->enable_keep_alive = tcp_socket_enable_keep_alive;
  socket->disable_keep_alive = tcp_socket_disable_keep_alive;
  socket->keep_alive_status = tcp_socket_keep_alive_status;
  socket->destroy = tcp_socket_destroy;
}

t_tcp_socket	*new_tcp_socket()
{
  t_tcp_socket	*self;

  self = malloc(sizeof(t_tcp_socket));
  if (self == NULL)
    return (NULL);
  self->socket = socket(AF_INET, SOCK_STREAM, 0);
  self->buffer = NULL;
  self->connected = false;
  if (self->socket == INVALID_SOCKET)
  {
    free(self);
    return (NULL);
  }
  tcp_socket_methods(self);
  return (self);
}

t_tcp_socket	*new_tcp_socket_explicit(SOCKET sock)
{
  t_tcp_socket	*self;

  self = malloc(sizeof(t_tcp_socket));
  if (self == NULL)
    return (NULL);
  self->socket = sock;
  self->buffer = NULL;
  self->connected = false;
  if (self->socket == INVALID_SOCKET)
  {
    free(self);
    return (NULL);
  }
  tcp_socket_methods(self);
  return (self);
}