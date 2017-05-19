/*
** list.c for list in /home/gogo/rendu/dante/profondeur/srcs/list/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 14:23:58 2016 Gauthier Cler
** Last update Thu May  5 16:22:51 2016 Gauthier Cler
*/

#include	"solver.h"

void		change_node(t_node *node, t_node new)
{
  t_node	*tmp;

  tmp = node;
  while (tmp->pos.x != new.pos.x || tmp->pos.y != new.pos.y)
    tmp = tmp->next;
  tmp->father.x = new.father.x;
  tmp->father.y = new.father.y;
  tmp->g = new.g;
}

void		add_node(t_node **node, t_node son)
{
  t_node	*new;

  new = xmalloc(sizeof(t_node));
  new->pos.x = son.pos.x;
  new->pos.y = son.pos.y;
  new->father.x = son.father.x;
  new->father.y = son.father.y;
  new->g = son.g;
  new->f = son.f;
  new->h = heuristic(new->pos.x, new->pos.y);
  new->next = *node;
  *node = new;
}

void		add_to_list(t_list **list, int x, int y)
{
  t_list	*save;

  save = xmalloc(sizeof(t_list));
  save->x = x;
  save->y = y;
  save->next = *list;
  *list = save;
}

void		switch_list(t_node **closed, t_node **open, t_node *selected)
{
  t_node	*tmp;
  t_node	*old;
  t_node	new;

  old = NULL;
  new.pos.x = selected->pos.x;
  new.pos.y = selected->pos.y;
  new.father.x = selected->father.x;
  new.father.y = selected->father.y;
  new.f = selected->f;
  new.g = selected->g;
  new.h = selected->h;
  add_node(closed, new);
  tmp = *open;
  while ((tmp->pos.x != selected->pos.x || tmp->pos.y != selected->pos.y) && tmp)
    {
      old = tmp;
      tmp = tmp->next;
    }
  if (old == NULL)
    *open = tmp->next;
  else
    old->next = tmp->next;
}
