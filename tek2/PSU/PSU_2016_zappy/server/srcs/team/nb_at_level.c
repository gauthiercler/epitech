/*
** nb_at_level.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team/nb_at_level.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 11:03:04 2017 Antoine FORET
** Last update Wed Jun 28 11:03:04 2017 Antoine FORET
*/

#include	"team.h"

size_t		team_nb_at_level(t_team *self, unsigned int level)
{
  return (self->players->player_at_level(self->players, level));
}