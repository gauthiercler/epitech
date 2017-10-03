/*
** names_list.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/responses/names/names_list.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Jun 05 14:20:30 2017 Anas Buyumad
** Last update Mon Jun 05 14:20:30 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/misc.h"
#include	"server/client_manager.h"
#include	"server/engine.h"

static bool	add_name(t_client *client, t_client *user,
			    t_channel *channel, bool *first)
{
  if (is_connected_to_channel(client, channel->id))
  {
    if (!(*first))
    {
      if (!write_in_fd(user->socket.fd, " "))
      {
	throw_error("vdprintf", __func__, &client->connected, CRITICAL);
	return (false);
      }
    }
    if (!write_in_fd(user->socket.fd, "%s", client->name))
    {
      throw_error("vdprintf", __func__, &client->connected, CRITICAL);
      return (false);
    }
    *first ? *first = !(*first) : 0;
  }
  return (true);
}

void		list_names(t_client_mgr *manager, t_client *client,
			       t_channel *channel)
{
  size_t	iterator;
  bool		first;

  first = true;
  iterator = 0;
  if (!write_in_fd(client->socket.fd, "%s %d %s :", SERVER_PREFIX,
		   RPL_NAMREPLY, channel->name))
    return (throw_error("vdprintf", __func__, &client->connected,
			CRITICAL));
  while (iterator < MAX_CLIENTS)
  {
    if (manager->clients[iterator].connected)
    {
      if (!add_name(&manager->clients[iterator], client, channel, &first))
	return ;
    }
    iterator += 1;
  }
  if (!write_in_fd(client->socket.fd, "%s", CRLF))
    return (throw_error("vdprintf", __func__, &client->connected,
			CRITICAL));
}