/*
** render.c for render in /home/gogo/rendu/gfx_raytracer1/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Sun Mar  6 17:22:39 2016 Gauthier Cler
** Last update Sun Mar 13 13:00:17 2016 Gauthier Cler
*/

#include	"raytracer.h"

void			render(t_prog *prog)
{
  t_bunny_position	pos;

  pos.y = 0;
  while (pos.y < prog->pix->clipable.buffer.height)
    {
      pos.x = 0;
      while (pos.x < prog->pix->clipable.buffer.width)
	{
	  calc_ray((double)pos.x, (double)pos.y, prog);
	  pos.x += 1;
	}
      pos.y += 1;
    }
}
