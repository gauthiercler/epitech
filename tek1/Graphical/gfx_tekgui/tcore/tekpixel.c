/*
** tekpixel.c for tekgui in /home/gogo/rendu/gfx_tekgui/tcore
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb  1 16:14:13 2016 Gauthier Cler
** Last update Sun Feb 28 19:18:22 2016 Gauthier Cler
*/

#include "tekgui.h"

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  int	*pixel;
  int	i;

  pixel = (int *)pix->pixels;
  i = pos[0].x + pos[0].y * pix->clipable.buffer.width;
  if (color[0].argb[3] > 0)
    if ((pos[0].x < pix->clipable.clip_width && pos[0].x >= 0) &&
	(pos[0].y < pix->clipable.clip_height &&  pos[0].y >= 0))
      pixel[i] = color->full;
}
