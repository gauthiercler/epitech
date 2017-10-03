/*
** list_channels.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/commands/list_channels.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 21:18:47 2017 Anas Buyumad
** Last update Thu Jun 01 21:18:47 2017 Anas Buyumad
*/

#include	<memory.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"common/error.h"
#include	"common/parser.h"
#include	"server/client_manager.h"
#include	"server/engine.h"

static void	list_all_channels(t_channel_mgr *manager,
				     t_client *client)
{
  size_t	iterator;

  iterator = 0;
  start_channel_listing(client);
  while (iterator < MAX_CHANNELS)
  {
    if (manager->channels[iterator].active)
      if (client->connected)
	list_channel(client, &manager->channels[iterator]);
    iterator += 1;
  }
  if (client->connected)
    stop_channel_listing(client);
}

static void	list_matched_channels(t_channel_mgr *manager,
					 t_client *client,
					 char **channels)
{
  size_t	iterator;
  size_t	channel_iterator;

  iterator = 0;
  start_channel_listing(client);
  while (iterator < MAX_CHANNELS)
  {
    channel_iterator = 0;
    while (channels[channel_iterator])
    {
      if (manager->channels[iterator].active && client->connected)
	if (strstr(manager->channels[iterator].name,
		   channels[channel_iterator]))
	  list_channel(client, &manager->channels[iterator]);
      channel_iterator += 1;
    }
    iterator += 1;
  }
  if (client->connected)
    stop_channel_listing(client);
}

void		list_channels(t_server *server,
				  t_command *command)
{
  t_client	*client;
  char		**channels;

  client = get_client_by_id(&server->client_mgr, command->client_id);
  if (client && client->connected)
  {
    fprintf(stdout, "[List Command]\n");
    if (!client->registered)
      return (throw_error_not_registered(client));
    if (command->nb_args == 0)
      list_all_channels(&server->channel_mgr, client);
    else
    {
      if ((channels = split(command->args[0], ",")) == NULL)
	return (throw_error("malloc", "join_channel",
			    &operational, CRITICAL));
      list_matched_channels(&server->channel_mgr, client, channels);
      free(channels);
    }
  }
}