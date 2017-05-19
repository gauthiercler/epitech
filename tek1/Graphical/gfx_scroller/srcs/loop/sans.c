/*
** sans.c for megalovania in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/loop/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Mar 20 20:28:34 2016 Buyumad Anas
** Last update Tue Mar 22 11:44:44 2016 Gauthier Cler
*/

#include		"megalovania.h"

void			draw_sans(t_bunny_pixelarray *pix,
				  t_bunny_pixelarray *sans)
{
  unsigned int		*pixels;
  t_bunny_position	pos;
  t_color		color;
  int			x;
  int			y;

  y = 0;
  pixels = (unsigned int *)sans->pixels;
  while (y < sans->clipable.clip_height)
    {
      x = 0;
      while (x < sans->clipable.clip_width)
	{
	  color.full = pixels[x + y * sans->clipable.clip_width];
	  pos.x = 785 + x;
	  pos.y = 0 + y;
	  pixel(pix, &pos, &color);
	  x += 1;
	}
      y += 1;
    }
}
