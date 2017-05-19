/*
** tekisoproject.c for tekisoproject in /home/gauthier/rendu/gfx_fdf2
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Dec 14 14:07:18 2015 Gauthier Cler
** Last update Fri Dec 18 14:51:07 2015 Gauthier Cler
*/

#include	"fdf.h"

void	tekisoproject(t_bunny_position *out, int x, int y, int z)
{
  int	x_offset;
  int	y_offset;

  x_offset = 500;
  y_offset = 100;
  out->x = x_offset - (sqrt(2)/2) * (y - x);
  out->y = y_offset - (sqrt((float)2 / 3) * z - (1 / sqrt(6)) * (x + y));
}
