/*
** empty.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/team_list/empty.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 29 09:58:12 2017 Montagne Valentin
** Last update Thu Jun 29 09:58:12 2017 Montagne Valentin
*/

#include		"team.h"

static bool		delete_team(t_team *self)
{
  if (self != NULL)
    self->destroy(self);
  return (true);
}

void			team_list_empty(t_team_list *self)
{
  self->apply(self, (t_list_action)(delete_team), NULL);
}