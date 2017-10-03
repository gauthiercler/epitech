/*
** spawn.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/tile/spawn.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 11:35:34 2017 Antoine FORET
** Last update Wed Jun 28 11:35:34 2017 Antoine FORET
*/

#include		<stdio.h>
#include 		<stdlib.h>
#include		"tile.h"

static void		spawn(t_tile *self, t_ore ore, unsigned int nb)
{
  if (nb == 0)
    return ;
  else if (nb > MAX_SPAWN)
  {
    fprintf(stderr, "[WARNING] Trying to spawn more that 10 (%d)"
      " unit of an ore. Ignoring spawn.\n", nb);
    return ;
  }
  self->add_ore(self, ore);
  return (spawn(self, ore, nb - 1));
}

static unsigned int	nb_spawn(float spawn_rate, float rate,
				    unsigned int max)
{
  return ((unsigned int)((spawn_rate / 100) *
    (rate / 100) * (rand() % max)));
}

void			tile_spawn(t_tile *self, t_config *config,
				       float rate)
{
  spawn(self, EO_FOOD, nb_spawn(config->spawn_rate.food, rate, MAX_SPAWN));
  spawn(self, EO_DERAUMERE, nb_spawn(config->spawn_rate.deraumere,
				     rate, MAX_SPAWN));
  spawn(self, EO_LINEMATE, nb_spawn(config->spawn_rate.linemate,
				    rate, MAX_SPAWN));
  spawn(self, EO_MENDIANE, nb_spawn(config->spawn_rate.mendiane,
				    rate, MAX_SPAWN));
  spawn(self, EO_PHIRAS, nb_spawn(config->spawn_rate.phiras,
				  rate, MAX_SPAWN));
  spawn(self, EO_SIBUR, nb_spawn(config->spawn_rate.sibur,
				 rate, MAX_SPAWN));
  spawn(self, EO_THYSTAME, nb_spawn(config->spawn_rate.thystame,
				    rate, MAX_SPAWN));
}