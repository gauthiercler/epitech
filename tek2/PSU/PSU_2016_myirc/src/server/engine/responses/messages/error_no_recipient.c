/*
** error_no_recipient.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/messages/error_no_recipient.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 04 18:00:08 2017 Anas Buyumad
** Last update Sun Jun 04 18:00:08 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		throw_error_no_recipient(t_client *client, char *command)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s (%s)%s", SERVER_PREFIX,
		   ERR_NORECIPIENT, ":No recipient given", command, CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}