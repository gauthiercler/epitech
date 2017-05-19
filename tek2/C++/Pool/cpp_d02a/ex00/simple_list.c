/*
** simple_list.c for cpp_d02a in /home/gogo/rendu/tek2/cpp_d02a/ex00/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan  5 16:39:46 2017 Gauthier Cler
** Last update Thu Jan  5 20:29:10 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"simple_list.h"

unsigned int	list_get_size(t_list list)
{
  unsigned int	size = 0;

  while (list){
      list = list->next;
      size += 1;
    }
 return size;
}

t_bool		list_is_empty(t_list list)
{
  if (!list)
    return FALSE;
  return TRUE;
}

void		list_dump(t_list list)
{
  while (list){
      printf("%f\n", list->value);
      list = list->next;
    }
}

t_bool		list_add_elem_at_front(t_list *front_ptr, double elem)
{
  t_list	new_ptr;

  new_ptr = malloc(sizeof(t_node));
  if (!new_ptr)
    return FALSE;
  new_ptr->value = elem;
  if (front_ptr)
    new_ptr->next = *front_ptr;
  else
    new_ptr->next = NULL;
  *front_ptr = new_ptr;
  return TRUE;
}

t_bool		list_add_elem_at_back(t_list *front_ptr, double elem)
{
  t_list	new_ptr;
  t_list	tmp = *front_ptr;

  new_ptr = malloc(sizeof(t_node));
  if (!new_ptr)
    return FALSE;
  new_ptr->value = elem;
  new_ptr->next = NULL;
  if (!tmp){
      *front_ptr = new_ptr;
      return TRUE;
    }
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new_ptr;
  return TRUE;
}

t_bool		list_add_elem_at_position(t_list *front_ptr, double elem, unsigned int position)
{
  t_list	new_ptr;
  t_list	tmp = *front_ptr;
  t_list	old;
  unsigned int	size;
  unsigned int	iterator = 0;

  if (position == 0)
    return list_add_elem_at_front(front_ptr, elem);
  size = list_get_size(*front_ptr);
  if (size < position)
    return FALSE;
  else if (size == position)
    return list_add_elem_at_back(front_ptr, elem);
  new_ptr = malloc(sizeof(t_node));
  if (!new_ptr)
    return FALSE;
  new_ptr->value = elem;
  while (iterator < position - 1){
      tmp = tmp->next;
      iterator += 1;
    }
  old = tmp;
  tmp = tmp->next;
  old->next = new_ptr;
  new_ptr->next = tmp;
  return TRUE;
}

t_bool		list_del_elem_at_front(t_list *front_ptr)
{
  t_list	tmp = *front_ptr;

  if (!front_ptr)
    return FALSE;
  if (tmp->next)
    *front_ptr = tmp->next;
  else
    *front_ptr = NULL;
  free(tmp);
  return TRUE;
}

t_bool		list_del_elem_at_back(t_list *front_ptr)
{
  t_list	tmp = *front_ptr;
  t_list	old;

  if (!front_ptr)
    return FALSE;
  if (!tmp->next)
    return list_del_elem_at_front(front_ptr);
  while (tmp->next)
    {
      old = tmp;
      tmp = tmp->next;
    }
  old->next = NULL;
  free(tmp);
  return TRUE;
}

t_bool		list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
  t_list	tmp = *front_ptr;
  t_list	old;
  unsigned int	iterator;
  unsigned int	size;

  if (!front_ptr)
    return FALSE;
  size = list_get_size(*front_ptr);
  if (position > size)
    return FALSE;
  if (position == 0)
    return list_del_elem_at_front(front_ptr);
  if (position == size)
    return list_del_elem_at_back(front_ptr);
  iterator = 1;
  while (iterator < position)
    {
      iterator += 1;
      tmp = tmp->next;
    }
  old = tmp->next;
  tmp->next = old->next;
  free(old);
  return TRUE;
}

double		list_get_elem_at_front(t_list list)
{
  if (!list)
    return 0;
  return list->value;
}

double		list_get_elem_at_back(t_list list)
{
  if (!list)
    return 0;
  while (list->next)
   list = list->next;
  return list->value;
}

double		list_get_elem_at_position(t_list list, unsigned int position)
{
  unsigned int		iterator = 0;

  if (!list)
    return 0;
  if (position > list_get_size(list))
    return 0;
  while (iterator < position){
      list = list->next;
      iterator += 1;
    }
  return list->value;
}

t_node		*list_get_first_node_with_value(t_list list, double value)
{
  if (!list)
    return NULL;
  while (list)
    {
      if (list->value == value)
	return list;
     list = list->next;
    }
  return NULL;
}
