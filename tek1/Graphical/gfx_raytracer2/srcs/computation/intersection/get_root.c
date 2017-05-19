/*
** get_root.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/intersection/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed May 11 19:20:35 2016 Buyumad Anas
** Last update Thu May 12 16:11:39 2016 Buyumad Anas
*/

#include	"raytracer.h"

float		get_root(float a, float b, float c)
{
  float		delta;
  float		first_root;
  float		second_root;

  if (a == 0.0000)
    return (IMPOSSIBLE);
  delta = (b * b) - (4.0 * a * c);
  if (delta < 0.00000)
    return (IMPOSSIBLE);
  if (delta == 0.00000)
    return (((-1.0) * b) / (2.0 * a));
  first_root = (((-1.0) * b) - sqrt(delta)) / (2.0 * a);
  second_root = (((-1.0) * b) + sqrt(delta)) / (2.0 * a);
  if (first_root <= second_root)
    return (first_root);
  return (second_root);
}
