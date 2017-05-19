/*
** list.c for list in /home/gogo/rendu/dante/profondeur/srcs/list/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 14:23:58 2016 Gauthier Cler
** Last update Sat May 21 18:59:23 2016 Buyumad Anas
*/

#include	"breadth.h"

void		add_to_listb(t_listb **list, int x, int y)
{
  t_listb	*save;

  save = xmalloc(sizeof(t_listb));
  save->x = x;
  save->y = y;
  save->next = *list;
  *list = save;
}

void		add_pileb(t_pileb **list, t_posb pos, int father_x,
			  int father_y)
{
  t_pileb	*save;

  save = xmalloc(sizeof(t_pileb));
  save->x = pos.x;
  save->y = pos.y;
  save->father_x = father_x;
  save->father_y = father_y;
  save->next = *list;
  *list = save;
}

void		add_end_saveb(t_pileb **p, t_posb pos, t_pileb *father,
			      t_mapbreadth *map)
{
  t_pileb	*save;

  save = xmalloc(sizeof(t_pileb));
  save->x = pos.x;
  save->y = pos.y;
  if (map->array[pos.y][pos.x] != EXIT)
  map->array[pos.y][pos.x] = WAITING;
  save->father_x = father->x;
  save->father_y = father->y;
  save->next = NULL;
  (*p)->next = save;
  (*p) = (*p)->next;
}

void		add_end_pileb(t_pileb **p, t_posb pos, int father_x,
			      int father_y)
{
  t_pileb	*save;
  t_pileb	*tmp;

  save = xmalloc(sizeof(t_pileb));
  save->x = pos.x;
  save->y = pos.y;
  save->father_x = father_x;
  save->father_y = father_y;
  save->next = NULL;
  if (*p == NULL)
    *p = save;
  else
    {
      tmp = *p;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = save;
    }
}

void		switch_listb(t_pileb **visited, t_pileb **pile)
{
  t_pileb	*tmp;
  t_posb		pos;
  int		father_x;
  int		father_y;

  if (*pile == NULL)
    return ;
  father_x = (*pile)->father_x;
  father_y = (*pile)->father_y;
  pos.x = (*pile)->x;
  pos.y = (*pile)->y;
  tmp = (*pile)->next;
  add_pileb(visited, pos, father_x, father_y);
  free(*pile);
  *pile = tmp;
}
