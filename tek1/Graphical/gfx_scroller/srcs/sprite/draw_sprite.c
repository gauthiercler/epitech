/*
** draw_sprite.c for gfx_scroller in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/sprite/draw_sprite.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Mar  20 00:10:19 2016 Anas Buyumad
** Last update Tue Mar 22 11:49:10 2016 Gauthier Cler
*/

#include		"megalovania.h"

void			draw_sheet(t_data *data, int mode)
{
  unsigned int		*pixels;
  int			x;
  int			y;
  t_bunny_position	pos;
  t_color		color;

  y = 0;
  pixels = data->ship[mode]->pixels;
  while (y < data->ship[mode]->clipable.clip_height)
    {
      x = 0;
      while (x < data->ship[mode]->clipable.clip_width)
	{
	  color.full = pixels[x + y * data->ship[mode]->clipable.clip_width];
	  pos.x = data->ship_pos_x + x;
	  pos.y = data->ship_pos_y + y;
	  pixel(data->pix, &pos, &color);
	  x += 1;
	}
      y += 1;
    }
}

void			draw_sprite(t_data *data)
{
  static int		inc = 0;

  if (inc <= 5)
    draw_sheet(data, 0);
  else if (inc > 5 && inc <= 10)
    draw_sheet(data, 1);
  else if (inc > 10 && inc <= 15)
    draw_sheet(data, 2);
  else if (inc > 15 && inc <= 20)
    draw_sheet(data, 3);
  inc += 1;
  if (inc > 20)
    inc = 0;
}

int		load_ship(t_data *data)
{
  if ((data->font = bunny_load_pixelarray("ressources/font.png")) == NULL)
    return (ERROR);
  if ((data->ship[0] = bunny_load_pixelarray("ressources/f1.png")) == NULL)
    return (ERROR);
  if ((data->ship[1] = bunny_load_pixelarray("ressources/f2.png")) == NULL)
    return (ERROR);
  if ((data->ship[2] = bunny_load_pixelarray("ressources/f3.png")) == NULL)
    return (ERROR);
  if ((data->ship[3] = bunny_load_pixelarray("ressources/f4.png")) == NULL)
    return (ERROR);
  return (SUCCESS);
}
