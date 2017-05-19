/*
** list.c for list in /home/gogo/rendu/dante/profondeur/srcs/list/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 14:23:58 2016 Gauthier Cler
** Last update Sun May  1 12:22:07 2016 Gauthier Cler
*/

#include	"solver.h"

void		add_to_list(t_list **list, int x, int y)
{
  t_list	*save;

  save = xmalloc(sizeof(t_list));
  save->x = x;
  save->y = y;
  save->next = *list;
  *list = save;
}

void		add_pile(t_pile **list, t_pos pos, t_pos father, t_map *map)
{
  t_pile	*save;

  save = xmalloc(sizeof(t_pile));
  save->x = pos.x;
  save->y = pos.y;
  save->father_x = father.x;
  save->father_y = father.y;
  if (map != NULL)
    if (map->array[pos.y][pos.x] != EXIT)
      map->array[pos.y][pos.x] = WAITING;
  save->next = *list;
  *list = save;
}

void		add_end_save(t_pile **p, t_pos pos, t_pile *father, t_map *map)
{
  t_pile	*save;

  save = xmalloc(sizeof(t_pile));
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

void		add_end_pile(t_pile **p, t_pos pos, int father_x, int father_y)
{
  t_pile	*save;
  t_pile	*tmp;

  save = xmalloc(sizeof(t_pile));
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

void		switch_list(t_pile **visited, t_pile **pile)
{
  t_pile	*tmp;
  t_pos		pos;
  t_pos		father;

  if (*pile == NULL)
    return ;
  father.x = (*pile)->father_x;
  father.y = (*pile)->father_y;
  pos.x = (*pile)->x;
  pos.y = (*pile)->y;
  tmp = (*pile)->next;
  add_pile(visited, pos, father, NULL);
  free(*pile);
  *pile = tmp;
}
