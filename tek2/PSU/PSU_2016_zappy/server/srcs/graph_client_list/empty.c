/*
** empty.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/graph_client_list/empty.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 30 11:46:31 2017 Antoine FORET
** Last update Fri Jun 30 11:46:31 2017 Antoine FORET
*/

#include	"graph_client.h"

static bool	empty(t_graph_client *self)
{
  if (self != NULL)
    self->destroy(self);
  return (true);
}

void		graph_client_list_empty(t_graph_client_list *self)
{
  self->apply(self, (t_list_action)(empty), NULL);
}