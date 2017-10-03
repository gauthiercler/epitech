/*
** remove_player.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/tile/remove_player.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Mon Jun 26 23:45:11 2017 Clement Nancelle
** Last update Mon Jun 26 23:45:11 2017 Clement Nancelle
*/

#include		"tile.h"

bool			tile_remove_player(t_tile *self, t_player *player)
{
  return (self->player_list->pop(self->player_list, player));
}