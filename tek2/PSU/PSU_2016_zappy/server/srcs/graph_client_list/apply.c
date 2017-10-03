/*
** apply.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/graph_client_list/apply.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 30 11:45:26 2017 Antoine FORET
** Last update Fri Jun 30 11:45:26 2017 Antoine FORET
*/

#include	"graph_client.h"

bool		graph_client_list_apply(
  t_graph_client_list *self, t_list_action action, void *params)
{
  return (self->list->foreach(self->list, action, params));
}