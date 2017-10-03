/*
** new_player.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/graph_client_list/new_player.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jul 01 11:58:58 2017 Antoine FORET
** Last update Sat Jul 01 11:58:58 2017 Antoine FORET
*/

#include	"graph_client.h"

bool		graph_client_list_new_player(t_graph_client_list *self,
						 t_player *player)
{
  return (self->apply(self, (t_list_action)(send_player_spawn), player));
}