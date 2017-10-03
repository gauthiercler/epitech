/*
** new.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/client/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 09:22:21 2017 Antoine FORET
** Last update Thu Apr 27 09:22:21 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"client.h"

static void	tcp_client_methods(t_client *client)
{
  client->get_ip = client_get_ip;
  client->get_port = client_get_port;
  client->get_host_ip = client_get_host_ip;
  client->get_host_port = client_get_host_port;
  client->send = tcp_client_send;
  client->receive = tcp_client_receive;
  client->receive_until = tcp_client_receive_until;
  client->disconnect = tcp_client_disconnect;
  client->is_connected = tcp_client_is_connected;
  client->enable_keep_alive = tcp_client_enable_keep_alive;
  client->disable_keep_alive = tcp_client_disable_keep_alive;
  client->keep_alive_status = tcp_client_keep_alive_status;
  client->destroy = tcp_client_destroy;
}

t_client	*new_tcp_client(SOCKET sock)
{
  t_client	*self;

  if (sock == INVALID_SOCKET)
    return (NULL);
  self = malloc(sizeof(t_client));
  if (self == NULL)
    return (NULL);
  self->socket = new_tcp_socket_explicit(sock);
  if (self->socket == NULL)
  {
    free(self);
    return (NULL);
  }
  tcp_client_methods(self);
  return (self);
}

t_client	*new_tcp_client_connect(const char *ip, uint16_t port)
{
  t_client	*self;

  self = malloc(sizeof(t_client));
  if (self == NULL)
    return (NULL);
  self->socket = new_tcp_socket();
  if (self->socket == NULL)
  {
    free(self);
    return (NULL);
  }
  if (!self->socket->connect(self->socket, ip, port))
  {
    self->socket->destroy(self->socket);
    free(self);
    return (NULL);
  }
  tcp_client_methods(self);
  return (self);
}