/*
** remove_egg.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/tile/remove_egg.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Wed Jun 28 15:57:04 2017 Clement Nancelle
** Last update Wed Jun 28 15:57:04 2017 Clement Nancelle
*/

#include	"tile.h"

bool		tile_remove_egg(t_tile *self, t_egg *egg)
{
  return (self->egg_list->pop_egg(self->egg_list, egg));
}