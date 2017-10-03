/*
** destroy.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/tile/destroy.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Mon Jun 26 20:45:46 2017 Clement Nancelle
** Last update Mon Jun 26 20:45:46 2017 Clement Nancelle
*/

#include		<malloc.h>
#include		"tile.h"

void			tile_destroy(t_tile *self)
{
  if (self->player_list != NULL)
    self->player_list->destroy(self->player_list);
  if (self->egg_list != NULL)
    self->egg_list->destroy(self->egg_list);
  if (self->inventory != NULL)
    self->inventory->destroy(self->inventory);
  free(self);
}