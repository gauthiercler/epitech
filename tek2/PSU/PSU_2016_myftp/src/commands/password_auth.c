/*
** password_auth.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/password_auth.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:42:36 2017 Gauthier Cler
** Last update Wed May 10 10:42:37 2017 Gauthier Cler
*/

#include	<memory.h>
#include	"socket.h"
#include	"macro.h"

void		password_auth(t_client *client)
{
  if (client->user.logged)
    send_response(client, ALREADY_LOGGED_IN);
  else if (client->user.name == NULL)
    send_response(client, LOGIN_USER_FIRST);
  else if (strcasecmp(client->user.name, LOGIN) == 0)
  {
    client->user.logged = true;
    send_response(client, LOGIN_SUCCESS);
  }
  else
    send_response(client, BAD_LOGIN);
}