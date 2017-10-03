/*
** upload_file.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/upload_file.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:43:13 2017 Gauthier Cler
** Last update Wed May 10 10:43:14 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	<memory.h>
#include	<libgen.h>
#include	<limits.h>
#include	<fcntl.h>
#include	<macro.h>
#include	<stdlib.h>
#include	<errno.h>
#include	"misc.h"
#include	"socket.h"

static bool	write_in_file(t_client *client, t_socket *sock)
{
  int		file;
  char		buffer[MAX_MESSAGE_LENGTH + 1];
  ssize_t	read_count;

  send_response(client, OK_SEND_DATA);
  file = creat(client->args[1], 0644);
  if (file == CALL_ERROR)
  {
    close_fd(file);
    return (display_error(__func__, "creat"));
  }
  while ((read_count = read(sock->fd, buffer, MAX_MESSAGE_LENGTH)) > 0
	 || (errno == EAGAIN || errno == EINTR))
    write(file, buffer, (size_t)read_count);
  close_fd(file);
  send_response(client, TRANSFER_COMPLETE);
  return (true);
}

static bool	get_dir_path(const char *path, char *dir_path)
{
  strcpy(dir_path, path);
  dirname(dir_path);
  return (true);
}

static bool	is_valid_command(t_client *client)
{
  char		*dir_path;

  dir_path = malloc(PATH_MAX);
  if (!dir_path)
    return (display_error(__func__, "malloc"));
  memset(dir_path, 0, PATH_MAX);
  if (index(client->args[1], '/') != NULL &&
      (!replace_root(client) ||
       !get_dir_path(client->args[1], dir_path) ||
       !get_abs_path(&dir_path) ||
       is_below_root(client->base_path, dir_path)))
  {
    free_ptr(&dir_path);
    return (false);
  }
  free_ptr(&dir_path);
  return (true);
}

void		upload_file(t_client *client)
{
  t_socket	sock;

  if (!client->data_socket.active)
    send_response(client, DATA_NOT_ENABLED);
  else if (!client->args[1])
    send_response(client, FILE_CREATE_FAILED);
  else
  {
    if (!is_valid_command(client))
    {
      send_response(client, FILE_CREATE_FAILED);
      return ;
    }
    if (!activate_data_socket(client, &sock))
      return ;
    if (!write_in_file(client, &sock))
      send_response(client, FILE_CREATE_FAILED);
    close_fd(sock.fd);
    close_previous_connection(client);
  }
}