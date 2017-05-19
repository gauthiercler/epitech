/*
** go.c for go in /home/gauthier/rendu/gfx_wolf3d/tcore
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Dec 21 11:22:32 2015 Gauthier Cler
** Last update Sun Jan  3 19:17:21 2016 Gauthier Cler
*/

#include "wolf.h"

void	go(t_bunny_position	*curpos,
	   double		angle,
	   t_bunny_position	*newpos,
	   int			move)
{
  newpos->x = curpos->x + cos(angle) * move;
  newpos->y = curpos->y + sin(angle) * move;
}
