/*
** user_auth.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/user_auth.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:43:23 2017 Gauthier Cler
** Last update Wed May 10 10:43:23 2017 Gauthier Cler
*/

#include	<memory.h>
#include	"misc.h"
#include	"socket.h"

void		user_auth(t_client *client)
{
  if (client->user.logged)
    send_response(client, CANT_SWITCH_GUEST);
  else if (client->args[1])
  {
    free_ptr(&client->user.name);
    client->user.name = strdup(client->args[(!client->args[2]) ? 1 : 0]);
    if (client->user.name == NULL)
    {
      display_error(__func__, "strdup");
      return ;
    }
    send_response(client, SPECIFY_PASS);
  }
  else
    send_response(client, PERMISSION_DENIED);
  return ;
}