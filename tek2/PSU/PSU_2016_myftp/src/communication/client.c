/*
** client.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/client.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue May 09 22:22:23 2017 Gauthier Cler
** Last update Tue May 09 22:22:23 2017 Gauthier Cler
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		<memory.h>
#include		<limits.h>
#include		"misc.h"
#include		"socket.h"
#include		"macro.h"
#include		"ftp.h"

static bool		init_client(t_client *client)
{
  client->data_socket.active = false;
  client->data_socket.type = ACTIVE;
  client->path = NULL;
  client->user.name = NULL;
  client->user.logged = false;
  client->input = NULL;
  client->args = NULL;
  client->active = true;
  client->message_length = MAX_MESSAGE_LENGTH + 1;
  client->base_path = getcwd(NULL, PATH_MAX);
  if (client->base_path == NULL)
    return (false);
  return (true);
}

static bool		client_loop(t_client *client)
{
  printf("Opening client\n");
  client->stream_fd = fdopen(client->socket.fd, "r+");
  send_response(client, GREETINGS);
  while (client->active && get_client_input(client) > 0)
    if (!handle_command(client))
    {
      free_tab(client->args);
      free(client->args);
      break ;
    }
  printf("Quitting client\n");
  free_ptr(&client->input);
  free_ptr(&client->user.name);
  free_ptr(&client->path);
  free_ptr(&client->base_path);
  if (!close_filestream(client->stream_fd))
    return (false);
  return (true);
}

bool			handle_client(t_client *client, t_server *server)
{
  pid_t			pid;

  pid = fork();
  if (pid == CALL_ERROR)
  {
    close_fd(client->socket.fd);
    return (false);
  }
  else if (pid > 0)
  {
    if (!close_fd(client->socket.fd))
      return (false);
  }
  else
  {
    close_fd(server->socket.fd);
    if (!init_client(client))
      return (false);
    client_loop((client));
    exit(EXIT_SUCCESS);
  }
  return (true);
}