/*
** list_channel_users.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/commands/list_channel_users.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 21:18:50 2017 Anas Buyumad
** Last update Thu Jun 01 21:18:50 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<memory.h>
#include	"common/error.h"
#include	"common/parser.h"
#include	"server/client_manager.h"
#include	"server/engine.h"

static void	list_all_channels_users(t_client_mgr *client_manager,
					   t_channel_mgr *channel_manager,
					   t_client *client)
{
  size_t	iterator;

  iterator = 0;
  while (iterator < MAX_CHANNELS)
  {
    if (channel_manager->channels[iterator].active && client->connected)
    {
      list_names(client_manager, client,
		 &channel_manager->channels[iterator]);
      if (client->connected)
	stop_names_listing(client,
			   channel_manager->channels[iterator].name);
    }
    iterator += 1;
  }
}

static void	list_matched_channels_users(t_client_mgr *client_manager,
					       t_channel_mgr
					       *channel_manager,
					       t_client *client,
					       char **channels)
{
  size_t	iterator;
  size_t	channel_iterator;

  iterator = 0;
  while (iterator < MAX_CHANNELS)
  {
    channel_iterator = 0;
    while (channels[channel_iterator])
    {
      if (channel_manager->channels[iterator].active && client->connected)
      {
	if (strcmp(channel_manager->channels[iterator].name,
		   channels[channel_iterator]) == 0)
	{
	  list_names(client_manager, client,
		     &channel_manager->channels[iterator]);
	  if (client->connected)
	    stop_names_listing(client,
			       channel_manager->channels[iterator].name);
	}
      }
      channel_iterator += 1;
    }
    iterator += 1;
  }
}

void		list_channel_users(t_server *server, t_command *command)
{
  t_client	*client;
  char		**channels;

  client = get_client_by_id(&server->client_mgr, command->client_id);
  if (client && client->connected)
  {
    fprintf(stdout, "[Names Command]\n");
    if (!client->registered)
      return (throw_error_not_registered(client));
    if (command->nb_args == 0)
      list_all_channels_users(&server->client_mgr,
			      &server->channel_mgr, client);
    else
    {
      if ((channels = split(command->args[0], ",")) == NULL)
	return (throw_error("malloc", __func__, &operational, CRITICAL));
      list_matched_channels_users(&server->client_mgr,
				  &server->channel_mgr, client, channels);
      free(channels);
    }
  }
}