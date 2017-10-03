/*
** ftp_server.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/ftp_server.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon May 08 14:03:57 2017 Gauthier Cler
** Last update Mon May 08 14:03:57 2017 Gauthier Cler
*/

#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<signal.h>
#include		"misc.h"
#include		"socket.h"
#include		"macro.h"

bool			get_ip_address(t_socket *socket)
{
  socklen_t		addr_len;

  addr_len = sizeof(socket->addr);
  if (getsockname(socket->fd,
		  (struct sockaddr *)&socket->addr,
		  &addr_len) == CALL_ERROR)
  {
    close_fd(socket->fd);
    return (display_error(__func__, "getsockname"));
  }
  return (true);
}

static bool		server_loop(t_server *server)
{
  t_client		client;
  socklen_t		addr_len;

  addr_len = sizeof(server->socket.addr);
  while (true)
  {
    client.socket.fd = accept(server->socket.fd, (struct sockaddr *)
      &client.socket.addr, &addr_len);
    if (client.socket.fd == CALL_ERROR || !get_ip_address(&client.socket))
      return (false);
    if (!handle_client(&client, server))
      return (false);
  }
  return (true);
}

bool			ftp_server(uint16_t port)
{
  t_server		server;

  if (!create_socket(&server.socket, port))
    return (false);
  signal(SIGCHLD, SIG_IGN);
  server_loop(&server);
  if (!close_fd(server.socket.fd))
    return (false);
  return (true);
}