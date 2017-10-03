/*
** accept.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/accept.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun May 14 17:05:44 2017 Gauthier Cler
** Last update Sun May 14 17:05:44 2017 Gauthier Cler
*/

#include 	<stdbool.h>
#include 	"misc.h"
#include 	"macro.h"

bool		accept_connection(t_client *client, t_socket *sock)
{
  socklen_t	len;

  len = sizeof(sock);
  sock->fd = accept(client->data_socket.socket.fd,
		    (struct sockaddr *)&sock->addr, &len);
  if (sock->fd == CALL_ERROR)
    return (display_error(__func__, "accept"));
  return (true);
}