/*
** push.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/graph_client_list/push.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 30 11:49:35 2017 Antoine FORET
** Last update Fri Jun 30 11:49:35 2017 Antoine FORET
*/

#include	"graph_client.h"

bool		graph_client_list_push(t_graph_client_list *self,
					   t_graph_client *client)
{
  return (self->list->push_front(self->list, client));
}