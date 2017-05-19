/*
** full_pix.c for full_pix in /home/gogo/rendu/gfx_raytracer2/srcs/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Apr 26 15:55:14 2016 Gauthier Cler
** Last update Tue Apr 26 15:55:17 2016 Gauthier Cler
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
