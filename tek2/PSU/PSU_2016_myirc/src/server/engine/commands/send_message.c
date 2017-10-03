/*
** send_message.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/commands/send_message.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 21:18:34 2017 Anas Buyumad
** Last update Thu Jun 01 21:18:35 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<memory.h>
#include	"common/error.h"
#include	"common/misc.h"
#include	"common/parser.h"
#include	"server/channel_manager.h"
#include	"server/client_manager.h"
#include	"server/engine.h"

static void	send_message_to_client(t_client *client, t_client *user,
					  char *recipient,
					  char *message)
{
  if (client->connected)
  {
    if (!write_in_fd(client->socket.fd, ":%s PRIVMSG %s %s%s",
		     user->name, recipient, message, CRLF))
      return (throw_error("vdprintf", __func__,
			  &client->connected, CRITICAL));
  }
}

static void	send_message_to_channel(t_client_mgr *manager,
					   t_channel *channel,
					   t_client *user,
					   char *message)
{
  size_t	iterator;

  iterator = 0;
  while (iterator < MAX_CLIENTS)
  {
    if (manager->clients[iterator].connected)
    {
      if (is_connected_to_channel(&manager->clients[iterator],
				  channel->id) &&
	manager->clients[iterator].id != user->id)
	send_message_to_client(&manager->clients[iterator],
			       user, channel->name, message);
    }
    iterator += 1;
  }
}

static void	send_message_to_recipients(t_server *server,
					      t_client *user,
					      char **recipients,
					      char *message)
{
  t_channel	*channel;
  t_client	*client;
  size_t	iterator;

  iterator = 0;
  while (recipients[iterator])
  {
    channel = get_channel_by_name(&server->channel_mgr,
				  recipients[iterator]);
    client = get_client_by_name(&server->client_mgr,
				recipients[iterator]);
    if (channel)
      send_message_to_channel(&server->client_mgr, channel, user, message);
    else if (client)
      send_message_to_client(client, user, client->name, message);
    else
      throw_error_no_such_nick(user, recipients[iterator]);
    iterator += 1;
  }
}

void		send_message(t_server *server, t_command *command)
{
  t_client	*client;
  char		**receivers;

  client = get_client_by_id(&server->client_mgr, command->client_id);
  if (client && client->connected)
  {
    fprintf(stdout, "[Message Command]\n");
    if (!client->registered)
      return (throw_error_not_registered(client));
    if (command->nb_args < 1)
      return (throw_error_no_recipient(client, "PRIVMSG"));
    else if (command->nb_args < 2)
      return (throw_error_no_text_to_send(client));
    if ((receivers = split(command->args[0], ",")) == NULL)
      return (throw_error("malloc", __func__, &operational, CRITICAL));
    send_message_to_recipients(server, client, receivers,
			       command->raw_input + strlen("PRIVMSG")
			       + strlen(command->args[0]) + 2);
    free(receivers);
  }
}