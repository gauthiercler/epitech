/*
** fill.c for gfx_scroller in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/misc/fill.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar  19 13:15:41 2016 Anas Buyumad
** Last update Sun Mar 20 14:25:28 2016 Anas Buyumad
*/

#include	"megalovania.h"

void		fill(t_bunny_pixelarray *pix, unsigned int color)
{
  unsigned int	*pixels;
  int		x;
  int		y;

  pixels = (unsigned int *)pix->pixels;
  y = pix->clipable.clip_y_position;
  while (y < pix->clipable.clip_y_position + pix->clipable.clip_height)
    {
      x = pix->clipable.clip_x_position;
      while (x < pix->clipable.clip_x_position + pix->clipable.clip_width)
	{
	  pixels[x + y * pix->clipable.buffer.width] = color;
	  x += 1;
	}
      y += 1;
    }
}
