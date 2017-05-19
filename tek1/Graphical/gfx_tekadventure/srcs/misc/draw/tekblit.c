/*
** tekblit.c for tekblit in /home/montag_v/rendu/nocss_2020/src_test
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Wed Mar 30 09:11:14 2016 valentin montagne
** Last update Thu Apr 14 19:27:34 2016 Buyumad Anas
*/

#include		<lapin.h>
#include		"adventure.h"

void			scale_x(const t_bunny_pixelarray	*pix,
				t_position *pos,
				int *i)
{
  if (pix->clipable.scale.x == 0 || pix->clipable.scale.y == 0)
    return ;
  *i += 1;
  if (*i > (int)pix->clipable.scale.x && pix->clipable.scale.x > 1)
    {
      *i = 0;
      pos->x += 1;
    }
  else
    pos->x += (1 / pix->clipable.scale.x);
}

void			scale_y(const t_bunny_pixelarray	*pix,
				t_position		*pos,
				int				*i)
{
  if (pix->clipable.scale.x == 0 || pix->clipable.scale.y == 0)
    return ;
  *i += 1;
  if (*i > (int)pix->clipable.scale.y && pix->clipable.scale.y > 1)
    {
      *i = 0;
      pos->y += 1;
    }
  else
    pos->y += (1 / pix->clipable.scale.y);
}

t_color			getcolor2(t_bunny_pixelarray *pix,
				   t_position *pos)
{
  t_color		color;
  int			*pixel;

  pixel = pix->pixels;
  color.full = pixel[pos->x + pos->y * pix->clipable.buffer.width];
  return (color);
}

void			draw(t_bunny_pixelarray *destination,
			     t_bunny_pixelarray *origin,
			     t_position	*poso,
			     t_position	*posd)
{
  t_color	color;

  poso[1].x = poso[0].x + origin->clipable.clip_x_position;
  color = getcolor2(origin, &poso[1]);
  color.argb[3] = 255;
  pixel(destination, posd, &color);
  posd->x += 1;
}

void			tekblit(t_bunny_pixelarray *destination,
				t_bunny_pixelarray *origin,
				t_position *pos)
{
  t_position		poso[2];
  t_position		posd;
  int			i;
  int			j;

  poso[0].y = 0;
  posd.y = pos->y;
  i = 0;
  j = 0;
  while (poso[0].y < origin->clipable.clip_height)
    {
      poso[0].x = 0;
      poso[1].y = poso[0].y + origin->clipable.clip_y_position;
      posd.x = pos->x;
      while (poso[0].x < origin->clipable.clip_width)
	{
	  draw(destination, origin, poso, &posd);
	  scale_x(origin, &poso[0], &i);
	}
      posd.y += 1;
      scale_y(origin, &poso[0], &j);
    }
}
