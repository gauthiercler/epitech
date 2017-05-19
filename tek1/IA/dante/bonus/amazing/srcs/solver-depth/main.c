/*
** main.c for solver in /home/gogo/rendu/dante/profondeur/srcs/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:12:03 2016 Gauthier Cler
** Last update Sun May 22 19:17:05 2016 Gauthier Cler
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<time.h>
#include	"amazing.h"

char		**load_depth_array(t_map *map, int size_x, int size_y)
{
  char		**array;
  int		i;
  int		j;

  i = 0;
  array = xmalloc(sizeof(char *) * (size_y + 1));
  while (i < size_y)
    {
      j = 0;
      array[i] = xmalloc(sizeof(char) * (size_x + 1));
      while (j < size_x)
	{
	  if (map->cells[i][j] == PATH)
	    array[i][j] = POSSIBLE;
	  else if (map->cells[i][j] == WALL)
	    array[i][j] = WALL_DEPTH;
	  j += 1;
	}
      array[i][j] = '\0';
      i += 1;
    }
  array[i] = NULL;
  return (array);
}

void		disdds(t_map_depth *map)
{
  int		row;
  int		column;

  row = 0;
  while (row < map->size_y)
    {
      column = 0;
      while (column < map->size_x)
	{
	  write(1, &map->array[row][column], 1);
	  write(1, " ", 1);
	  column += 1;
	}
      format(1, "\n");
      row += 1;
    }
}

int		solver(t_amazing *amazing)
{
  int		counter;

  amazing->solver.map.size_x = amazing->width;
  amazing->solver.map.size_y = amazing->height;
  amazing->solver.map.array = load_depth_array(&amazing->perfect.map,
					       amazing->solver.map.size_x,
					       amazing->solver.map.size_y);
  amazing->solver.list = NULL;
  if ((amazing->solver.list = solve_maze(&amazing->solver.map, amazing)) == NULL)
    {
      format(1, "No solution found\n");
      return (ERROR);
    }
  empty_map(amazing->solver.map.array);
  fill_map(amazing->solver.map.array, amazing->solver.list, &counter);
  draw_maze_depth(amazing);
  SDL_Flip(amazing->Screen);
  usleep(amazing->speed);
  clean_list(amazing->solver.list);
  return (SUCCESS);
}
