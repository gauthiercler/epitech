/*
** untrack_all.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/socket_watcher/untrack_all.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 23 13:06:50 2017 Antoine FORET
** Last update Tue May 23 13:06:50 2017 Antoine FORET
*/

#include		<malloc.h>
#include		"socket_watcher.h"

static void		clear_tracked(t_socket_tracked *current)
{
  t_socket_tracked	*next;

  if (current == NULL)
    return ;
  next = current->next;
  free(current);
  clear_tracked(next);
}

void			socket_watcher_untrack_all(t_socket_watcher *self)
{
  clear_tracked(self->tracked_sockets);
  self->tracked_sockets = NULL;
}