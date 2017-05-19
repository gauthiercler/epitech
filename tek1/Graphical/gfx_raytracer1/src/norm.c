/*
** norm.c for norm in /home/gogo/rendu/gfx_raytracer1/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Sat Mar 12 00:27:03 2016 Gauthier Cler
** Last update Sun Mar 13 19:44:34 2016 Gauthier Cler
*/

#include	"raytracer.h"

void		prevent_overflow(double coef, t_color *color)
{
  if (color->argb[0] * coef > 255)
    color->argb[0] = 255;
  else
    color->argb[0] *= coef;
  if (color->argb[1] * coef > 255)
    color->argb[1] = 255;
  else
    color->argb[1] *= coef;
  if (color->argb[2] * coef > 255)
    color->argb[2] = 255;
  else
    color->argb[2] *= coef;
}

unsigned int	get_coef(t_prog *prog, t_vec *vec, t_vec *res, double *coef)
{
  unsigned int	color;

  color = prog->object[prog->target.elem].color.full;
  if (prog->object[prog->target.elem].type == 2)
    color = damier(prog, vec);
  if (prog->object[prog->target.elem].type == 3)
    *coef = -(res->x * vec->x + res->z * vec->z);
  else
    *coef = -(res->y * vec->y) * prog->options.lum_coef;
  return (color);
}

double		to_rad(double angle)
{
  return (angle * (M_PI / 180));
}

void		apply_norme(t_vec *vec, double norme)
{
  vec->x /= norme;
  vec->y /= norme;
  vec->z /= norme;
}

double		norme(t_vec *vec)
{
  return (sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}
