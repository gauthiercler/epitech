/*
** active_mode.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/active_mode.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:20:16 2017 Gauthier Cler
** Last update Wed May 10 10:20:16 2017 Gauthier Cler
*/

#include		<arpa/inet.h>
#include		<macro.h>
#include		"misc.h"
#include		"socket.h"

static bool		is_valid_ip(t_client *client, int ip[4])
{
  int			ret;
  char			buffer[IP_MAX + 1];

  sprintf(buffer, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
  ret = inet_pton(AF_INET, buffer,
		  &(client->data_socket.socket.addr.sin_addr));
  if (ret != 1)
    return (display_error(__func__, "inet_pton"));
  return (true);
}

static bool		is_valid_port(t_client *client, int port[2])
{
  int			calculated_port;

  calculated_port = port[0] * 256 + port[1];
  if (calculated_port <= 1024 ||
      calculated_port > 65535)
    return (false);
  client->data_socket.socket.port.byte[0] = (uint8_t)port[1];
  client->data_socket.socket.port.byte[1] = (uint8_t)port[0];
  return (true);
}

static bool		is_valid_input(t_client *client)
{
  int			ip[4];
  int			port[2];

  if (sscanf(client->args[1], "%d,%d,%d,%d,%d,%d",
	     &ip[0], &ip[1], &ip[2], &ip[3], &port[0], &port[1]) != 6)
    return (false);
  if (!is_valid_ip(client, ip) || !is_valid_port(client, port))
    return (false);
  return (true);
}

void			active_mode(t_client *client)
{
  char			buffer[IP_MAX + 1];

  close_previous_connection(client);
  if (!client->args[1] || !is_valid_input(client))
    send_response(client, ILLEGAL_PORT);
  else
  {
    client->data_socket.type = ACTIVE;
    client->data_socket.active = true;
    inet_ntop(AF_INET, &(client->data_socket.socket.addr.sin_addr),
	      buffer, IP_MAX);
    send_response(client, PORT_OK);
  }
}