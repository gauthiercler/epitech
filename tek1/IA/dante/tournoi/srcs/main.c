/*
** main.c for solver in /home/gogo/rendu/dante/profondeur/srcs/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:12:03 2016 Gauthier Cler
** Last update Sat May 21 17:39:35 2016 Gauthier Cler
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<time.h>
#include	"solver.h"

void		disp_map(char **map)
{
  int		i;
  int		j;

  i = 0;
  while (map[i])
    {
      j = 0;
      while (map[i][j])
	{
	  if (map[i][j] == VISITED)
	    {
	      format(1, "\e[31m");
	      write(1, &map[i][j], 1);
	      format(1, "\e[0m");
	    }
	  else
	    write(1, &map[i][j], 1);
	  j += 1;
	}
      write(1, "\n", 1);
      i += 1;
    }
}

void		disp_opti(char **map)
{
  int		i;

  i = 0;
  while (map[i])
    {
      if (map[i + 1] != NULL)
	format(1, "%s\n", map[i]);
      else
	format(1, "%s", map[i]);
      i += 1;
    }
}

int		solver(char *filename, bool color_flag, bool count_flag)
{
  t_solve	solve;
  int		counter;

  if ((solve.map.array = load_map(filename, &solve.map.size_x,
				  &solve.map.size_y)) == NULL)
    return (ERROR);
  solve.list = NULL;
  if ((solve.list = solve_maze(&solve.map)) == NULL)
    {
      format(1, "No solution found\n");
      return (ERROR);
    }
  empty_map(solve.map.array);
  fill_map(solve.map.array, solve.list, &counter);
  if (color_flag == true)
    disp_map(solve.map.array);
  else
    disp_opti(solve.map.array);
  if (count_flag == true)
    format(1, "%d steps from start to end\n", counter);
  clean_map(solve.map.array);
  clean_list(solve.list);
  return (SUCCESS);
}

int		main(int ac, char **av)
{
  bool		color_flag;
  bool		count_path;

  color_flag = false;
  count_path = false;
  if (ac < 2)
    return (print_usage());
  if (check_args(ac, av, &color_flag, &count_path) == ERROR)
    return (print_usage());
  return (solver(av[1], color_flag, count_path));
}
