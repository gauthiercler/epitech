/*
** download_file.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/download_file.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:40:27 2017 Gauthier Cler
** Last update Wed May 10 10:40:28 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	<sys/stat.h>
#include	<sys/sendfile.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<libgen.h>
#include	"misc.h"
#include	"socket.h"
#include	"macro.h"

static bool	send_file(t_client *client, t_socket *sock)
{
  int		fd;
  struct stat	file_stat;

  fd = open(client->args[1], O_RDONLY);
  if (fd == CALL_ERROR)
    return (display_error(__func__, "open"));
  if (fstat(fd, &file_stat) == CALL_ERROR)
    return (display_error(__func__, "fstat"));
  if (dprintf(client->socket.fd, "%d %s %s (%ld bytes).%s", 150,
	  "Opening ASCII mode data connection for", basename(client->args[1]),
	  file_stat.st_size, CRLF) < 0)
  {
    client->active = false;
    return (display_error(__func__, "dprintf"));
  }
  if (sendfile(sock->fd, fd, NULL,
	       file_stat.st_size) == CALL_ERROR)
    return (display_error(__func__, "sendfile"));
  send_response(client, TRANSFER_COMPLETE);
  close_fd(fd);
  return (true);
}

static bool	send_file_control(t_client *client, t_socket *sock)
{
  if (!send_file(client, sock))
  {
    close_previous_connection(client);
    send_response(client, FILE_OPEN_FAILED);
    return (false);
  }
  return (true);
}

static bool	is_valid_command(t_client *client)
{
  if (!replace_root(client) ||
      !get_abs_path(&client->args[1]) ||
      !is_valid_file(client->args[1]) ||
      is_below_root(client->base_path, client->args[1]) ||
      access(client->args[1], R_OK) == CALL_ERROR)
  {
    send_response(client, FILE_OPEN_FAILED);
    return (false);
  }
  return (true);
}

void		download_file(t_client *client)
{
  t_socket	sock;

  if (!client->data_socket.active)
    send_response(client, DATA_NOT_ENABLED);
  else if (!client->args[1])
    send_response(client, UNKNOWN_COMMAND);
  else
  {
    if (!is_valid_command(client) ||
	!activate_data_socket(client, &sock) ||
	!send_file_control(client, &sock))
      return ;
    close_fd(sock.fd);
    close_previous_connection(client);
  }
}
