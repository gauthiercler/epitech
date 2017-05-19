/*
** main.c for solver in /home/gogo/rendu/dante/profondeur/srcs/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:12:03 2016 Gauthier Cler
** Last update Sat May 21 19:02:19 2016 Buyumad Anas
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<time.h>
#include	"amazing.h"

char		**load_breadth_array(t_map *map, int size_x, int size_y)
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

int		solver_b(t_amazing *amazing)
{
  int		counter;

  amazing->solver_breadth.map.size_x = amazing->width;
  amazing->solver_breadth.map.size_y = amazing->height;
  amazing->solver_breadth.map.array =
      load_breadth_array(&amazing->perfect.map,
			 amazing->solver_breadth.map.size_x,
			 amazing->solver_breadth.map.size_y);
  amazing->solver_breadth.list = NULL;
  if ((amazing->solver_breadth.list =
       solve_maze_b(amazing, &amazing->solver_breadth.map)) == NULL)
    {
      format(1, "No solution\n");
      return (ERROR);
    }
  empty_mapb(amazing->solver_breadth.map.array);
  fill_mapb(amazing->solver_breadth.map.array, amazing->solver_breadth.list,
	    &counter);
  draw_maze_breadth(amazing);
  SDL_Flip(amazing->Screen);
  usleep(amazing->speed);
  clean_listb(amazing->solver_breadth.list);
  return (SUCCESS);
}
