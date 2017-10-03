/*
** error_not_on_channel.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/channel/error_not_on_channel.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 04 16:25:13 2017 Anas Buyumad
** Last update Sun Jun 04 16:25:13 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		throw_error_not_on_channel(t_client *client,
					       char *channel_name)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s %s%s",
		   SERVER_PREFIX, ERR_NOTONCHANNEL,
		   channel_name, ":You're not on that channel", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}