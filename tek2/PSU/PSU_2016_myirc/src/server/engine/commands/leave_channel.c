/*
** leave_channel.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/commands/leave_channel.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 21:18:55 2017 Anas Buyumad
** Last update Thu Jun 01 21:18:55 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"common/error.h"
#include	"common/parser.h"
#include	"server/channel_manager.h"
#include	"server/client_manager.h"
#include	"server/engine.h"

void		part_single_channel(t_server *server, t_client *client,
					char *channel_name)
{
  t_channel	*channel;

  fprintf(stdout, "[Part Channel]");
  if ((channel = get_channel_by_name(&server->channel_mgr,
				     channel_name)) == NULL)
    return (throw_error_no_such_channel(client, channel_name));
  if (!is_connected_to_channel(client, channel->id))
    return (throw_error_not_on_channel(client, channel_name));
  if (!remove_channel_of_client(client, channel->id))
    return ;
  part_broadcast(&server->client_mgr, client, channel);
  if (get_nb_connected_on_channel(&server->client_mgr, channel->id) == 0)
    remove_channel_by_id(&server->channel_mgr, channel->id);
}

static void	part_channels(t_server *server, t_client *client,
				 char **channels)
{
  size_t	iterator;

  iterator = 0;
  while (channels[iterator])
  {
    if (client->connected)
      part_single_channel(server, client, channels[iterator]);
    iterator += 1;
  }
}

void		leave_channel(t_server *server, t_command *command)
{
  t_client	*client;
  char		**channels;

  client = get_client_by_id(&server->client_mgr, command->client_id);
  if (client && client->connected)
  {
    fprintf(stdout, "[Part Command]");
    if (!client->registered)
      return (throw_error_not_registered(client));
    if (command->nb_args == 0)
      return (throw_error_need_more_params(client, "PART"));
    if ((channels = split(command->args[0], ",")) == NULL)
      return (throw_error("malloc", __func__, &operational, CRITICAL));
    part_channels(server, client, channels);
    free(channels);
  }
}