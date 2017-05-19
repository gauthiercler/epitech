/*
** pixel_filter.c for flou_filter in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan  7 17:13:40 2016 Gauthier Cler
** Last update Tue Jan 26 21:47:24 2016 Gauthier Cler
*/

#include	"tekpaint.h"

void		pixel_filter(t_bunny_pixelarray	*pix)
{
  int           *pixel;
  int           i;

  i = 0;
  pixel = (int *)pix->pixels;
  while (i < pix->clipable.clip_width * pix->clipable.clip_height - 1)
    {
      pixel[i] = pixel[i];
      pixel[i + 1] = pixel[i];
      pixel[i + 2] = pixel[i];
      pixel[i + 3] = pixel[i];
      i += 4;
    }
}
