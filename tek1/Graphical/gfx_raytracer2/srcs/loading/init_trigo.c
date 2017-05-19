/*
** init_trigo.c for init_trigo in /home/gogo/rendu/gfx_raytracer2/srcs/loading/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat May 14 16:57:04 2016 Gauthier Cler
** Last update Sat May 14 18:40:12 2016 Gauthier Cler
*/

#include	"raytracer.h"

void		init_trigo()
{
  int		count;
  float		converted;

  count = 0;
  while (count < 360)
    {
      converted = (M_PI * (float)count) / 180.0;
      xcos[count] = cosf(converted);
      xsin[count] = sinf(converted);
      count += 1;
    }
}
