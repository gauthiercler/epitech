/*
** list_users.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/users/list_users.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 04 17:04:52 2017 Anas Buyumad
** Last update Sun Jun 04 17:04:52 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/engine.h"

void		list_server_users(t_client_mgr *manager, t_client *client)
{
  size_t	iterator;

  iterator = 0;
  while (iterator < MAX_CLIENTS)
  {
    if (manager->clients[iterator].connected)
    {
      if (!write_in_fd(client->socket.fd, "%s %d %s%s", SERVER_PREFIX,
		       RPL_USERS, &manager->clients[iterator].name, CRLF))
	return (throw_error("vdprintf", __func__,
			    &client->connected, CRITICAL));
    }
    iterator += 1;
  }
}