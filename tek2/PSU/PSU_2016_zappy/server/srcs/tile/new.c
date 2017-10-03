/*
** new.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/tile/new.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Mon Jun 26 19:59:30 2017 Clement Nancelle
** Last update Mon Jun 26 19:59:30 2017 Clement Nancelle
*/

#include		<stdlib.h>
#include		"tile.h"

static void		tile_methods(t_tile *self)
{
  self->add_player = tile_add_player;
  self->remove_player = tile_remove_player;
  self->nb_players = tile_nb_players;
  self->nb_players_at = tile_nb_player_at;
  self->add_egg = tile_add_egg;
  self->remove_egg = tile_remove_egg;
  self->spawn = tile_spawn;
  self->add_ore = tile_add_ore;
  self->remove_ore = tile_remove_ore;
  self->destroy = tile_destroy;
  self->to_str = tile_to_str;
}

static bool		tile_init(t_tile *self)
{
  self->player_list = new_player_list();
  self->egg_list = new_egg_list();
  self->inventory = new_inventory();
  if (self->player_list == NULL || self->egg_list == NULL
      || self->inventory == NULL)
  {
    if (self->player_list != NULL)
      self->player_list->destroy(self->player_list);
    if (self->egg_list != NULL)
      self->egg_list->destroy(self->egg_list);
    if (self->inventory != NULL)
      self->inventory->destroy(self->inventory);
    return (false);
  }
  return (true);
}

t_tile			*new_tile()
{
  t_tile		*self;

  self = malloc(sizeof(t_tile));
  if (self == NULL)
    return (NULL);
  tile_methods(self);
  if (tile_init(self) == false)
  {
    free(self);
    return (NULL);
  }
  return (self);
}