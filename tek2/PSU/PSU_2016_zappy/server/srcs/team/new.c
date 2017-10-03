/*
** new.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 10:55:37 2017 Antoine FORET
** Last update Wed Jun 28 10:55:37 2017 Antoine FORET
*/

#include	<malloc.h>
#include	<string.h>
#include	"team.h"

static void	team_methods(t_team *self)
{
  self->add_player = team_add_player;
  self->remove_player = team_remove_player;
  self->nb_at_level = team_nb_at_level;
  self->get_name = team_get_name;
  self->place_available = team_place_available;
  self->nb_eggs = team_nb_eggs;
  self->first_egg = team_first_egg;
  self->push_egg = team_push_egg;
  self->pop_egg = team_pop_egg;
  self->destroy = team_destroy;
}

static bool	team_init(t_team *self, const char *name)
{
  self->name = strdup(name);
  self->slots = 3;
  self->players = new_player_list();
  self->eggs = new_egg_list();
  return (self->name != NULL &&
	  self->players != NULL &&
	  self->eggs != NULL);
}

t_team		*new_team(const char *name)
{
  t_team	*self;

  self = malloc(sizeof(t_team));
  if (self == NULL)
    return (NULL);
  team_methods(self);
  if (!team_init(self, name))
  {
    self->destroy(self);
    return (NULL);
  }
  return (self);
}