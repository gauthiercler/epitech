/*
** load_color.c for load_color in /home/montag_v/rendu/gfx_raytracer2
** 
** Made by montag_v
** Login   <montag_v@epitech.net>
** 
** Started on  Wed May  4 16:40:37 2016 montag_v
** Last update Wed May  4 16:42:49 2016 montag_v
*/

#include	"raytracer.h"

void		load_color(t_bunny_ini *ini, char *scope, t_color *color)
{
  color->argb[0] = my_atoi(bunny_ini_get_field(ini, scope, "color", 0));
  color->argb[1] = my_atoi(bunny_ini_get_field(ini, scope, "color", 1));
  color->argb[2] = my_atoi(bunny_ini_get_field(ini, scope, "color", 2));
}
