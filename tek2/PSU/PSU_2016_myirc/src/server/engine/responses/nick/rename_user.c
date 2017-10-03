/*
** rename_user.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/nick/rename_user.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Jun 06 11:24:50 2017 Anas Buyumad
** Last update Tue Jun 06 11:24:50 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		reply_rename_user(t_client *client, char *oldname)
{
  if (!write_in_fd(client->socket.fd, ":%s NICK :%s%s",
		   oldname, client->name, CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}