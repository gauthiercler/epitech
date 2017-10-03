/*
** error_need_more_params.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/common/error_need_more_params.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jun 03 16:54:28 2017 Anas Buyumad
** Last update Sat Jun 03 16:54:28 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		throw_error_need_more_params(t_client *client,
						 char *command)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s %s%s", SERVER_PREFIX,
		   ERR_NEEDMOREPARAMS, command,
		   ":Not enough parameters", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}