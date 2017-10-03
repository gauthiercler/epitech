/*
** new.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/egg/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 24 18:59:08 2017 Antoine FORET
** Last update Sat Jun 24 18:59:08 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"egg.h"

static void	egg_methods(t_egg *self)
{
  self->tick = egg_tick;
  self->is_hatched = egg_is_hatched;
  self->destroy = egg_destroy;
}

static bool	egg_init(t_egg *self,
			    t_config *config,
			    const t_position *position,
			    t_team *team)
{
  self->id = config->id_increment;
  self->time_hatching = config->time_hatching;
  self->position.x = position->x;
  self->position.y = position->y;
  self->team = team;
  config->id_increment += 1;
  return (true);
}

t_egg		*new_egg(t_config *config, const t_position *position, t_team *team)
{
  t_egg		*self;

  self = malloc(sizeof(t_egg));
  if (self == NULL)
    return (NULL);
  egg_methods(self);
  if (!egg_init(self, config, position, team))
  {
    self->destroy(self);
    return (NULL);
  }
  return (self);
}