/*
** search_record.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/socket_watcher/search_record.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 23 14:03:34 2017 Antoine FORET
** Last update Tue May 23 14:03:34 2017 Antoine FORET
*/

#include		"socket_watcher.h"

static t_socket_tracked	*search_track_record(t_socket_tracked *tracked,
						    void *socket)
{
  if (tracked == NULL)
    return (NULL);
  else if (tracked->socket == socket)
    return (tracked);
  else
    return (search_track_record(tracked->next, socket));
}

t_socket_tracked	*socket_watcher_get_record(t_socket_watcher *self,
						   void *socket)
{
  return (search_track_record(self->tracked_sockets, socket));
}