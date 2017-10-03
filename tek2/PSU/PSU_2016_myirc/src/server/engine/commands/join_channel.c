/*
** join_channel.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/commands/join_channel.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 21:18:59 2017 Anas Buyumad
** Last update Thu Jun 01 21:18:59 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<memory.h>
#include	"common/error.h"
#include	"common/parser.h"
#include	"server/channel_manager.h"
#include	"server/client_manager.h"
#include	"server/engine.h"

static void	join_single_channel(t_server *server, t_client *client,
				       char *channel_name)
{
  t_channel	*channel;

  fprintf(stdout, "[Join Channel]\n");
  if (strlen(channel_name) > CHANNEL_NAME_SIZE ||
    !strpbrk(channel_name, CHANNEL_SUFFIX))
    return (throw_error_no_such_channel(client, channel_name));
  if (client->active_channels == MAX_CLIENT_CHANNELS)
    return (throw_error_too_many_channels(client, channel_name));
  channel = get_channel_by_name(&server->channel_mgr, channel_name);
  if (!channel)
  {
    if (!create_channel(&server->channel_mgr, channel_name))
      return ;
    if ((channel = get_channel_by_name(&server->channel_mgr,
				       channel_name)) == NULL)
      return ;
  }
  fprintf(stdout, "[Joinning Channel]\nName -> %s\n", channel_name);
  if (!add_channel_to_client(client, channel->id))
    return (throw_error_too_many_channels(client, channel_name));
  join_broadcast(&server->client_mgr, client, channel);
  list_names(&server->client_mgr, client, channel);
  stop_names_listing(client, channel->name);
}

static void	join_channels(t_server *server, t_client *client,
				 char **channels)
{
  size_t	iterator;

  iterator = 0;
  while (channels[iterator])
  {
    if (client->connected)
      join_single_channel(server, client, channels[iterator]);
    iterator += 1;
  }
}

void		join_channel(t_server *server, t_command *command)
{
  t_client	*client;
  char		**channels;

  client = get_client_by_id(&server->client_mgr, command->client_id);
  if (client && client->connected)
  {
    fprintf(stdout, "[Join Command]\n");
    if (!client->registered)
      return (throw_error_not_registered(client));
    if (command->nb_args == 0)
      return (throw_error_need_more_params(client, "JOIN"));
    if ((channels = split(command->args[0], ",")) == NULL)
      return (throw_error("malloc", __func__, &operational, CRITICAL));
    join_channels(server, client, channels);
    free(channels);
  }
}