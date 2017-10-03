/*
** compute_timeout.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/compute_timeout.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 22:43:45 2017 Antoine FORET
** Last update Wed Jun 28 22:43:45 2017 Antoine FORET
*/

#include	<stdio.h>
#include	"server.h"

static bool	compute_timeout(t_player *player, long *timeout_tick)
{
  long		self_timeout;

  self_timeout = *timeout_tick;
  if (self_timeout > player->hungry)
    self_timeout = player->hungry;
  if (player->command_list->first(player->command_list) != NULL)
    self_timeout = player->command_list->first(player->command_list)->tick;
  if (self_timeout < *timeout_tick)
    *timeout_tick = self_timeout;
  return (true);
}

long		server_compute_timeout(t_server *self)
{
  long		timeout_tick;

  timeout_tick = DEFAULT_TIMEOUT * self->config.frequency;
  self->players->apply(self->players, (t_list_action)(compute_timeout),
		       &timeout_tick);
  if (timeout_tick < MIN_TIMEOUT)
    timeout_tick = MIN_TIMEOUT;
  return ((timeout_tick / self->config.frequency) * 1000000);
}