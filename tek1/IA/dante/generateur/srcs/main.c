/*
** main.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 15:27:49 2016 Buyumad Anas
** Last update Fri May 27 14:57:46 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<time.h>
#include	"perfection.h"

int		get_gen_mode(char *str)
{
  if (str == NULL)
    return (0);
  return (1);
}

void		fill_gaps(t_perfect *perfect)
{
  int		row;
  int		column;

  row = 0;
  while (row < perfect->map.height)
    {
      column = 0;
      while (column < perfect->map.width)
	{
	  if (perfect->map.cells[row][column] == UNSET)
	    perfect->map.cells[row][column] = WALL;
	  column += 1;
	}
      row += 1;
    }
}

void		generation(t_perfect *perfect)
{
  t_list	*cell;
  int		direction;

  gen_start(perfect);
  while (generation_over(&perfect->map) == ERROR)
    {
      if (perfect->list == NULL)
	{
	  fill_gaps(perfect);
	  return ;
	}
      cell = select_cell(&perfect->list, perfect->type);
      if ((direction = pick_neighbor(perfect->list, &perfect->map, cell)) == -1)
	{
	  perfect->map.cells[cell->cell.pos_y][cell->cell.pos_x] = PATH;
	  delete_elem(&perfect->list, cell);
	}
      else
	assess_direction(perfect, cell, direction);
    }
}

int		perfection(char **av)
{
  t_perfect	perfect;
  time_t 	t;

  if (check_arguments(av) == ERROR)
    return (ERROR);
  perfect.list = NULL;
  perfect.debug = false;
  perfect.map.width = atoi(av[1]);
  perfect.map.height = atoi(av[2]);
  perfect.mode = get_gen_mode(av[3]);
  perfect.type = 0;
  srand((unsigned) time(&t));
  gen_map(&perfect.map);
  generation(&perfect);
  if (perfect.mode == 0)
    imperfection(&perfect);
  write_map(&perfect.map);
  clean_map(&perfect.map);
  return (SUCCESS);
}

int		main(int ac, char **av)
{
  if (ac != 4 && ac != 3)
    {
      display_usage();
      return (1);
    }
  else
    {
      if ((perfection(av)) == ERROR)
	return (1);
    }
  return (SUCCESS);
}
