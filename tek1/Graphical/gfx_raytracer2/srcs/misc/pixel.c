/*
** pixel.c for tekpixel in /home/gogo/rendu/gfx_raytracer2/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed May 11 16:04:40 2016 Gauthier Cler
** Last update Wed May 11 16:05:18 2016 Gauthier Cler
*/

#include	"raytracer.h"

void		pixel(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color)
{
  t_color	under;
  t_color	over;
  unsigned int	*pixels;
  float		ratio;

  pixels = (unsigned int *)pix->pixels;
  if ((pos->x >= 0 && pos->x < pix->clipable.clip_width) &&
      (pos->y >= 0 && pos->y < pix->clipable.clip_height))
    {
      ratio = color->argb[3] / 255.0;
      under.full = pixels[pos->x + pos->y * pix->clipable.clip_width];
      over.argb[0] = color->argb[0] * ratio + under.argb[0] * (1 - ratio);
      over.argb[1] = color->argb[1] * ratio + under.argb[1] * (1 - ratio);
      over.argb[2] = color->argb[2] * ratio + under.argb[2] * (1 - ratio);
      if (under.argb[3] < color->argb[3])
	over.argb[3] = color->argb[3];
      else
	over.argb[3] = under.argb[3];
      pixels[pos->x + pos->y * pix->clipable.clip_width] = over.full;
    }
}
