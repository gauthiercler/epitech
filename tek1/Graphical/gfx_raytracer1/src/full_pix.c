/*
** full_pix.c for full_pix in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 11 20:21:27 2016 Gauthier Cler
** Last update Mon Mar  7 19:30:08 2016 Gauthier Cler
*/

#include	"raytracer.h"

void		full_pix(t_bunny_pixelarray	*pix,
			 unsigned int		color)
{
  int		i;
  int		*pixel;
  int		size;

  i = 0;
  pixel = pix->pixels;
  size = pix->clipable.buffer.width * pix->clipable.buffer.height;
  while (i < size)
    {
      pixel[i] = color;
      i++;
    }
}
