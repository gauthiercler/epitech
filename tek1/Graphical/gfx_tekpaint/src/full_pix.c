/*
** full_pix.c for full_pix in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 11 20:21:27 2016 Gauthier Cler
** Last update Tue Jan 26 18:30:06 2016 Gauthier Cler
*/

#include	"tekpaint.h"

void		full_pix(t_bunny_pixelarray	*pix,
			 t_color		*color)
{
  int		i;
  int		*pixel;
  int		size;

  i = 0;
  pixel = pix->pixels;
  size = pix->clipable.buffer.width * pix->clipable.buffer.height;
  while (i < size)
    {
      pixel[i] = color->full;
      i++;
    }
}
