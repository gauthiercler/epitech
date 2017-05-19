/*
** configure_hitpoint.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat May 14 17:50:56 2016 Buyumad Anas
** Last update Sat May 14 18:06:57 2016 Buyumad Anas
*/

#include	"raytracer.h"

void		configure_hitpoint(t_data *data)
{
  data->hitpoint.x = data->origin.x + (data->coeff * data->vector.x);
  data->hitpoint.y = data->origin.y + (data->coeff * data->vector.y);
  data->hitpoint.z = data->origin.z + (data->coeff * data->vector.z);
  data->origin.x = data->hitpoint.x;
  data->origin.y = data->hitpoint.y;
  data->origin.z = data->hitpoint.z;
}
