/*
** place_available.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team/place_available.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 16:38:11 2017 Antoine FORET
** Last update Thu Jun 29 16:38:11 2017 Antoine FORET
*/

#include	"team.h"

static bool	count_eggs(t_egg *egg, size_t *nb_egg)
{
  if (egg->is_hatched(egg))
    *nb_egg += 1;
  return (true);
}

size_t		team_place_available(t_team *self, size_t max_vanilla)
{
  ssize_t	vanilla_space;
  size_t	egg_space;

  vanilla_space = max_vanilla - self->players->size(self->players);
  egg_space = 0;
  if (vanilla_space < 0)
    vanilla_space = 0;
  self->eggs->apply(self->eggs, (t_list_action)(count_eggs), &egg_space);
  return (vanilla_space + egg_space);
}