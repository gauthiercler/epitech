/*
** passive_mode.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/passive_mode.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:42:05 2017 Gauthier Cler
** Last update Wed May 10 10:42:05 2017 Gauthier Cler
*/

#include	<arpa/inet.h>
#include	"misc.h"
#include	"socket.h"
#include	"macro.h"

void		passive_mode(t_client *client)
{
  close_previous_connection(client);
  if (!create_socket(&client->data_socket.socket, 0) ||
      !get_ip_address(&client->data_socket.socket))
    return ;
  client->data_socket.socket.port.full =
    ntohs(client->data_socket.socket.addr.sin_port);
  printf("Port => %d\n", client->data_socket.socket.port.full);
  if (dprintf(client->socket.fd, "%d %s (%s,%d,%d).%s",
	  227, "Entering Passive Mode",
  string_replace(inet_ntoa(client->socket.addr.sin_addr), '.', ','),
	  client->data_socket.socket.port.byte[1],
	  client->data_socket.socket.port.byte[0], CRLF) < 0)
  {
    client->active = false;
    return ;
  }
  client->data_socket.type = PASSIVE;
  client->data_socket.active = true;
}