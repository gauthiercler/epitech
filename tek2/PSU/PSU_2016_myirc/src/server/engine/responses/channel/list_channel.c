/*
** list_channel.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/channel/list_channel.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 04 15:55:39 2017 Anas Buyumad
** Last update Sun Jun 04 15:55:39 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		list_channel(t_client *client, t_channel *channel)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s 1 :No topic%s",
		   SERVER_PREFIX, RPL_LIST, channel->name, CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}