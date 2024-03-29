/*
** error_no_nickname_given.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/nick/error_no_nickname_given.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jun 02 14:03:21 2017 Anas Buyumad
** Last update Fri Jun 02 14:03:21 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		throw_error_no_nickname_given(t_client *client)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s%s", SERVER_PREFIX,
		   ERR_NONICKNAMEGIVEN, ":No nickname given", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}