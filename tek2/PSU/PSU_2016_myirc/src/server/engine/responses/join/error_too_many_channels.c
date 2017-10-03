/*
** error_too_many_channels.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/join/error_too_many_channels.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jun 03 16:57:12 2017 Anas Buyumad
** Last update Sat Jun 03 16:57:13 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		throw_error_too_many_channels(t_client *client,
						  char *channel_name)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s %s%s", SERVER_PREFIX,
		   ERR_TOOMANYCHANNELS, channel_name,
		   ":You have joined too many channels", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}