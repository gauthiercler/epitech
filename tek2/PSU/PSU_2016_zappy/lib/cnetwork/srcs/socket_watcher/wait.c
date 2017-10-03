/*
** wait.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/socket_watcher/wait.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 23 13:08:55 2017 Antoine FORET
** Last update Tue May 23 13:08:55 2017 Antoine FORET
*/

#include		"socket_watcher.h"

static int		get_highest_fd(t_socket_tracked *record, int max)
{
  if (record == NULL)
    return (max);
  if (SOCK_INT(record->real_socket) > max)
    max = SOCK_INT(record->real_socket);
  return (get_highest_fd(record->next, max));
}

bool			socket_watcher_wait(t_socket_watcher *self,
						long timeout)
{
  struct timeval	timeout_value;
  struct timeval	*timer_ptr;

  self->generate_tracking(self);
  timeout_value.tv_sec = timeout / 1000000;
  timeout_value.tv_usec = timeout % 1000000;
  timer_ptr = ((timeout >= 0) ? &timeout_value : NULL);
  if (select(get_highest_fd(self->tracked_sockets, 0) + 1,
	     &self->read_fds, &self->write_fds, NULL, timer_ptr) > 0)
    return (true);
  else
    return (false);
}