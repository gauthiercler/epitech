/*
** nb_player_at.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/tile/nb_player_at.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Mon Jun 26 23:54:03 2017 Clement Nancelle
** Last update Mon Jun 26 23:54:03 2017 Clement Nancelle
*/

#include		"tile.h"

size_t			tile_nb_player_at(t_tile *self, unsigned int level)
{
  return (self->player_list->player_at_level(self->player_list, level));
}