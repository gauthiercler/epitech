/*
** loading.c for megalovania in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/loop/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Mar 20 17:21:30 2016 Buyumad Anas
** Last update Tue Mar 22 11:47:04 2016 Gauthier Cler
*/

#include		"megalovania.h"

void			draw_outline(t_bunny_pixelarray *pix)
{
  t_bunny_position	pos[2];
  t_color		color[2];

  color[0].full = RED;
  color[1].full = RED;
  pos[0].x = 200;
  pos[0].y = 520;
  pos[1].x = 1720;
  pos[1].y = 520;
  line(pix, pos, color);
  pos[0].x = 200;
  pos[0].y = 540;
  pos[1].x = 1720;
  pos[1].y = 540;
  line(pix, pos, color);
  pos[0].x = 200;
  pos[0].y = 520;
  pos[1].x = 200;
  pos[1].y = 540;
  line(pix, pos, color);
  pos[0].x = 1720;
  pos[0].y = 520;
  pos[1].x = 1720;
  pos[1].y = 540;
  line(pix, pos, color);
}

void			draw_line(t_bunny_pixelarray *pix, int progress)
{
  t_bunny_position	pos[2];
  t_color		color[2];

  color[0].full = RED;
  color[1].full = RED;
  pos[0].x = 200 + progress;
  pos[0].y = 521;
  pos[1].x = 200 + progress;
  pos[1].y = 539;
  line(pix, pos, color);
}

void			draw_loading_bar(t_data *data)
{
  int			i;

  i = 0;
  draw_outline(data->pix);
  while (i < data->loading_progress)
    {
      draw_line(data->pix, i);
      i += 1;
    }
  data->loading_progress += 7;
}

t_bunny_response	loading_loop(void *d)
{
  t_data		*data;
  t_bunny_position	b_pos;

  data = d;
  b_pos.x = 0;
  b_pos.y = 0;
  draw_loading_bar(data);
  draw_names(data);
  if (play_song(data->music_load, data->midi) == SUCCESS)
    usleep(1000);
  if (data->loading_progress >= 1520)
    return (EXIT_ON_SUCCESS);
  bunny_blit(&data->window->buffer, &data->pix->clipable, &b_pos);
  bunny_display(data->window);
  return (GO_ON);
}
