/*
** get_team.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team_list/get_team.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 09:51:29 2017 Antoine FORET
** Last update Wed Jun 28 09:51:29 2017 Antoine FORET
*/

#include	<string.h>
#include	"team.h"

static bool	search_team_name(t_team *team, const char *name)
{
  return (strcmp(team->name, name) == 0);
}

t_team		*team_list_get_team(t_team_list *self, const char *name)
{
  return (self->list->search(self->list,
			     (t_list_predicate)(search_team_name),
			     (void *)(name)));
}