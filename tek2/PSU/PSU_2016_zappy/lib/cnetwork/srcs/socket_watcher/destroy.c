/*
** destroy.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/socket_watcher/destroy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 23 14:39:39 2017 Antoine FORET
** Last update Tue May 23 14:39:39 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"socket_watcher.h"

void		socket_watcher_destroy(t_socket_watcher *self)
{
  self->clear_tracking(self);
  self->untrack_all(self);
  free(self);
}