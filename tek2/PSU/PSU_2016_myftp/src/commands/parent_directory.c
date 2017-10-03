/*
** parent_directory.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/parent_directory.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:41:53 2017 Gauthier Cler
** Last update Wed May 10 10:41:53 2017 Gauthier Cler
*/

#include	<memory.h>
#include	<stdlib.h>
#include	<limits.h>
#include	"misc.h"
#include	"socket.h"
#include	"ftp.h"

static bool	get_abs_path_parent(char **path)
{
  char		*buffer;

  buffer = malloc(PATH_MAX + 1);
  if (!buffer)
    return (false);
  if (realpath(*path, buffer) == NULL)
  {
    free(buffer);
    return (false);
  }
  free_ptr(path);
  *path = buffer;
  return (true);
}

void		parent_directory(t_client *client)
{
  char		*abs_path;

  abs_path = strdup("..");
  if (!abs_path || !get_abs_path_parent(&abs_path)
      || !move_dir((is_below_root(client->base_path, abs_path)) ?
		     client->base_path : abs_path))
    send_response(client, CWD_FAILED);
  else
    send_response(client, CWD_OK);
  free_ptr(&abs_path);
}