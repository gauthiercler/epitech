/*
** clear_tracking.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/socket_watcher/clear_tracking.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 23 14:38:48 2017 Antoine FORET
** Last update Tue May 23 14:38:48 2017 Antoine FORET
*/

#include	"socket_watcher.h"

void		socket_watcher_clear_tracking(t_socket_watcher *self)
{
  FD_ZERO(&self->read_fds);
  FD_ZERO(&self->write_fds);
}