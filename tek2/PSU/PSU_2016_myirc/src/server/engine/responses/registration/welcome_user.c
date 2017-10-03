/*
** welcome_user.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/registration/welcome_user.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 04 12:13:59 2017 Anas Buyumad
** Last update Sun Jun 04 12:14:00 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		welcome_user(t_client *client)
{
  if (!write_in_fd(client->socket.fd, "%s %03d %s %s%s%s%s",
		   SERVER_PREFIX, RPL_WELCOME, client->name,
		   ":Welcome to the Internet Relay Network ",
		   client->name, "!", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}