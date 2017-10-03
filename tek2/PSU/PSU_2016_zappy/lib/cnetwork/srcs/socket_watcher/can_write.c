/*
** can_write.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/socket_watcher/can_write.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 23 14:13:32 2017 Antoine FORET
** Last update Tue May 23 14:13:32 2017 Antoine FORET
*/

#include		"socket_watcher.h"

bool			socket_watcher_can_write(t_socket_watcher *self,
						     void *socket)
{
  t_socket_tracked	*record;

  record = self->get_record(self, socket);
  if (record == NULL || !FD_ISSET(record->real_socket, &self->write_fds))
    return (false);
  else
    return (true);
}