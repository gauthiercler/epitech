/*
** load_obj.c for load_obj in /home/montag_v/rendu/gfx_raytracer2
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Wed May  4 16:31:54 2016 montag_v
** Last update Fri May 20 14:53:29 2016 montag_v
*/

#include	"raytracer.h"

static int	load_simple_obj(t_bunny_ini *ini, char *scope, t_object *obj)
{
  load_coord(ini, scope, "coord", &obj->origin);
  load_color(ini, scope, &obj->infos.color);
  obj->infos.texture =
    my_strdup(bunny_ini_get_field(ini, scope, "texture", 0));
  load_coord(ini, scope, "inclinaison", &obj->infos.inclinaison);
  if (obj->type == CONE)
    obj->infos.angle =
      my_atof(bunny_ini_get_field(ini, scope, "angle", 0));
  if (obj->type == PLANE)
    load_coord(ini, scope, "normal", &obj->infos.normal);
  obj->infos.height =
    my_atof(bunny_ini_get_field(ini, scope, "height", 0));
  obj->infos.radius =
    my_atof(bunny_ini_get_field(ini, scope, "radius", 0));
  return (SUCCESS);
}

int		load_obj(t_bunny_ini *ini,
			 char *scope,
			 t_raytracer *ray,
			 t_object *obj)
{
  if ((obj->type = my_atoi(bunny_ini_get_field(ini, scope, "type", 0))) < 0
      || obj->type >= NB_OBJ_TYPES)
    return (format(2, "%s Error invalid type\n", scope));
  init_obj(obj);
  if (obj->type == POLYGON)
    {
      if (load_complex_obj(ini, scope, ray, obj) == ERROR)
	return (ERROR);
    }
  else
    if (load_simple_obj(ini, scope, obj) == ERROR)
      return (ERROR);
  return (SUCCESS);
}

int		loop_obj(t_bunny_ini *ini,
			 t_raytracer *ray,
			 t_object **obj,
			 int nb_obj)
{
  char		**scope;
  int		i;

  if ((scope = bunny_malloc(sizeof(char *) * (nb_obj + 1))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  if (((*obj) = bunny_malloc(sizeof(t_object) * (nb_obj + 1))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  if (find_scope(ini, scope, "obj", nb_obj) == ERROR)
    return (ERROR);
  i = 0;
  while (i < nb_obj)
    {
      if (load_obj(ini, scope[i], ray, &(*obj)[i]) == ERROR)
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}
