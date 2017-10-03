/*
** list_end.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/channel/list_end.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jun 03 21:37:30 2017 Anas Buyumad
** Last update Sat Jun 03 21:37:31 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		stop_channel_listing(t_client *client)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s%s",
		   SERVER_PREFIX, RPL_LISTEND, ":End of /LIST", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}