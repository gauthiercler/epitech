/*
** first_egg.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team/first_egg.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 22:38:32 2017 Antoine FORET
** Last update Thu Jun 29 22:38:32 2017 Antoine FORET
*/

#include	"team.h"

t_egg		*team_first_egg(t_team *self)
{
  return (self->eggs->first(self->eggs));
}