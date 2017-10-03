/*
** level_up.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/player/level_up.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 14:57:53 2017 Montagne Valentin
** Last update Mon Jun 26 14:57:53 2017 Montagne Valentin
*/

#include		"player.h"

void				player_level_up(t_player *self,
						    t_graph_client_list *gfx)
{
  t_list_node			*tmp;
  t_graph_client		*g;

  self->level += 1;
  tmp = gfx->list->list;
  while (tmp)
  {
    g = tmp->data;
    g->send_player_lvl(g, self);
    tmp = tmp->next;
  }
}