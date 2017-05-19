/*
** front_draw.c for gfx_scroller in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/front/front_draw.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar  19 16:54:52 2016 Anas Buyumad
** Last update Tue Mar 22 11:46:19 2016 Gauthier Cler
*/

#include	"megalovania.h"

void		alter_front_pos(t_planet *planet)
{
  planet->pos_x += planet->speed;
  if (planet->pos_x <= 860 - planet->dim
      && planet->pos_x > -planet->dim)
    planet->pos_y -= 0.5;
  else if (planet->pos_x > 860.0 - planet->dim
	   && planet->pos_x < 900.0 - planet->dim)
    planet->pos_y -= 0.2;
  else if (planet->pos_x > 900.0 - planet->dim
	   && planet->pos_x < 910.0 - planet->dim)
    planet->pos_y -= 0.1;
  else if (planet->pos_x > 910.0 - planet->dim
	   && planet->pos_x < 945.0 - planet->dim)
    planet->pos_y += 0.1;
  else if (planet->pos_x > 945.0 - planet->dim
	   && planet->pos_x < 1100.0 - planet->dim)
    planet->pos_y += 0.2;
  else if (planet->pos_x > 1100.0 - planet->dim
	   && planet->pos_x <= 1980.0 - planet->dim)
    planet->pos_y += 0.5;
  else if (planet->pos_x > 3000.0 + planet->dim)
    planet->pos_x = -planet->dim;
}

void			draw_font(t_data *data, t_planet *planet)
{
  t_color		color;
  unsigned int		*pixels;
  t_bunny_position	pos;
  int			x;
  int			y;

  y = 0;
  pixels = (unsigned int *)planet->planet->pixels;
  while (y < planet->planet->clipable.clip_width)
    {
      x = 0;
      while (x < planet->planet->clipable.clip_height)
	{
	  color.full = pixels[x + y * planet->planet->clipable.clip_width];
	  pos.x = planet->pos_x + x;
	  pos.y = planet->pos_y + y;
	  pixel(data->pix, &pos, &color);
	  x += 1;
	}
      y += 1;
    }
  alter_front_pos(planet);
}

void	draw_planets(t_data *data)
{
  int	i;

  i = 0;
  while (i < 4)
    {
      draw_font(data, &data->planets[i]);
      i += 1;
    }
}
