/*
** texturing.c for raytracer in /home/gogo/rendu/gfx_raytracer2/srcs/computation/texture/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sun May 15 22:58:41 2016 Gauthier Cler
** Last update Fri May 20 15:23:53 2016 Gauthier Cler
*/

#include		"raytracer.h"

static void		damier(t_data *data, t_object *obj)
{
  int			size;
  t_position		res;

  size = 40;
  res.x = sin(M_PI / size) * sin((M_PI / size) * data->hitpoint.x);
  res.y = sin(M_PI / size) * sin((M_PI / size) * data->hitpoint.y);
  res.z = sin(M_PI / size) * sin((M_PI / size) * data->hitpoint.z);
  if ((res.x < 0 && res.y > 0 && res.z < 0)
      || (res.x > 0 && res.y < 0 && res.z < 0)
      || (res.x > 0 && res.y > 0 && res.z > 0)
      || (res.x < 0 && res.y < 0 && res.z > 0))
    data->hit_color.full = obj->infos.color.full;
  else
    data->hit_color.full = BLACK;
}

void			texture_surface(t_data *data, t_object *obj,
					t_texture *textures,
					t_raytracer *raytracer)
{
  t_bunny_pixelarray	*pix;
  t_bunny_position	size;

  if (my_strcmp(obj->infos.texture, "damier") == SUCCESS)
    return (damier(data, obj));
  if ((pix = get_pix(obj->infos.texture, textures, &size)) == NULL)
    return ;
  raytracer->a_texture[obj->type](data, obj, pix, &size);
}
