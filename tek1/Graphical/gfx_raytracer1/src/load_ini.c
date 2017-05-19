/*
** load_ini.c for load_ini in /home/gogo/rendu/gfx_raytracer1/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Mar  7 23:09:28 2016 Gauthier Cler
** Last update Sun Mar 13 21:31:45 2016 Gauthier Cler
*/

#include	"raytracer.h"

int		fill_obj(t_object	*object,
			 int		i,
			 char		*tmp,
			 t_bunny_ini	*ini)
{
  object[i].type = my_atoi(bunny_ini_get_field(ini, tmp, "type", 0));
  object[i].pos.x = my_atof(bunny_ini_get_field(ini, tmp, "pos", 0));
  object[i].pos.y = my_atof(bunny_ini_get_field(ini, tmp, "pos", 1));
  object[i].pos.z = my_atof(bunny_ini_get_field(ini, tmp, "pos", 2));
  object[i].radius = my_atof(bunny_ini_get_field(ini, tmp, "radius", 0));
  object[i].color.argb[0] = my_atoi(bunny_ini_get_field(ini, tmp, "color", 0));
  object[i].color.argb[1] = my_atoi(bunny_ini_get_field(ini, tmp, "color", 1));
  object[i].color.argb[2] = my_atoi(bunny_ini_get_field(ini, tmp, "color", 2));
  return (SUCCESS);
}
t_object	*load_ini(char *path, int *nb_objects)
{
  t_object	*object;
  t_bunny_ini	*ini;
  int		i;
  char		*tmp;

  i = 0;
  if ((ini = bunny_load_ini(path)) == NULL)
    return (NULL);
  *nb_objects = my_atoi(bunny_ini_get_field(ini, "nb_obj", "nb", 0));
  if ((object = bunny_malloc(sizeof(t_object) * *nb_objects)) == NULL)
    return (NULL);
  while (i < *nb_objects)
    {
      tmp = my_strdup(bunny_ini_get_field(ini, "nb_obj", "name", i));
      if (fill_obj(object, i, tmp, ini) == ERROR)
	return (NULL);
      i += 1;
    }
  return (object);
}

int		load_infos(char *path,
			   t_option *options,
			   t_vec * eye_ori,
			   t_vec *lum)
{
  t_bunny_ini	*ini;

  if ((ini = bunny_load_ini(path)) == NULL)
    return (ERROR);
  eye_ori->x = my_atoi(bunny_ini_get_field(ini, "infos", "eye", 0));
  eye_ori->y = my_atoi(bunny_ini_get_field(ini, "infos", "eye", 1));
  eye_ori->z = my_atoi(bunny_ini_get_field(ini, "infos", "eye", 2));
  lum->x = my_atoi(bunny_ini_get_field(ini, "infos", "lum", 0));
  lum->y = my_atoi(bunny_ini_get_field(ini, "infos", "lum", 1));
  lum->z = my_atoi(bunny_ini_get_field(ini, "infos", "lum", 2));
  options->shadow = my_atoi(bunny_ini_get_field(ini, "infos", "shadow", 0));
  options->plane = my_atoi(bunny_ini_get_field(ini, "infos", "plane", 0));
  options->lum_coef = my_atof
    (bunny_ini_get_field(ini, "infos", "lum_coef", 0));
  options->size = my_atof(bunny_ini_get_field(ini, "infos", "size", 0));
  return (SUCCESS);
}
