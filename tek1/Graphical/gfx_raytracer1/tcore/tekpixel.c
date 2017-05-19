/*
** tekpixel.c for raytracer in /home/gogo/rendu/gfx_raytracer1/tcore
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb 29 10:10:00 2016 Gauthier Cler
** Last update Mon Feb 29 10:10:02 2016 Gauthier Cler
*/

#include	"raytracer.h"

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  int	*pixel;
  int	i;

  pixel = (int *)pix->pixels;
  i = pos[0].x + pos[0].y * pix->clipable.buffer.width;
  if ((pos[0].x < pix->clipable.clip_width && pos[0].x >= 0) &&
      (pos[0].y < pix->clipable.clip_height &&  pos[0].y >= 0))
    pixel[i] = color->full;
}
