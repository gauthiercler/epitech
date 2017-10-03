/*
** set_nickname.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/commands/set_nickname.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 21:18:28 2017 Anas Buyumad
** Last update Thu Jun 01 21:18:28 2017 Anas Buyumad
*/

#include	<memory.h>
#include	<stdio.h>
#include	"common/error.h"
#include	"common/misc.h"
#include	"server/channel_manager.h"
#include	"server/client_manager.h"
#include	"server/engine.h"

static bool	send_nick(t_client *client, int8_t channel_id,
			     char *old_nickname, t_client *user)
{
  if (is_connected_to_channel(client, channel_id) && client->id != user->id)
  {
    if (!write_in_fd(client->socket.fd, ":%s NICK :%s%s",
		     old_nickname, user->name, CRLF))
    {
      throw_error("vdprintf", __func__, &client->connected, CRITICAL);
      return (false);
    }
  }
  return (true);
}

static void	broadcast_change_nickname(t_server *server,
					     t_client *client,
					     char *old_nickname)
{
  size_t	idx;
  size_t	client_idx;
  t_channel	*channel;

  idx = 0;
  client_idx = 0;
  while (idx < MAX_CLIENT_CHANNELS)
  {
    if (client->channels[idx] > 0)
    {
      channel = get_channel_by_id(&server->channel_mgr,
				  (uint8_t)client->channels[idx]);
      while (client_idx < MAX_CLIENTS && channel)
      {
	if (server->client_mgr.clients[client_idx].connected)
	{
	  if (!send_nick(&server->client_mgr.clients[client_idx],
			 client->channels[idx], old_nickname, client))
	    return ;
	}
	client_idx += 1;
      }
    }
    idx += 1;
  }
}

void		set_nickname(t_server *server, t_command *command)
{
  t_client	*client;
  char		*nickname;
  char		old_nickname[CLIENT_NAME_SIZE + 1];

  client = get_client_by_id(&server->client_mgr, command->client_id);
  if (client && client->connected)
  {
    fprintf(stdout, "[Set Nickname]\n");
    memset(old_nickname, 0, CLIENT_NAME_SIZE + 1);
    if (command->nb_args == 0)
      return (throw_error_no_nickname_given(client));
    nickname = command->args[0];
    if (strlen(nickname) > CLIENT_NAME_SIZE
	|| strpbrk(nickname, INVALID_NICK_CHARS))
      return (throw_error_erroneus_nickname(client, nickname));
    if (get_client_by_name(&server->client_mgr, nickname) != NULL)
      return (throw_error_nickname_in_use(client, nickname));
    memcpy(old_nickname, client->name, CLIENT_NAME_SIZE);
    rename_client(&server->client_mgr, client, nickname);
    if (strlen(old_nickname))
      reply_rename_user(client, old_nickname);
    broadcast_change_nickname(server, client, old_nickname);
  }
}