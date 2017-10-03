/*
** delete.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/delete.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:39:48 2017 Gauthier Cler
** Last update Wed May 10 10:39:49 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	"misc.h"
#include	"socket.h"
#include	"macro.h"

void		delete(t_client *client)
{
  if (!client->args[1] ||
      !replace_root(client) ||
      !get_abs_path(&client->args[1]) ||
      !is_valid_file(client->args[1]) ||
      is_below_root(client->base_path, client->args[1]) ||
      access(client->args[1], W_OK) == CALL_ERROR ||
      unlink(client->args[1]) == CALL_ERROR)
    send_response(client, DELETE_FAILED);
  else
    send_response(client, DELETE_OK);
}