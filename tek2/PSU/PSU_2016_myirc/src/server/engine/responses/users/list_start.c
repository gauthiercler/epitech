/*
** list_start.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/users/list_start.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 04 17:04:56 2017 Anas Buyumad
** Last update Sun Jun 04 17:04:57 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		start_users_listing(t_client *client)
{
  if (!write_in_fd(client->socket.fd, "%s %d %s%s", SERVER_PREFIX,
		   RPL_USERSSTART, ":UserID Terminal Host", CRLF))
    throw_error("vdprintf", __func__, &client->connected, CRITICAL);
}