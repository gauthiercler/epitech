/*
** texture.c for texture in /home/gogo/rendu/gfx_raytracer2/srcs/computation/texture/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri May 20 15:03:52 2016 Gauthier Cler
** Last update Sat May 21 13:12:58 2016 Gauthier Cler
*/

#include	"raytracer.h"

void		plane_texture(t_data *data, t_object *obj,
			      t_bunny_pixelarray *pix,
			      t_bunny_position *size)
{
  int			x;
  int			y;
  float			u;
  float			v;

  if (obj->infos.normal.x == 0 && obj->infos.normal.y != 0)
    {
      u = data->hitpoint.x / size->x;
      v = data->hitpoint.z / size->y;
    }
  else if (obj->infos.normal.x == 0 && obj->infos.normal.y == 0)
    {
      u = data->hitpoint.x / size->x;
      v = data->hitpoint.y / size->y;
    }
  else if (obj->infos.normal.z == 0)
    {
      u = data->hitpoint.z / size->x;
      v = data->hitpoint.y / size->y;
    }
  else
    return ;
  x = u * size->x;
  y = v * size->y;
  data->hit_color.full = get_color(pix, abs(x), abs(y));
}

void		sphere_texture(t_data *data, t_object *obj,
			      t_bunny_pixelarray *pix,
			      t_bunny_position *size)
{
  int			x;
  int			y;

  get_normal_texture(data, obj);
  x = (0.5 + atan2(obj->infos.normal.z, obj->infos.normal.x) /
       (2 * M_PI)) * size->x;
  y = (0.5 - asin(obj->infos.normal.y) / M_PI) * size->y;
  if (x >= 0 && x < size->x && y >= 0 && y < size->y)
    data->hit_color.full = get_color(pix, x, y);
}

void		cylinder_texture(t_data *data, t_object *obj,
			      t_bunny_pixelarray *pix,
			      t_bunny_position *size)
{
  int			x;
  int			y;

  get_normal_texture(data, obj);
  x = (0.5 + atan2(obj->infos.normal.z, obj->infos.normal.x) /
       (2 * M_PI)) * size->x;
  y = (0.5 - asin(obj->infos.normal.y) / M_PI) * size->y;
  if (x >= 0 && x < size->x && y >= 0 && y < size->y)
    data->hit_color.full = get_color(pix, x, y);
}

void		cone_texture(t_data *data, t_object *obj,
			      t_bunny_pixelarray *pix,
			      t_bunny_position *size)
{
  int			x;
  int			y;

  get_normal_texture(data, obj);
  x = (0.5 + atan2(obj->infos.normal.z, obj->infos.normal.x) /
       (2 * M_PI)) * size->x;
  y = (0.5 - asin(obj->infos.normal.y) / M_PI) * size->y;
  if (x >= 0 && x < size->x && y >= 0 && y < size->y)
    data->hit_color.full = get_color(pix, x, y);
}

void		polygon_texture(t_data *data, t_object *obj,
			      t_bunny_pixelarray *pix,
			      t_bunny_position *size)
{
  (void)data;
  (void)obj;
  (void)pix;
  (void)size;
}
