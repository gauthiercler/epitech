/*
** handle_network.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/handle_network.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 16:06:08 2017 Antoine FORET
** Last update Wed Jun 28 16:06:08 2017 Antoine FORET
*/

#include	<stdio.h>
#include	"server.h"

void		server_handle_network(t_server *self)
{
  self->generate_tracking(self);
  if (self->watcher->wait(self->watcher, self->compute_timeout(self)))
  {
    self->clean_players(self);
    self->clean_gfx(self);
    self->accept_clients(self);
    self->receive_data(self);
    self->send_data(self);
    self->clean_players(self);
    self->clean_gfx(self);
  }
}
