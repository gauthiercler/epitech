/*
** pop_egg.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team/pop_egg.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 22:42:45 2017 Antoine FORET
** Last update Thu Jun 29 22:42:45 2017 Antoine FORET
*/

#include	"team.h"

void		team_pop_egg(t_team *self)
{
  t_egg		*egg;

  egg = self->first_egg(self);
  if (egg != NULL)
  {
    self->eggs->pop_egg(self->eggs, egg);
    egg->destroy(egg);
  }
}