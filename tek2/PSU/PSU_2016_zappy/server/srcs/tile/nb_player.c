/*
** nb_player.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/tile/nb_player.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Mon Jun 26 23:51:30 2017 Clement Nancelle
** Last update Mon Jun 26 23:51:30 2017 Clement Nancelle
*/

#include		"tile.h"

size_t			tile_nb_players(t_tile *self)
{
  return (self->player_list->size(self->player_list));
}