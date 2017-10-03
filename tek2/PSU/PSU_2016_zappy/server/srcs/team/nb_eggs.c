/*
** nb_eggs.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team/nb_eggs.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 16:49:27 2017 Antoine FORET
** Last update Thu Jun 29 16:49:27 2017 Antoine FORET
*/

#include	"team.h"

size_t		team_nb_eggs(t_team *self)
{
  return (self->eggs->size(self->eggs));
}