/*
** can_read.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/socket_watcher/can_read.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 23 14:01:25 2017 Antoine FORET
** Last update Tue May 23 14:01:25 2017 Antoine FORET
*/

#include		"socket_watcher.h"

bool			socket_watcher_can_read(t_socket_watcher *self,
						    void *socket)
{
  t_socket_tracked	*record;

  record = self->get_record(self, socket);
  if (record == NULL || !FD_ISSET(record->real_socket, &self->read_fds))
    return (false);
  else
    return (true);
}