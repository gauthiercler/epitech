/*
** full_pix.c for fdf2 in /home/gauthier/rendu/gfx_fdf2
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Dec 14 10:14:02 2015 Gauthier Cler
** Last update Wed Dec 16 11:12:50 2015 Gauthier Cler
*/

#include	"fdf.h"

void	full_pix(t_bunny_pixelarray *pix,
		 t_color *color)
{
  int	i;
  int	*pixel;
  int	size;

  i = 0;
  pixel = pix->pixels;
  size = pix->clipable.buffer.width * pix->clipable.buffer.height;
  while (i < size)
    {
      pixel[i] = color->full;
      i++;
    }
}
