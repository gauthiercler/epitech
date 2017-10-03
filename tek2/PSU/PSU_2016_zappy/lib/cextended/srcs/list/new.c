/*
** new.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/srcs/list/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 21 10:48:18 2017 Antoine FORET
** Last update Wed Jun 21 10:48:18 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"list.h"

static void	list_methods(t_list *self)
{
  self->size = list_size;
  self->dump = list_dump;
  self->search = list_search;
  self->foreach = list_foreach;
  self->at = list_at;
  self->front = list_front;
  self->back = list_back;
  self->push_at = list_push_at;
  self->push_front = list_push_front;
  self->push_back = list_push_back;
  self->pop_at = list_pop_at;
  self->pop_front = list_pop_front;
  self->pop_back = list_pop_back;
  self->pop_data = list_pop_data;
  self->destroy = list_destroy;
}

t_list		*new_list()
{
  t_list	*self;

  self = malloc(sizeof(t_list));
  if (self == NULL)
    return (NULL);
  list_methods(self);
  self->list = NULL;
  return (self);
}