/*
** add_team.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team_list/add_team.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 09:49:02 2017 Antoine FORET
** Last update Wed Jun 28 09:49:02 2017 Antoine FORET
*/

#include	"team.h"

bool		team_list_add_team(t_team_list *self, t_team *team)
{
  return (self->list->push_front(self->list, team));
}