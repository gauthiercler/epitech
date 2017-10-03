/*
** pop.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/graph_client_list/pop.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 30 11:48:15 2017 Antoine FORET
** Last update Fri Jun 30 11:48:15 2017 Antoine FORET
*/

#include	"graph_client.h"

void		graph_client_list_pop(t_graph_client_list *self,
					  t_graph_client *client)
{
  self->list->pop_data(self->list, client);
}