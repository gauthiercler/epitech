/*
** remove_team.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team_list/remove_team.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 09:50:35 2017 Antoine FORET
** Last update Wed Jun 28 09:50:35 2017 Antoine FORET
*/

#include	"team.h"

bool		team_list_remove_team(t_team_list *self, t_team *team)
{
  return (self->list->pop_data(self->list, team));
}