/*
** no_users.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/users/no_users.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 04 17:21:25 2017 Anas Buyumad
** Last update Sun Jun 04 17:21:25 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		throw_error_no_users(t_client *client)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s%s", SERVER_PREFIX,
		   RPL_NOUSERS, ":Nobody logged in", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}