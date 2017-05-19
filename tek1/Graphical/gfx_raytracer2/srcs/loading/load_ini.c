/*
** load_ini.c for load_ini in /home/montag_v/rendu/gfx_raytracer2
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Wed May  4 14:30:45 2016 montag_v
** Last update Fri May 20 14:49:54 2016 montag_v
*/

#include	<stdio.h>
#include	"raytracer.h"

int		load_ini(t_raytracer *raytracer, char *filename)
{
  t_bunny_ini	*ini;

  if ((ini = bunny_load_ini(filename)) == NULL)
    return (format(2, "load_ini : Couldn't load the file %s\n", filename));
  load_eye(ini, &raytracer->eye);
  if ((raytracer->nb_lux =
       my_atoi(bunny_ini_get_field(ini, "lux", "nb_lux", 0))) < 0)
    return (format(2, "load_ini : Error nb_lux < 0\n"));
  if (loop_lux(ini, &raytracer->lux, raytracer->nb_lux) == ERROR)
    return (ERROR);
  if ((raytracer->nb_obj =
       my_atoi(bunny_ini_get_field(ini, "obj", "nb_obj", 0))) < 0)
    return (format(2, "load_ini : Error nb_obj < 0\n"));
  if (loop_obj(ini, raytracer, &raytracer->object, raytracer->nb_obj) == ERROR)
    return (ERROR);
  if (load_texture(ini, &raytracer->texture) == ERROR)
    return (ERROR);
  bunny_delete_ini(ini);
  return (SUCCESS);
}
