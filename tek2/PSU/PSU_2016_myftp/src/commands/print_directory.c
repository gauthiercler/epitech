/*
** print_directory.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/print_directory.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:42:49 2017 Gauthier Cler
** Last update Wed May 10 10:42:50 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	<memory.h>
#include	<limits.h>
#include	"misc.h"
#include	"macro.h"
#include	"ftp.h"

bool		update_pwd(t_client *client)
{
  free_ptr(&client->path);
  client->path = getcwd(NULL, PATH_MAX);
  if (!client->path)
    return (false);
  return (true);
}

void		print_directory(t_client *client)
{
  if (!update_pwd(client))
    return ;
  if (dprintf(client->socket.fd, "%d \"%s%s\"%s", 257,
	  (strlen(client->path + strlen(client->base_path)) == 0) ? "/" : "",
	  client->path + strlen(client->base_path), CRLF) < 0)
    client->active = false;
}