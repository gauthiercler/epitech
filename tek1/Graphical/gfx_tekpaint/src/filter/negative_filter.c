/*
** negative_filter.c for negative_filter in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan  7 16:31:19 2016 Gauthier Cler
** Last update Tue Jan 26 21:47:07 2016 Gauthier Cler
*/

#include	"tekpaint.h"

void		negative_filter(t_bunny_pixelarray	*pix)
{
  t_color       color[2];
  int           *pixel;
  int           i;

  i = 0;
  color[0].full = 0;
  pixel = (int *)pix->pixels;
  while (i < pix->clipable.clip_width * pix->clipable.clip_height)
    {
      color[0].full = pixel[i];
      color[0].argb[0] = 255 - color[0].argb[0];
      color[0].argb[1] = 255 - color[0].argb[1];
      color[0].argb[2] = 255 - color[0].argb[2];
      pixel[i] = color[0].full;
      i++;
    }
}
