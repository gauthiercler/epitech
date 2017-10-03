/*
** joined_channel.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/responses/joined_channel.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 17:47:53 2017 Gauthier Cler
** Last update Mon Jun 05 17:47:54 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	<memory.h>
#include 	"client/misc.h"
#include	"client/channels.h"
#include	"common/misc.h"

void		joined_channel(t_client *client)
{
  char		*user;

  if (operational && client->response.message && client->response.prefix)
  {
    user = strtok(client->response.prefix, "!");
    if (strncmp(user, client->name,
		strlen(user)) == 0)
      add_channel(client->channels, client->response.message);
    display_time();
    write_in_fd(STDOUT_FILENO, " -|- %s joined channel %s\n",
		user,
		client->response.message);
  }
}