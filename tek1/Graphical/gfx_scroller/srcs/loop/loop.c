/*
** loop.c for gfx_scroller in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/loop/loop.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar  19 12:46:09 2016 Anas Buyumad
** Last update Sun Mar 20 15:32:33 2016 Gauthier Cler
*/

#include		"megalovania.h"

void			draw_stars(t_data *data)
{
  int			i;

  i = 0;
  while (i < 20)
    {
      draw_star(data->pix, &data->stars[i]);
      data->stars[i].pos.x += (int)data->stars[i].speed;
      if (data->stars[i].pos.x > 1920)
	{
	  data->stars[i].pos.x = 0;
	  data->stars[i].pos.y = rand() % 1080;
	}
      i += 1;
    }
}

void			move_ship(t_data *data)
{
  static int		inc = 0;

  if (data->ship_mode == 1)
    if (data->ship_pos_x < 960)
      data->ship_pos_x += 3;
  if (data->ship_pos_x >= 955)
    data->ship_mode = 2;
  if (data->ship_mode == 2)
    {
      if (inc < 20)
	data->ship_pos_x += 1;
      if (inc >= 20)
	{
	  data->ship_pos_x -= 1;
	  if (inc >= 39)
	    inc = 0;
	}
      inc += 1;
    }
}

void			draw_text(t_data *data)
{
    t_bunny_position	text_pos;

    data->sin_pos.x -= 7;
    data->sin_circle += 0.1;
    data->sin_pos.y = 100 - sin(data->sin_circle) * data->ondulation;
    (data->sin_pos.x <= -4700) ? data->sin_pos.x = 1920 : 0;
    (data->sin_circle >= 360) ? data->sin_circle = 0 : 0;
    text_pos.x = data->sin_pos.x;
    text_pos.y = data->sin_pos.y;
    tektext(data->pix, "ITS A BEAUTIFUL DAY OUTSIDE BIRDS ARE SINGING FLOWERS "
	    , data->font, &text_pos);
    tektext(data->pix, "ARE BLOOMING ON AYS LIKE THESE KIDS LIKE YOU SHOULD BE"
	    , data->font, &text_pos);
    tektext(data->pix, " BURNING IN HELL", data->font, &text_pos);
}

t_bunny_response	loop(void *d)
{
  t_data		*data;
  t_bunny_position	b_pos;

  data = d;
  b_pos.x = 0;
  b_pos.y = 0;
  fill(data->pix, BLACK);
  draw_stars(data);
  draw_planets(data);
  draw_sprite(data);
  draw_text(data);
  move_ship(data);
  if (data->peanut_active)
    draw_peanut(data);
  bunny_blit(&data->window->buffer, &data->pix->clipable, &b_pos);
  bunny_display(data->window);
  return (GO_ON);
}
