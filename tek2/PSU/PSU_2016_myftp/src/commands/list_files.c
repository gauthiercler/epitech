/*
** list_files.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/list_files.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:41:28 2017 Gauthier Cler
** Last update Wed May 10 10:41:30 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	<errno.h>
#include	<limits.h>
#include	<memory.h>
#include	<ftp.h>
#include	"misc.h"
#include	"socket.h"
#include	"macro.h"

static bool	send_list(t_client *client, FILE *file, t_socket *sock)
{
  char		*buffer;
  size_t	len;

  len = 0;
  buffer = NULL;
  send_response(client, BEFORE_LIST);
  while (getline(&buffer, &len, file) != CALL_ERROR)
  {
    string_replace(buffer, '\n', '\0');
    if (dprintf(sock->fd, "%s%s", buffer, CRLF) < 0)
    {
      client->active = false;
      return (display_error(__func__, "dprintf"));
    }
  }
  free_ptr(&buffer);
  pclose(file);
  send_response(client, AFTER_LIST);
  return (true);
}

static FILE	*call_command(t_client *client, const char *abs_path)
{
  FILE		*file;
  char		*command;

  if (client->path == NULL && !update_pwd(client))
    return (NULL);
  command = concat(LIST_DIR, (client->args[1] && abs_path != NULL &&
			      (strlen(abs_path) >= strlen(client->path)))
			     ? abs_path : client->path);
  if (!command)
    return (NULL);
  file = popen(command, "r");
  if (!file)
  {
    display_error(__func__, "popen");
    return (NULL);
  }
  free(command);
  return (file);
}

static bool	get_command(t_client *client, t_socket *sock)
{
  FILE		*file;
  char		abs_path[PATH_MAX];

  if (client->args[1])
  {
    if (!replace_root(client))
      return (false);
    if (!realpath(client->args[1], abs_path)
	&& errno != ENOENT)
      return (display_error(__func__, "realpath"));
  }
  file = call_command(client, abs_path);
  if (!file)
    return (false);
  return (send_list(client, file, sock));
}

void		list_files(t_client *client)
{
  t_socket	sock;

  if (!client->data_socket.active)
    send_response(client, DATA_NOT_ENABLED);
  else
  {
    if (!activate_data_socket(client, &sock))
      return ;
    if (!get_command(client, &sock))
    {
      send_response(client, BEFORE_LIST);
      send_response(client, AFTER_LIST);
      close_previous_connection(client);
      close_fd(sock.fd);
      return ;
    }
    close_fd(sock.fd);
    close_previous_connection(client);
  }
}