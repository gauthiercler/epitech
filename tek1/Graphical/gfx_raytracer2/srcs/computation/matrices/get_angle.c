/*
** get_angle.c for get_angle in /home/gogo/rendu/gfx_raytracer2/srcs/computation/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat May 14 17:15:22 2016 Gauthier Cler
** Last update Sat May 14 18:19:31 2016 Gauthier Cler
*/

#include	"raytracer.h"

int		get_angle(int angle)
{
  if (angle == -0)
    angle = 0;
  if (angle < 0)
    angle = 360 - abs(angle);
  if (angle == 360)
    angle = 0;
  return (angle);
}
