/*
** leaved_channel.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/responses/leaved_channel.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 17:48:05 2017 Gauthier Cler
** Last update Mon Jun 05 17:48:05 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	<memory.h>
#include	"client/misc.h"
#include	"client/channels.h"
#include	"common/misc.h"

void		leaved_channel(t_client *client)
{
  int8_t	channel_id;
  char		*user;

  if (operational && client->response.prefix && client->response.message)
  {
    user = strtok(client->response.prefix, "!");
    if (strncmp(user, client->name,
		strlen(user)) == 0)
    {
      channel_id = remove_channel(client->channels,
				  client->response.message);
      if (channel_id > 0)
	update_channels_ids(client->channels, channel_id);
    }
    display_time();
    write_in_fd(STDOUT_FILENO, " -|- %s leaved channel %s\n",
		user,
		client->response.message);
  }
}