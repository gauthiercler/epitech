/*
** ini.c for ini in /home/gauthier/rendu/gfx_wolf3d/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Dec 23 14:37:51 2015 Gauthier Cler
** Last update Sun Jan  3 12:51:46 2016 Gauthier Cler
*/

#include	"wolf.h"

int	**read_ini(t_prog *prog)
{
  int	i;
  int	**map;

  i = 0;
  prog->map.width =
    my_atoi(bunny_ini_get_field(prog->ini, "level1", "width", 0));
  prog->map.height =
    my_atoi(bunny_ini_get_field(prog->ini, "level1", "height", 0));
  prog->player.pos_x =
    my_atoi(bunny_ini_get_field(prog->ini, "level1", "start_position", 0)) + 1;
  prog->player.pos_y =
    my_atoi(bunny_ini_get_field(prog->ini, "level1", "start_position", 1)) + 1;
  prog->player.angle =
    my_atof(bunny_ini_get_field(prog->ini, "level1", "start_position", 2));
  prog->player.angle = prog->player.angle * M_PI / 180;
  map = bunny_malloc(sizeof(int *) * prog->map.width);
  while (i < prog->map.width)
    {
      map[i] = bunny_malloc(sizeof(int) * prog->map.height);
      i++;
    }
  fill_map(prog, map);
  return (map);
}

void	fill_map(t_prog *prog, int **map)
{
  int	i;
  int	j;
  int	k;

  k = 0;
  i = 0;
  j = 0;
  while (j < prog->map.width)
    {
      while (i < prog->map.height)
	{
	  map[j][i] =
	    my_atoi(bunny_ini_get_field(prog->ini, "level1", "data", k));
	  i++;
	  k++;
	}
      i = 0;
      j++;
    }
}
