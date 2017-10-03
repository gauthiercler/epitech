/*
** response_fork.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/parser/ai/response/response_fork.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat Jul 01 14:25:29 2017 Montagne Valentin
** Last update Sat Jul 01 14:25:29 2017 Montagne Valentin
*/

#include		"parse_stream.h"

static void		send_to_gfx(t_list *list,
				       t_egg *egg)
{
  t_graph_client	*gfx;
  t_list_node		*tmp;

  tmp = list->list;
  while (tmp)
  {
    gfx = tmp->data;
    gfx->send_egg_spawn(gfx, egg);
    tmp = tmp->next;
  }
}

bool			response_fork(t_player *player, t_server *server)
{
  t_tile		*current_tile;
  t_egg			*negg;

  negg = new_egg(&server->config, &player->position, player->team);
  current_tile =
    server->map->get_tile_by_position(server->map, &player->position);
  current_tile->add_egg(current_tile, negg);
  player->team->eggs->push(player->team->eggs, negg);
  send_to_gfx(server->gfx->list, negg);
  return (player->send(player, "ok\n"));
}