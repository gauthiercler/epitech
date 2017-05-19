/*
** get_simple_root.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/intersection/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri May 13 15:39:35 2016 Buyumad Anas
** Last update Fri May 13 15:43:35 2016 Buyumad Anas
*/

#include	"raytracer.h"

float		get_simple_root(float a, float b)
{
  if (a == 0.0000)
    return (IMPOSSIBLE);
  return (((-1.0) * b) / a);
}
