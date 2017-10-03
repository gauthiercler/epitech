/*
** changed_username.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/responses/changed_username.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 19:30:40 2017 Gauthier Cler
** Last update Mon Jun 05 19:30:40 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	<memory.h>
#include	"client/misc.h"
#include	"common/misc.h"

void		changed_username(t_client *client)
{
  char		*new_name;
  char		*old_name;

  if (operational && client->response.prefix &&
    (client->response.args[1] || client->response.message))
  {
    new_name = (client->response.args[1] ? client->response.args[1]
				     : client->response.message);
    if ((old_name = strtok(client->response.prefix, "!")) == NULL)
      return ;
    if (strncmp(old_name, client->name,
		strlen(client->name)) == 0)
      change_user(client, new_name);
    display_time();
    write_in_fd(STDOUT_FILENO, " -|- %s changed username to %s\n", old_name,
		new_name);
  }
}