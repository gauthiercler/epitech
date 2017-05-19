/*
** pixel.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/misc/draw/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed Apr 13 14:29:42 2016 Buyumad Anas
** Last update Thu Apr 14 16:50:13 2016 Buyumad Anas
*/

#include	"adventure.h"

void		pixel(t_bunny_pixelarray *pix, t_position *pos, t_color *color)
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
