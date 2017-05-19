/*
** main.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 15:27:49 2016 Buyumad Anas
** Last update Sun May  1 11:53:35 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<time.h>
#include	"perfection.h"

t_random	xrandom;

void		debug_display(t_map *map)
{
  format(1, "\033[1;1H");
  disp_map(map);
  getchar();
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
  if (perfect->debug)
    debug_display(&perfect->map);
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
      if (perfect->debug)
	debug_display(&perfect->map);
    }
  if (perfect->debug)
    debug_display(&perfect->map);
}

int		perfection(char **av)
{
  t_perfect	perfect;

  if (check_arguments(av) == ERROR)
    return (ERROR);
  perfect.list = NULL;
  perfect.map.width = atoi(av[1]);
  perfect.map.height = atoi(av[2]);
  perfect.mode = atoi(av[3]);
  if ((perfect.filename = strdup(av[4])) == NULL)
    return (format(2, "Couldn't perform filename malloc.\n"));
  perfect.type = atoi(av[5]);
  perfect.debug = atoi(av[6]);
  if (perfect.debug)
    format(1, "\033[2J");
  init_random();
  gen_map(&perfect.map);
  generation(&perfect);
  if (perfect.mode == 0)
    imperfection(&perfect);
  if (perfect.mode == 0 && perfect.debug)
    debug_display(&perfect.map);
  create_file(&perfect);
  clean_map(&perfect.map);
  return (SUCCESS);
}

int		main(int ac, char **av)
{
  if (ac != 7)
    display_usage();
  else
    return (perfection(av));
  return (SUCCESS);
}
