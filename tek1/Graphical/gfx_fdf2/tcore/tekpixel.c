/*
** tekpixel.c for fdf2 in /home/gauthier/rendu/gfx_fdf2
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Dec 14 10:14:31 2015 Gauthier Cler
** Last update Sun Dec 20 22:19:55 2015 Gauthier Cler
*/

#include	"fdf.h"

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos, t_color *color)
{
  int	*pixel;
  int	i;

  pixel = (int *)pix->pixels;
  i = pos[0].x + pos[0].y * pix->clipable.buffer.width;
  if ((pos[0].x < pix->clipable.clip_width && pos[0].x >= 0) &&
      (pos[0].y < pix->clipable.clip_height &&  pos[0].y >= 0))
    pixel[i] = color[0].full;
}
