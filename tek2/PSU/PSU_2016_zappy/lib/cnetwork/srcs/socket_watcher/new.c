/*
** new.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/socket_watcher/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 23 11:37:41 2017 Antoine FORET
** Last update Tue May 23 11:37:41 2017 Antoine FORET
*/

#include		<malloc.h>
#include		"socket_watcher.h"

static void		socket_watcher_methods(t_socket_watcher *self)
{
  self->track = socket_watcher_track;
  self->untrack = socket_watcher_untrack;
  self->untrack_all = socket_watcher_untrack_all;
  self->wait = socket_watcher_wait;
  self->can_read = socket_watcher_can_read;
  self->can_write = socket_watcher_can_write;
  self->get_record_socket = socket_watcher_get_record_socket;
  self->get_record = socket_watcher_get_record;
  self->generate_tracking = socket_watcher_generate_tracking;
  self->clear_tracking = socket_watcher_clear_tracking;
  self->destroy = socket_watcher_destroy;
}

t_socket_watcher	*new_socket_watcher()
{
  t_socket_watcher	*socket_watcher;

  socket_watcher = malloc(sizeof(t_socket_watcher));
  if (socket_watcher == NULL)
    return (NULL);
  FD_ZERO(&socket_watcher->read_fds);
  FD_ZERO(&socket_watcher->write_fds);
  socket_watcher->tracked_sockets = NULL;
  socket_watcher_methods(socket_watcher);
  return (socket_watcher);
}