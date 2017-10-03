/*
** join_broadcast.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/common/join_broadcast.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jun 03 17:52:00 2017 Anas Buyumad
** Last update Sat Jun 03 17:52:00 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	"common/error.h"
#include	"common/misc.h"
#include	"server/channel_manager.h"
#include	"server/client_manager.h"
#include	"server/engine.h"

void		join_broadcast(t_client_mgr *manager, t_client *user,
				   t_channel *channel)
{
  size_t	iterator;

  iterator = 0;
  fprintf(stdout, "[Broadcasting Join]\n");
  fprintf(stdout, "Channel -> %s\n", channel->name);
  dump_client(user);
  while (iterator < MAX_CLIENTS)
  {
    if (manager->clients[iterator].connected)
    {
      if (is_connected_to_channel(&manager->clients[iterator], channel->id))
      {
	if (!write_in_fd(manager->clients[iterator].socket.fd,
			 ":%s JOIN :%s%s", user->name,
			 channel->name, CRLF))
	  throw_error("vdprintf", __func__,
		      &manager->clients[iterator].connected, CRITICAL);
      }
    }
    iterator += 1;
  }
}