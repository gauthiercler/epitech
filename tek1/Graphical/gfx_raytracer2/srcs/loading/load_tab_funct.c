/*
** load_tab_funct.c for raytracer in /home/gogo/rendu/gfx_raytracer2/srcs/loading/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue May 10 18:15:17 2016 Gauthier Cler
** Last update Fri May 20 15:03:32 2016 Gauthier Cler
*/

#include	"raytracer.h"

void		load_tab_funct(t_raytracer *data)
{
  data->compute[PLANE] = plane;
  data->compute[SPHERE] = sphere;
  data->compute[CYLINDER] = cylinder;
  data->compute[CONE] = cone;
  data->compute[POLYGON] = polygon;
  data->a_texture[PLANE] = plane_texture;
  data->a_texture[SPHERE] = sphere_texture;
  data->a_texture[CYLINDER] = cylinder_texture;
  data->a_texture[CONE] = cone_texture;
  data->a_texture[POLYGON] = polygon_texture;
}
