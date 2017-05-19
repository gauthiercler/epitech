/*
** compute_ray.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/rays/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue May 10 17:28:00 2016 Buyumad Anas
** Last update Sun May 22 15:37:38 2016 Buyumad Anas
*/

#include	"raytracer.h"

void		compute_space_ray(t_position *origin, t_position *target,
				  t_position *vector)
{
  vector->x = target->x - origin->x;
  vector->y = target->y - origin->y;
  vector->z = target->z - origin->z;
}

void		compute_ray(t_position *origin, t_position *target,
			    t_position *vector)
{
  vector->x = target->x - (SCREEN_WIDTH / 2);
  vector->y = (SCREEN_HEIGHT / 2) - target->y;
  vector->z = target->z - origin->z;
}
