/*
** data_socket.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/communication/data_socket.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue May 16 00:13:20 2017 Gauthier Cler
** Last update Tue May 16 00:13:20 2017 Gauthier Cler
*/

#include	"macro.h"
#include	"socket.h"
#include	"misc.h"

static bool	open_connection(t_client *client, t_socket *sock)
{
  sock->fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock->fd == CALL_ERROR)
    return (display_error(__func__, "socket"));
  sock->addr.sin_family = AF_INET;
  sock->addr.sin_addr = client->data_socket.socket.addr.sin_addr;
  sock->addr.sin_port = htons(client->data_socket.socket.port.full);
  if (connect(sock->fd, (struct sockaddr *)&sock->addr, sizeof(sock->addr))
      == CALL_ERROR)
  {
    close_fd(sock->fd);
    return (display_error(__func__, "connect"));
  }
  return (true);
}

bool		activate_data_socket(t_client *client, t_socket *sock)
{
  bool		ret;

  ret = true;
  if (client->data_socket.type == PASSIVE &&
    !accept_connection(client, sock))
    ret = false;
  else if (client->data_socket.type == ACTIVE &&
	   !open_connection(client, sock))
    ret = false;
  if (ret == false)
  {
    close_previous_connection(client);
    send_response(client, CONNECTION_FAILED);
  }
  return (ret);
}

void		close_previous_connection(t_client *client)
{
  if (client->data_socket.active)
  {
    if (client->data_socket.type == PASSIVE)
      close_fd(client->data_socket.socket.fd);
    client->data_socket.active = false;
  }
}