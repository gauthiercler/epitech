/*
** names_end.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/names/names_end.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Jun 05 14:17:54 2017 Anas Buyumad
** Last update Mon Jun 05 14:17:54 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		stop_names_listing(t_client *client, char *channel_name)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s %s%s", SERVER_PREFIX,
		   RPL_ENDOFNAMES, channel_name,
		   ":End of /NAMES list", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}