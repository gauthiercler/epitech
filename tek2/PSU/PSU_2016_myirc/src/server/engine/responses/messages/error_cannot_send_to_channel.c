/*
** error_cannot_send_to_channel.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/messages/error_cannot_send_to_channel.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 04 17:42:51 2017 Anas Buyumad
** Last update Sun Jun 04 17:42:51 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		throw_error_cannot_send_to_channel(t_client *client,
						       char *channel_name)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s %s%s", SERVER_PREFIX,
		   ERR_CANNOTSENDTOCHAN, channel_name,
		   ":Cannot send to channel", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}