/*
** compute_color.c for raytracer in /home/gogo/rendu/gfx_raytracer2
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
**
** Started on  Fri May 20 16:20:33 2016 Gauthier Cler
** Last update Sun May 22 15:44:26 2016 Buyumad Anas
*/

#include	"raytracer.h"

void		compute_color(t_data *data)
{
  if (data->hit_color.argb[0] * data->light_coeff > 255)
    data->hit_color.argb[0] = 255;
  else
    data->hit_color.argb[0] *= data->light_coeff;
  if (data->hit_color.argb[1] * data->light_coeff > 255)
    data->hit_color.argb[1] = 255;
  else
    data->hit_color.argb[1] *= data->light_coeff;
  if (data->hit_color.argb[2] * data->light_coeff > 255)
    data->hit_color.argb[2] = 255;
  else
    data->hit_color.argb[2] *= data->light_coeff;
  if (data->hit_color.argb[0] * data->shadow_coeff > 255)
    data->hit_color.argb[0] = 255;
  else
    data->hit_color.argb[0] *= data->shadow_coeff;
  if (data->hit_color.argb[1] * data->shadow_coeff > 255)
    data->hit_color.argb[1] = 255;
  else
    data->hit_color.argb[1] *= data->shadow_coeff;
  if (data->hit_color.argb[2] * data->shadow_coeff > 255)
    data->hit_color.argb[2] = 255;
  else
    data->hit_color.argb[2] *= data->shadow_coeff;
}
