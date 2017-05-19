/*
** delete_elem.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/list/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 21:19:40 2016 Buyumad Anas
** Last update Sat May 21 19:11:22 2016 Buyumad Anas
*/

#include	"perfection.h"

void		delete_elem(t_list **list, t_list *elem)
{
  t_list	*tmp;
  t_list	*old;

  tmp = *list;
  old = NULL;
  while (tmp != NULL)
    {
      if (elem->cell.pos_x == tmp->cell.pos_x &&
	  elem->cell.pos_y == tmp->cell.pos_y)
	{
	  if (old == NULL)
	    *list = tmp->next;
	  else
	    old->next = tmp->next;
	}
      old = tmp;
      tmp = tmp->next;
    }
}
