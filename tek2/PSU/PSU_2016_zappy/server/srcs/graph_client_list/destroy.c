/*
** destroy.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/graph_client_list/destroy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 30 11:44:37 2017 Antoine FORET
** Last update Fri Jun 30 11:44:37 2017 Antoine FORET
*/

#include	"graph_client.h"

void		graph_client_list_destroy(t_graph_client_list *self)
{
  if (self->list != NULL)
    self->list->destroy(self->list);
  free(self);
}