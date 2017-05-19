/*
** names.c for megalovania in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/loop/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Mar 20 18:12:27 2016 Buyumad Anas
** Last update Tue Mar 22 11:47:24 2016 Gauthier Cler
*/

#include		"megalovania.h"

void			draw_names(t_data *data)
{
  t_bunny_position	text_pos;

  text_pos.x = 220;
  text_pos.y = 800;
  tektext(data->pix, "ANAS BUYUMAD GAUTHIER CLER", data->font, &text_pos);
  tektext(data->pix, "  YOHAN VAMOUR", data->font, &text_pos);
  text_pos.x = 775;
  text_pos.y = 425;
  tektext(data->pix, "MEGALOVANIA", data->font, &text_pos);
}

void		big_loop(t_data *data)
{
  bunny_sound_loop(&data->music_load->sound, false);
  bunny_sound_volume(&data->music_load->sound, 40);
  bunny_loop(data->window, 100, data);
  bunny_delete_sound(&data->music_load->sound);
  bunny_sound_loop(&data->music->sound, false);
  bunny_sound_volume(&data->music->sound, 40);
  bunny_sound_play(&data->music->sound);
  bunny_set_loop_main_function(&loop);
  bunny_loop(data->window, 100, data);
  bunny_sound_stop(&data->music->sound);
  burn(data);
}
