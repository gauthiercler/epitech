/*
** blit_to_pix.c for blit_to_pix in /home/gogo/rendu/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Feb 17 19:00:51 2016 Gauthier Cler
** Last update Thu Feb 25 00:31:44 2016 Gauthier Cler
*/

#include	"tekgui.h"

void			blit_to_pix(t_bunny_pixelarray *pix,
				    t_tekgui elem)
{
  t_color		color;
  t_bunny_position	img_pos;
  t_bunny_position	pix_pos;
  unsigned char		alpha;

  if (check_alpha(elem.pix) == 0)
    alpha = 255;
  img_pos.x = 0;
  img_pos.y = 0;
  pix_pos.y = elem.pos.y;
  while (img_pos.y != elem.pix->clipable.buffer.height)
    {
      img_pos.x = 0;
      pix_pos.x = elem.pos.x;
      while (img_pos.x != elem.pix->clipable.buffer.width)
	{
	  color.full = get_color(elem.pix, &img_pos);
	  color.argb[3] += alpha;
	  tekpixel(pix, &pix_pos, &color);
	  pix_pos.x += 1;
	  img_pos.x += 1;
	}
      img_pos.y += 1;
      pix_pos.y += 1;
    }
}

int		check_alpha(t_bunny_pixelarray *pix)
{
  int		i;
  int		*pixel;
  t_color	color;

  pixel = pix->pixels;
  while (i < pix->clipable.buffer.width * pix->clipable.buffer.height)
    {
      color.full = pixel[i];
      if (color.argb[3] > 0)
	return (1);
      i += 1;
    }
  return (0);
}
