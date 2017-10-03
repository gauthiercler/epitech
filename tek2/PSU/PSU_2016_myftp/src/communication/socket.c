/*
** socket.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/socket.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon May 08 17:04:22 2017 Gauthier Cler
** Last update Mon May 08 17:04:22 2017 Gauthier Cler
*/

#include		<stdio.h>
#include		<stdbool.h>
#include		"misc.h"
#include		"ftp.h"
#include		"macro.h"

static bool		listen_on_socket(int sock)
{
  if (listen(sock, MAX_BACKLOG_VALUE) == CALL_ERROR)
  {
    close_fd(sock);
    return (display_error(__func__, "listen"));
  }
  return (true);
}

static bool		bind_socket(int sock, struct sockaddr_in name)
{
  if (bind(sock, (struct sockaddr *)&name, sizeof(name)) == CALL_ERROR)
  {
    close_fd(sock);
    return (display_error(__func__, "bind"));
  }
  return (true);
}

bool			create_socket(t_socket *sock, uint16_t port)
{
  sock->fd = socket(PF_INET, SOCK_STREAM, 0);
  if (sock->fd == CALL_ERROR)
    return (display_error(__func__, "socket"));
  sock->addr.sin_family = AF_INET;
  sock->addr.sin_port = (port) ? htons(port) : port;
  sock->addr.sin_addr.s_addr = htonl(INADDR_ANY);
  if (!bind_socket(sock->fd, sock->addr)
      || !listen_on_socket(sock->fd))
    return (false);
  return (true);
}
