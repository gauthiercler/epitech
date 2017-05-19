/*
** main.c for solver in /home/gogo/rendu/dante/profondeur/srcs/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:12:03 2016 Gauthier Cler
** Last update Sun May 22 17:53:41 2016 Gauthier Cler
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<time.h>
#include	"amazing.h"

int		goal_x;
int		goal_y;

char		**load_star_array(t_map *map, int size_x, int size_y)
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

int		solvera(t_amazing *amazing)
{
  int		counter;

  amazing->solve_astar.map.size_x = amazing->width;
  amazing->solve_astar.map.size_y = amazing->height;
  amazing->solve_astar.map.array =
      load_star_array(&amazing->perfect.map,
		      amazing->solve_astar.map.size_x,
		      amazing->solve_astar.map.size_y);
  amazing->solve_astar.list = NULL;
  if ((amazing->solve_astar.list =
       solve_maze_a(amazing, &amazing->solve_astar.map)) == NULL)
    {
      format(1, "No solution\n");
      return (ERROR);
    }
  empty_mapa(amazing->solve_astar.map.array);
  fill_mapa(amazing->solve_astar.map.array, amazing->solve_astar.list, &counter);
  draw_maze_star(amazing);
  SDL_Flip(amazing->Screen);
  clean_lista(amazing->solve_astar.list);
  return (SUCCESS);
}
