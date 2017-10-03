/*
** untrack.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/socket_watcher/untrack.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 23 12:40:34 2017 Antoine FORET
** Last update Tue May 23 12:40:34 2017 Antoine FORET
*/

#include		<malloc.h>
#include		"socket_watcher.h"

static t_socket_tracked	*search_prev_track_record(t_socket_tracked
							 *previous,
							 t_socket_tracked
							 *current,
							 void *socket)
{
  if (current == NULL)
    return (NULL);
  else if (current->socket == socket)
    return (previous);
  else
    return (search_prev_track_record(current, current->next, socket));
}

static void		remove_first_record(t_socket_watcher *self)
{
  t_socket_tracked	*record;

  record = self->tracked_sockets;
  self->tracked_sockets = self->tracked_sockets->next;
  if (record != NULL)
    free(record);
}

static void		remove_after(t_socket_tracked *prev)
{
  t_socket_tracked	*record;

  record = prev->next;
  prev->next = ((record != NULL) ? record->next : NULL);
  if (record != NULL)
    free(record);
}

void			socket_watcher_untrack(t_socket_watcher *self,
						   void *socket)
{
  t_socket_tracked	*record;

  if (self->tracked_sockets != NULL
      && self->tracked_sockets->socket == socket)
    return (remove_first_record(self));
  record = search_prev_track_record(NULL, self->tracked_sockets, socket);
  if (record != NULL && record->next != NULL)
    remove_after(record);
}