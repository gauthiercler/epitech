/*
** is_cell_in_list.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/generation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 22:43:29 2016 Buyumad Anas
** Last update Thu Apr 28 20:07:25 2016 Buyumad Anas
*/

#include	"perfection.h"

int		is_not_link(t_cell *link, t_cell *cell)
{
  if ((cell->pos_x != link->pos_x) || (cell->pos_y != link->pos_y))
    return (SUCCESS);
  else
    return (ERROR);
}

int		is_cell(t_list *list, t_cell *cell)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if ((tmp->cell.pos_x == cell->pos_x) &&
	  (tmp->cell.pos_y == cell->pos_y))
	return (SUCCESS);
      tmp = tmp->next;
    }
  return (ERROR);
}
