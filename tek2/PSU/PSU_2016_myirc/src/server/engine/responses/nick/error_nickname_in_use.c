/*
** error_nickname_in_use.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/nick/error_nickname_in_use.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jun 02 14:08:43 2017 Anas Buyumad
** Last update Fri Jun 02 14:08:43 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		throw_error_nickname_in_use(t_client *client,
						char *nickname)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s %s%s", SERVER_PREFIX,
		   ERR_NICKNAMEINUSE, nickname,
		   ":Nickname is already in use", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}