/*
** load_coord.c for load_coord in /home/montag_v/rendu/gfx_raytracer2
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Wed May  4 15:13:11 2016 montag_v
** Last update Mon May 16 01:31:58 2016 Gauthier Cler
*/

#include	"raytracer.h"

void		load_coord(t_bunny_ini *ini,  char *scope, char *name,
			   t_position *coord)
{
  coord->x =
    my_atof(bunny_ini_get_field(ini, scope, name, 0));
  coord->y =
    my_atof(bunny_ini_get_field(ini, scope, name, 1));
  coord->z =
    my_atof(bunny_ini_get_field(ini, scope, name, 2));
}
