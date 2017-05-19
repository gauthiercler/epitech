/*
** ray_check.c for ray_check in /home/gauthier/rendu/gfx_wolf3d/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Jan  2 18:51:18 2016 Gauthier Cler
** Last update Sun Jan  3 22:16:21 2016 Gauthier Cler
*/

#include	"wolf.h"

void	check_ray_dir(t_prog *prog, float delta_x, float delta_y)
{
  if (prog->ray.dir_x < 0)
    prog->side.dis_x = (prog->player.pos_x - prog->map.x) * delta_x;
  else
    prog->side.dis_x = (prog->map.x + 1 - prog->player.pos_x) * delta_x;
  if (prog->ray.dir_y < 0)
    prog->side.dis_y = (prog->player.pos_y - prog->map.y) * delta_y;
  else
    prog->side.dis_y = (prog->map.y + 1 - prog->player.pos_y) * delta_y;
}

void    loop_ray(t_prog *prog, float delta_x, float delta_y)
{
  while (prog->map.array[prog->map.x][prog->map.y] == 0)
    {
      if (prog->side.dis_x < prog->side.dis_y)
	{
	  prog->side.dis_x += delta_x;
	  if (prog->ray.dir_x < 0)
	    prog->map.x -= 1;
	  else
	    prog->map.x += 1;
	  prog->side.dir = 0;
	}
      else
	{
	  prog->side.dis_y += delta_y;
	  if (prog->ray.dir_y < 0)
	    prog->map.y -= 1;
	  else
	    prog->map.y += 1;
	  prog->side.dir = 1;
	}
    }
}
