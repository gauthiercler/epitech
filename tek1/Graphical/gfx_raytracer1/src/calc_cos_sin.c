/*
** calc_cos_sin.c for calc_cos_sin in /home/gogo/rendu/gfx_raytracer1/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Sun Mar  6 18:19:34 2016 Gauthier Cler
** Last update Sun Mar  6 21:56:50 2016 Gauthier Cler
*/

#include	"raytracer.h"

void		init_cos_sin(double *dcos, double *dsin)
{
  int		i;

  i = 0;
  while (i < 360)
    {
      dcos[i] = cos(M_PI * i / 180);
      dsin[i] = sin(M_PI * i / 180);
      i += 1;
    }
}
