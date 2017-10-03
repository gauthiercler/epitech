/*
** change_directory.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/change_directory.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:35:36 2017 Gauthier Cler
** Last update Wed May 10 10:35:37 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	<memory.h>
#include 	<malloc.h>
#include 	"misc.h"
#include	"socket.h"
#include	"macro.h"
#include	"ftp.h"

bool		move_dir(const char *path)
{
  if (chdir(path) == CALL_ERROR)
    return (false);
  return (true);
}

bool		replace_root(t_client *client)
{
  char		*buffer;

  if (*client->args[1] != '/' && *client->args[1] != '~')
    return (true);
  buffer = malloc(strlen(client->base_path)
		  + strlen(client->args[1] + 1) + 2);
  if (buffer == NULL)
    return (display_error(__func__, "malloc"));
  sprintf(buffer, "%s/%s", client->base_path, client->args[1] + 1);
  free_ptr(&client->args[1]);
  client->args[1] = buffer;
  return (true);
}

void		change_directory(t_client *client)
{
  if (!client->args[1])
    send_response(client, CWD_FAILED);
  else
  {
    if (!replace_root(client) || !get_abs_path(&client->args[1]))
      send_response(client, CWD_FAILED);
    else if (!move_dir((is_below_root(client->base_path, client->args[1])) ?
		  client->base_path : client->args[1]))
      send_response(client, CWD_FAILED);
    else
      send_response(client, CWD_OK);
  }
}