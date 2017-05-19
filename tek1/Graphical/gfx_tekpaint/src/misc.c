/*
** misc.c for misc in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 11 21:13:29 2016 Gauthier Cler
** Last update Tue Jan 26 21:18:56 2016 Gauthier Cler
*/

#include	"tekpaint.h"

int		get_color(t_bunny_pixelarray		*pix,
			  const t_bunny_position	*pos)
{
  int		*pixel;
  int		i;

  pixel = (int *)pix->pixels;
  i = pos[0].x + pos[0].y * pix->clipable.buffer.width;
  return (pixel[i]);
}
