/*
** response_forward.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/parser/ai/response/response_forward.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 30 11:59:42 2017 Montagne Valentin
** Last update Fri Jun 30 11:59:43 2017 Montagne Valentin
*/

#include		<stdio.h>
#include		"parse_stream.h"

static const t_position	pos[] =
  {
    { 0, -1 },
    { 1, 0 },
    { 0, 1 },
    { -1, 0 }
  };

static void		change_tile(t_map *map, t_player *player,
				       t_position *oldp)
{
  t_tile		*old;
  t_tile		*new;

  old = map->get_tile_by_position(map, oldp);
  new = map->get_tile_by_position(map, &player->position);
  old->remove_player(old, player);
  new->add_player(new, player);
}

static bool		send_forward_gfx(t_graph_client *gfx,
					    t_player *player)
{
  return (gfx->send_player_position(gfx, player));
}

bool			response_forward(t_player *player, t_server *server)
{
  t_position		oldp;

  oldp = player->position;
  player->position.x += pos[player->direction].x;
  player->position.y += pos[player->direction].y;
  server->map->convert(server->map, &player->position);
  change_tile(server->map, player, &oldp);
  server->gfx->apply(server->gfx, (t_list_action)(send_forward_gfx), player);
  return (player->send(player, "ok\n"));
}