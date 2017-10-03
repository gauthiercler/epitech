/*
** welcome_message.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/responses/welcome_message.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 20:50:01 2017 Gauthier Cler
** Last update Mon Jun 05 20:50:01 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	<memory.h>
#include	"common/misc.h"
#include	"client/misc.h"

void		welcome_message(t_client *client)
{
  if (operational)
  {
    display_time();
    if (client->response.nb_args >= 1 &&
      strncmp(client->response.args[1], client->name,
	      strlen(client->response.args[1])) != 0)
      change_user(client, client->response.args[1]);
    if (client->response.message)
      write_in_fd(STDOUT_FILENO, " -|- %s\n", client->response.message);
  }
}