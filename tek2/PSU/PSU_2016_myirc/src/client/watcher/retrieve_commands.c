/*
** retrieve_commands.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/watcher/retrieve_commands.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jun 01 15:23:39 2017 Gauthier Cler
** Last update Thu Jun 01 15:23:39 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<memory.h>
#include	"client/commands.h"
#include	"common/misc.h"
#include	"client/parser.h"

static void	get_line_input(t_client *client)
{
  char		*line;
  size_t	size;
  char		*line_feed;

  line = NULL;
  if (operational)
  {
    if (getline(&line, &size, stdin) == SYSCALL_FAIL)
      operational = false;
    else
    {
      if (strlen(line) < MSG_MAX_SIZE)
      {
	if ((line_feed = strchr(line, '\n')) != NULL)
	  *line_feed = '\0';
	memcpy(client->command.raw_input, line, strlen(line));
      }
    }
    free_ptr((void *)&line);
  }
}

static void	get_socket_input(t_client *client)
{
  if (operational)
  {
    if (!build_buffer_command(client))
    {
      if (operational && ring_buffer_is_full(&client->ring_buffer))
      {
	client->discard_command = true;
	ring_buffer_discard_data(&client->ring_buffer);
      }
      read_input_data(client);
    }
  }
}

void		retrieve_commands(t_client *client)
{
  if (operational)
  {
    if (FD_ISSET(STDIN_FILENO, &client->watcher.read_watcher))
    {
      get_line_input(client);
      if (build_command(&client->command))
	execute_command(client);
      clean_command(&client->command);
    }
    if (client->connected &&
	FD_ISSET(client->socket.fd, &client->watcher.read_watcher))
      get_socket_input(client);
    if (!ring_buffer_is_empty(&client->ring_buffer))
      build_buffer_command(client);
  }
}