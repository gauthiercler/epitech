/*
** new.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/player_list/new.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 14:00:22 2017 Montagne Valentin
** Last update Mon Jun 26 14:00:23 2017 Montagne Valentin
*/

#include		<stdlib.h>
#include		"player.h"

static void		player_list_methods(t_player_list *self)
{
  self->size = player_list_size;
  self->destroy = player_list_destroy;
  self->player_at_level = player_list_nb_at_level;
  self->push = player_list_push;
  self->pop = player_list_pop;
  self->apply = player_list_apply;
  self->empty = player_list_empty;
}

static bool		player_list_init(t_player_list *self)
{
  self->list = new_list();
  if (self->list == NULL)
    return (false);
  return (true);
}

t_player_list		*new_player_list()
{
  t_player_list		*self;

  self = malloc(sizeof(t_player_list));
  if (self == NULL)
    return (NULL);
  player_list_methods(self);
  if (!player_list_init(self))
  {
    self->destroy(self);
    return (NULL);
  }
  return (self);
}