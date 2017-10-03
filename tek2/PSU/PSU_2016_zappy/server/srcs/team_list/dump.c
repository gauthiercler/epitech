/*
** dump.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team_list/dump.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 11:54:23 2017 Antoine FORET
** Last update Thu Jun 29 11:54:23 2017 Antoine FORET
*/

#include	<stdio.h>
#include	"team.h"

static bool	dump(t_team *team)
{
  fprintf(stderr, "[INFO] Team %s available.\n", team->name);
  return (true);
}

void		team_list_dump(t_team_list *self)
{
  self->apply(self, (t_list_action)(dump), NULL);
}