/*
** tick.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/tick.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 15:22:15 2017 Antoine FORET
** Last update Thu Jun 29 15:22:15 2017 Antoine FORET
*/

#include	<stdio.h>
#include	"server.h"

static bool	apply_tick(t_player *player, float *ticks)
{
  player->tick(player, *ticks);
  return (true);
}

static bool	apply_egg_tick(t_egg *egg, float *ticks)
{
  egg->tick(egg, *ticks);
  return (true);
}

static bool	apply_team_tick(t_team *team, float *ticks)
{
  return (team->eggs->apply(team->eggs, (t_list_action)(apply_egg_tick), ticks));
}

void		server_tick(t_server *self)
{
  float		nb_tick;

  nb_tick = (float)(self->chrono->time_elapsed(
    self->chrono) / 1000.0 * self->config.frequency);
  if (nb_tick > 0)
  {
    self->tick_stack += nb_tick;
    self->chrono->reset(self->chrono);
    self->players->apply(self->players, (t_list_action)(apply_tick), &nb_tick);
    self->teams->apply(self->teams, (t_list_action)(apply_team_tick), &nb_tick);
  }
}