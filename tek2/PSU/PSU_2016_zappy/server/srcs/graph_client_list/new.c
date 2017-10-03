/*
** new.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/graph_client_list/new.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 30 11:39:54 2017 Antoine FORET
** Last update Fri Jun 30 11:39:54 2017 Antoine FORET
*/

#include	"graph_client.h"

static void		graph_client_list_methods(t_graph_client_list *self)
{
  self->apply = graph_client_list_apply;
  self->empty = graph_client_list_empty;
  self->pop = graph_client_list_pop;
  self->push = graph_client_list_push;
  self->new_player = graph_client_list_new_player;
  self->destroy = graph_client_list_destroy;
}

static bool		graph_client_list_init(t_graph_client_list *self)
{
  self->list = new_list();
  return (self->list != NULL);
}

t_graph_client_list	*new_graph_client_list()
{
  t_graph_client_list	*self;

  self = malloc(sizeof(t_graph_client_list));
  if (self == NULL)
    return (false);
  graph_client_list_methods(self);
  if (!graph_client_list_init(self))
  {
    self->destroy(self);
    return (NULL);
  }
  return (self);
}