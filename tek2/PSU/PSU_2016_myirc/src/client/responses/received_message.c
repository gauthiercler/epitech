/*
** received_message.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/responses/received_message.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 17:48:19 2017 Gauthier Cler
** Last update Mon Jun 05 17:48:19 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	<memory.h>
#include	"common/misc.h"
#include	"client/misc.h"

void		received_message(t_client *client)
{
  if (operational &&
    client->response.nb_args >= 1 &&
    client->response.message &&
    client->response.prefix)
  {
    display_time();
    if (strncmp(client->name, client->response.args[1],
		strlen(client->response.args[1])) != 0)
      write_in_fd(STDOUT_FILENO, " %s", client->response.args[1]);
    write_in_fd(STDOUT_FILENO, " <%s> %s\n",
		strtok(client->response.prefix, "!"),
		client->response.message);
  }
}