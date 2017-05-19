/*
** norme.c for norme in /home/gogo/rendu/gfx_raytracer2/srcs/computation/texture/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri May 20 14:40:48 2016 Gauthier Cler
** Last update Fri May 20 14:44:51 2016 Gauthier Cler
*/

#include		"raytracer.h"

float			norme(t_position *pos)
{
  return (sqrt(pos->x * pos->x + pos->y * pos->y + pos->z * pos->z));
}

void			get_normal_texture(t_data *data, t_object *obj)
{
  obj->infos.normal.x = (data->hitpoint.x - obj->origin.x) / obj->infos.radius;
  obj->infos.normal.y = (data->hitpoint.y - obj->origin.y) / obj->infos.radius;
  obj->infos.normal.z = (data->hitpoint.z - obj->origin.z) / obj->infos.radius;
  obj->infos.normal.x /= norme(&obj->infos.normal);
  obj->infos.normal.y /= norme(&obj->infos.normal);
  obj->infos.normal.z /= norme(&obj->infos.normal);
}
