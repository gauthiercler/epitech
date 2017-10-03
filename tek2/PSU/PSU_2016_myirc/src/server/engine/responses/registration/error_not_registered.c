/*
** error_not_registered.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/registration/error_not_registered.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Jun 05 15:49:17 2017 Anas Buyumad
** Last update Mon Jun 05 15:49:17 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		throw_error_not_registered(t_client *client)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s%s", SERVER_PREFIX,
		   ERR_NOTREGISTERED, ":You have not registered", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}