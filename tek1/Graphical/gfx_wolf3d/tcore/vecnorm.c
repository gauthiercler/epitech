/*
** vecnorm.c for vecnorme in /home/gauthier/rendu/gfx_wolf3d/tcore
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Dec 21 11:21:23 2015 Gauthier Cler
** Last update Sun Jan  3 23:27:57 2016 Gauthier Cler
*/

#include "wolf.h"

double		vecnorm(t_bunny_position *coord0,
			t_bunny_position *coord1)
{
  double	res;

  res =
    sqrt(pow((coord1->x - coord0->x), 2) + pow((coord1->y - coord0->y), 2));
  return (res);
}
