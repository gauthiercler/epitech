/*
** transposition.c for transposition in /home/gogo/rendu/gfx_tekadventure/bmp_loader
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 20 21:09:24 2016 Gauthier Cler
** Last update Wed Apr 20 21:09:30 2016 Gauthier Cler
*/

#include		<lapin.h>
#include		"bmp.h"

t_bunny_pixelarray	*transposition(t_bmp *bmp)
{
  int			x;
  int			y;
  unsigned int		*pixels;
  t_bunny_pixelarray	*pix;

  y = 0;
  if ((pix = bunny_new_pixelarray(bmp->width, bmp->height)) == NULL)
    return (NULL);
  pixels = (unsigned int *)pix->pixels;
  while (y < pix->clipable.clip_height)
  {
    x = 0;
    while (x < pix->clipable.clip_width)
    {
      pixels[x + y * pix->clipable.clip_width] =
	  bmp->pixels[x + (bmp->height - y - 1) * bmp->width].full;
      x += 1;
    }
    y += 1;
  }
  return (pix);
}
