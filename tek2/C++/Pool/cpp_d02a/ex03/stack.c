/*
** stack.c for cpp_d02 in /home/gogo/rendu/tek2/cpp_d02a/ex03/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan  5 23:50:10 2017 Gauthier Cler
** Last update Thu Jan  5 23:55:29 2017 Gauthier Cler
*/

#include	"stack.h"

unsigned int stack_get_size(t_stack stack)
{
  return list_get_size(stack);
}

t_bool          stack_is_empty(t_stack stack)
{
  return list_is_empty(stack);
}

t_bool  stack_push(t_stack *stack_ptr, void *elem)
{
  return list_add_elem_at_front(stack_ptr, elem);
}

t_bool  stack_pop(t_stack *stack_ptr)
{
  return list_del_elem_at_front(stack_ptr);
}

void    *stack_top(t_stack stack)
{
  return list_get_elem_at_position(stack, 0);
}
