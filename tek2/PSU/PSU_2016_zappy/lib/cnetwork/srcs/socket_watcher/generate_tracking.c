/*
** generate_tracking.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/socket_watcher/generate_tracking.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 23 14:34:27 2017 Antoine FORET
** Last update Tue May 23 14:34:27 2017 Antoine FORET
*/

#include	"socket_watcher.h"

static void	fill_from_record(t_socket_watcher *self,
				    t_socket_tracked *record)
{
  if (record == NULL)
    return ;
  if (record->action & TRACK_READ)
    FD_SET(record->real_socket, &self->read_fds);
  if (record->action & TRACK_WRITE)
    FD_SET(record->real_socket, &self->write_fds);
  return (fill_from_record(self, record->next));
}

void		socket_watcher_generate_tracking(t_socket_watcher *self)
{
  self->clear_tracking(self);
  fill_from_record(self, self->tracked_sockets);
}