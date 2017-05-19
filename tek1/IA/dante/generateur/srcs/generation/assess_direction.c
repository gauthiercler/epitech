/*
** assess_direction.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/generation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed Apr 27 15:25:55 2016 Buyumad Anas
** Last update Sat May 21 18:58:13 2016 Buyumad Anas
*/

#include	"perfection.h"

void		set_neighbor_pos(t_cell *cell, t_cell *neighbor, int direction)
{
  if (direction == NORTH || direction == SOUTH)
    {
      neighbor->pos_x = cell->pos_x;
      (direction == NORTH) ? neighbor->pos_y = cell->pos_y - 1 : 0;
      (direction == SOUTH) ? neighbor->pos_y = cell->pos_y + 1 : 0;
    }
  else if (direction == EAST || direction == WEST)
    {
      neighbor->pos_y = cell->pos_y;
      (direction == EAST) ? neighbor->pos_x = cell->pos_x + 1 : 0;
      (direction == WEST) ? neighbor->pos_x = cell->pos_x - 1 : 0;
    }
}

void		set_neighbor_link(t_cell *link, t_cell *n_link)
{
  n_link->pos_x = link->pos_x;
  n_link->pos_y = link->pos_y;
}

void		analyze_state(int state, int *error)
{
  if (state == IMP)
    *error += 1;
}

void		assess_direction(t_perfect *perfect, t_list *cell, int direction)
{
  t_list	neighbor;
  int		error;
  int		state;

  error = 0;
  set_neighbor_pos(&cell->cell, &neighbor.cell, direction);
  set_neighbor_link(&cell->cell, &neighbor.link);
  state = check_surroundings(perfect->list, &perfect->map, &neighbor, NORTH);
  analyze_state(state, &error);
  state = check_surroundings(perfect->list, &perfect->map, &neighbor, EAST);
  analyze_state(state, &error);
  state = check_surroundings(perfect->list, &perfect->map, &neighbor, SOUTH);
  analyze_state(state, &error);
  state = check_surroundings(perfect->list, &perfect->map, &neighbor, WEST);
  analyze_state(state, &error);
  if (error == 0)
    {
      add_elem(&perfect->list, &neighbor.cell, &cell->cell);
      perfect->map.cells[neighbor.cell.pos_y][neighbor.cell.pos_x] = 8;
    }
  else
    {
      perfect->map.cells[neighbor.cell.pos_y][neighbor.cell.pos_x] = WALL;
    }
}
