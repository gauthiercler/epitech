/*
** render_pixel.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun May 22 15:41:25 2016 Buyumad Anas
** Last update Sun May 22 15:41:51 2016 Buyumad Anas
*/

#include		"raytracer.h"

void			render_pixel(t_raytracer *raytracer, t_data *data)
{
  t_bunny_position	pos;

  pos.x = data->target.x;
  pos.y = data->target.y;
  pixel(raytracer->pix, &pos, &data->hit_color);
}
