/*
** full_pix.c for tekgui in /home/gogo/rendu/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Feb  2 23:43:17 2016 Gauthier Cler
** Last update Tue Feb  2 23:43:25 2016 Gauthier Cler
*/

#include	"tekgui.h"

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
