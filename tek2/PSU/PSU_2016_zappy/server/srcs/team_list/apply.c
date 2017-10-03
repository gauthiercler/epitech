/*
** apply.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/team_list/apply.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 18:07:31 2017 Montagne Valentin
** Last update Wed Jun 28 18:07:31 2017 Montagne Valentin
*/

#include		"team.h"

bool			team_list_apply(t_team_list *self,
					    t_list_action action,
					    void *params)
{
  return (self->list->foreach(self->list, action, params));
}