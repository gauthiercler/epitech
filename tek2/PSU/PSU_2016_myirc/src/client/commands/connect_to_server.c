/*
** connect_to_server.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/commands/connect_to_server.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue May 30 18:41:09 2017 Gauthier Cler
** Last update Tue May 30 18:41:09 2017 Gauthier Cler
*/

#include		<unistd.h>
#include		<netdb.h>
#include		<stdlib.h>
#include		"client/misc.h"
#include		"common/misc.h"
#include		"memory.h"
#include		"common/error.h"
#include		"client/commands.h"
#include		"common/socket.h"

static bool		resolve_host(const char *input,
					struct sockaddr_in *addr)
{
  struct hostent	*host;

  host = gethostbyname(input);
  if (!host)
  {
    throw_error("gethostbyname", __func__, &operational, MINOR);
    return (false);
  }
  if (host->h_addr_list && host->h_addr_list[0])
    memcpy(&addr->sin_addr, host->h_addr_list[0], (size_t)host->h_length);
  else
    return (false);
  return (true);
}

static bool		setup_connection(t_client *client)
{
  char			*host;
  char			*port;

  host = strtok(client->command.args[1], ":");
  if (!host)
    return (false);
  port = strtok(NULL, ":");
  if (!resolve_host(host, &client->socket.address))
    return (false);
  client->socket.address.sin_family = AF_INET;
  client->socket.address.sin_port =
    htons((uint16_t)((port) ? atoi(port) : 6667));
  return (true);
}

static bool		try_to_connect(t_socket *socket)
{
  create_socket(socket);
  if (!connect_socket(socket))
    return (false);
  return (true);
}

void			connect_to_server(t_client *client)
{
  if (operational)
  {
    if (client->command.nb_args >= 1)
    {
      if (client->connected)
	close_connection(client);
      if (setup_connection(client) &&
	try_to_connect(&client->socket))
      {
	write_in_fd(STDOUT_FILENO, "Connected to %s\n",
		    client->command.args[1]);
	client->connected = true;
      }
    }
    else
      write_in_fd(STDOUT_FILENO, "%s"
	"connect : Not enough arguments given\n");
  }
}