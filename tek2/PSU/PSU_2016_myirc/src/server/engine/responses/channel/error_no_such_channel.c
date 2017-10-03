/*
** error_no_such_channel.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/channel/error_no_such_channel.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jun 03 17:52:21 2017 Anas Buyumad
** Last update Sat Jun 03 17:52:21 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		throw_error_no_such_channel(t_client *client,
						char *channel_name)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s %s%s",
		   SERVER_PREFIX, ERR_NOSUCHCHANNEL,
		   channel_name, ":No such channel", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}