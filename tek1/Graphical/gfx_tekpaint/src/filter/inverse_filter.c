/*
** inverse_filter.c for inverse_filter in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan  5 17:44:31 2016 Gauthier Cler
** Last update Tue Jan 26 21:46:58 2016 Gauthier Cler
*/

#include	"tekpaint.h"

void		inverse_filter(t_bunny_pixelarray	*pix)
{
  t_color       color[2];
  int           *pixel;
  int           i;
  int           sav;

  i = 0;
  color[0].full = 0;
  pixel = (int *)pix->pixels;
  while (i < pix->clipable.clip_width * pix->clipable.clip_height)
    {
      color[0].full = pixel[i];
      sav = color[0].argb[0];
      color[0].argb[0] = color[0].argb[2];
      color[0].argb[2] = sav;
      pixel[i] = color[0].full;
      i++;
    }
}
