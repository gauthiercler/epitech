/*
** add_player.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/tile/add_player.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Mon Jun 26 20:50:45 2017 Clement Nancelle
** Last update Mon Jun 26 20:50:45 2017 Clement Nancelle
*/

#include		<stdio.h>
#include		"tile.h"

bool			tile_add_player(t_tile *self, t_player *player)
{
  return (self->player_list->push(self->player_list, player));
}