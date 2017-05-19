/*
** objects.c for objects in /home/gogo/rendu/gfx_raytracer1/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Sun Mar  6 21:40:49 2016 Gauthier Cler
** Last update Mon Mar  7 23:27:25 2016 Gauthier Cler
*/

#include	"raytracer.h"

void		init_sphere(t_object *objs)
{
  objs->type = 1;
  objs->pos.x = 0;
  objs->pos.y = 0;
  objs->pos.z = 300;
  objs->radius = 40;
  objs->color.argb[0] = 255;
  objs->color.argb[1] = 0;
  objs->color.argb[2] = 255;
}
