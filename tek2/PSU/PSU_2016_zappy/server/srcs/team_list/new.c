/*
** new.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team_list/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 09:36:07 2017 Antoine FORET
** Last update Wed Jun 28 09:36:07 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"team.h"

static void	team_list_methods(t_team_list *self)
{
  self->add_team = team_list_add_team;
  self->remove_team = team_list_remove_team;
  self->get_team = team_list_get_team;
  self->destroy = team_list_destroy;
  self->apply = team_list_apply;
  self->dump = team_list_dump;
  self->empty = team_list_empty;
}

static bool	team_list_init(t_team_list *self)
{
  self->list = new_list();
  return (self->list != NULL);
}

t_team_list	*new_team_list()
{
  t_team_list	*self;

  self = malloc(sizeof(t_team_list));
  if (self == NULL)
    return (NULL);
  team_list_methods(self);
  if (!team_list_init(self))
  {
    self->destroy(self);
    return (NULL);
  }
  return (self);
}