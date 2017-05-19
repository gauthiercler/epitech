/*
** add_elem.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/list/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 20:36:17 2016 Buyumad Anas
** Last update Sun May  1 12:30:51 2016 Gauthier Cler
*/

#include	"perfection.h"

void		add_elem(t_list **list, t_cell *cell, t_cell *link)
{
  t_list	*elem;

  elem = xmalloc(sizeof(t_list));
  elem->cell.pos_x = cell->pos_x;
  elem->cell.pos_y = cell->pos_y;
  elem->link.pos_x = link->pos_x;
  elem->link.pos_y = link->pos_y;
  elem->next = *list;
  *list = elem;
}
