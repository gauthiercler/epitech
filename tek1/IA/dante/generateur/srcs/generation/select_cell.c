/*
** select_cell.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/generation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 21:59:47 2016 Buyumad Anas
** Last update Sat May 21 16:52:54 2016 Gauthier Cler
*/

#include	"perfection.h"

t_list		*select_backtrack(t_list **list)
{
  t_list	*tmp;

  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  return (tmp);
}

int		get_nb_cells(t_list **list)
{
  t_list	*tmp;
  int		count;

  count = 0;
  tmp = *list;
  while (tmp != NULL)
    {
      count += 1;
      tmp = tmp->next;
    }
  return (count);
}

t_list		*get_pick(t_list **list, int pick)
{
  t_list	*tmp;
  int		count;

  count = 0;
  tmp = *list;
  while (count < pick && tmp->next != NULL)
    {
      tmp = tmp->next;
      count += 1;
    }
  return (tmp);
}

t_list		*select_prim(t_list **list)
{
  int		nb_cells;
  int		pick;

  nb_cells = get_nb_cells(list);
  if (nb_cells == 0)
    return (NULL);
  pick = rand() % nb_cells;
  return (get_pick(list, pick));
}

t_list		*select_cell(t_list **list, int mode)
{
  if (mode == BACKTRACK)
    return (*list);
  else if (mode == PRIM)
    return (select_prim(list));
  return (NULL);
}
