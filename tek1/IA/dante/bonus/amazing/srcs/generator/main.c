/*
** main.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 15:27:49 2016 Buyumad Anas
** Last update Wed May  4 14:51:23 2016 Buyumad Anas
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<time.h>
#include	"amazing.h"

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

void		generation(t_perfect *perfect, t_amazing *amazing)
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
      draw_maze(amazing);
      SDL_Flip(amazing->Screen);
      usleep(amazing->speed);
    }
}

int		perfection(t_amazing *amazing)
{
  amazing->perfect.list = NULL;
  amazing->perfect.map.width = amazing->width;
  amazing->perfect.map.height = amazing->height;
  amazing->perfect.mode = amazing->gen_mode;
  amazing->perfect.filename = NULL;
  amazing->perfect.type = amazing->gen_type;
  amazing->perfect.debug = 0;
  init_random();
  generation(&amazing->perfect, amazing);
  if (amazing->perfect.mode == 0)
    imperfection(&amazing->perfect);
  printf("Done generating.\n");
  return (SUCCESS);
}
