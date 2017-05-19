/*
** tekpixel.c for tekpixel in /home/gauthier/rendu/gfx_wolf3d/tcore
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Dec 14 10:48:04 2015 Gauthier Cler
** Last update Sun Jan  3 23:29:05 2016 Gauthier Cler
*/

#include "wolf.h"

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos, t_color *color)
{
  int	*pixel;
  int	i;

  pixel = (int *)pix->pixels;
  i = pos[0].x + pos[0].y * pix->clipable.buffer.width;
  if ((pos[0].x < pix->clipable.clip_width && pos[0].x >= 0) &&
      (pos[0].y < pix->clipable.clip_height &&  pos[0].y >= 0))
    pixel[i] = color->full;
}
