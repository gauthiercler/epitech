/*
** peanut.c for gfx_scroller in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/sprite/peanut.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Mar  20 02:46:33 2016 Anas Buyumad
** Last update Tue Mar 22 11:49:57 2016 Gauthier Cler
*/

#include		"megalovania.h"

void			d_peanut(t_data *data, int mode)
{
  unsigned int		*pixels;
  int			x;
  int			y;
  t_bunny_position	pos;
  t_color		color;

  y = 0;
  pixels = data->peanut[mode]->pixels;
  while (y < data->peanut[mode]->clipable.clip_height)
    {
      x = 0;
      while (x < data->peanut[mode]->clipable.clip_width)
	{
	  color.full = pixels[x + y * data->peanut[mode]->clipable.clip_width];
	  pos.x = data->peanut_pos.x + x;
	  pos.y = data->peanut_pos.y + y;
	  pixel(data->pix, &pos, &color);
	  x += 1;
	}
      y += 1;
    }
}

void			draw_peanut(t_data *data)
{
  static int		inc = 0;
  static int		mode = 0;

  if (mode == 0)
    inc += 1;
  d_peanut(data, inc / 5);
  if (inc >= 35)
    inc = 0;
}

int             load_jelly(t_data *data)
{
  if ((data->peanut[0] =
       bunny_load_pixelarray("ressources/jelly-0.png")) == NULL)
    return (ERROR);
  if ((data->peanut[1] =
       bunny_load_pixelarray("ressources/jelly-1.png")) == NULL)
    return (ERROR);
  if ((data->peanut[2] =
       bunny_load_pixelarray("ressources/jelly-2.png")) == NULL)
    return (ERROR);
  if ((data->peanut[3] =
       bunny_load_pixelarray("ressources/jelly-3.png")) == NULL)
    return (ERROR);
  if ((data->peanut[4] =
       bunny_load_pixelarray("ressources/jelly-4.png")) == NULL)
    return (ERROR);
  if ((data->peanut[5] =
       bunny_load_pixelarray("ressources/jelly-5.png")) == NULL)
    return (ERROR);
  if ((data->peanut[6] =
       bunny_load_pixelarray("ressources/jelly-6.png")) == NULL)
    return (ERROR);
  if ((data->peanut[7] =
       bunny_load_pixelarray("ressources/jelly-7.png")) == NULL)
    return (ERROR);
  return (SUCCESS);
}

void		load_sprite_attribute(t_data *data)
{
  data->peanut_active = false;
  data->peanut_pos.x = 450;
  data->peanut_pos.y = 450;
  data->ship_pos_x = -800;
  data->ship_pos_y = 500;
  data->ship_mode = 1;
  data->ondulation = 50;
  data->sin_circle = 0;
  data->sin_pos.x = 1920;
  data->sin_pos.y = 500;
}

void		load_sans(t_data *data)
{
  data->loading_progress = 0;
  fill(data->pix, BLACK);
  draw_sans(data->pix, data->sans);
  gen_stars(data);
}
