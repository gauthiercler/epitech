/*
** display_list.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/list/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 20:58:00 2016 Buyumad Anas
** Last update Thu Apr 28 15:44:14 2016 Buyumad Anas
*/

#include	"perfection.h"

void		display_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      format(2, "Elem -\n");
      format(2, "Cell -> X : %d, Y : %d\n", tmp->cell.pos_x, tmp->cell.pos_y);
      format(2, "Link -> X : %d, Y : %d\n", tmp->link.pos_x, tmp->link.pos_y);
      format(2, "-\n");
      tmp = tmp->next;
    }
}
