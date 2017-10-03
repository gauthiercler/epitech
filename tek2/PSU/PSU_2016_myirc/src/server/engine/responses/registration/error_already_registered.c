/*
** error_already_registered.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/registration/error_already_registered.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Jun 05 15:47:26 2017 Anas Buyumad
** Last update Mon Jun 05 15:47:26 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		throw_error_already_registered(t_client *client)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s%s", SERVER_PREFIX,
		   ERR_ALREADYREGISTERED, ":You may not reregister", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}