/*
** list_start.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/channel/list_start.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jun 03 21:35:26 2017 Anas Buyumad
** Last update Sat Jun 03 21:35:26 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		start_channel_listing(t_client *client)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s %s%s", SERVER_PREFIX,
		   RPL_LISTSTART, "Channel", ":Users Name", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}