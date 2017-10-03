/*
** push_egg.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team/push_egg.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 22:39:43 2017 Antoine FORET
** Last update Thu Jun 29 22:39:43 2017 Antoine FORET
*/

#include	"team.h"

bool		team_push_egg(t_team *self,
				  t_position *position, t_config *config)
{
  t_egg		*egg;

  egg = new_egg(config, position, self);
  if (egg == NULL)
    return (false);
  return (self->eggs->push(self->eggs, egg));
}