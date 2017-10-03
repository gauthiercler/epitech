/*
** response_right.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/parser/ai/response/response_right.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 30 13:53:19 2017 Montagne Valentin
** Last update Fri Jun 30 13:53:19 2017 Montagne Valentin
*/

#include		"parse_stream.h"

static bool		send_right_gfx(t_graph_client *gfx, t_player *player)
{
  return (gfx->send_player_position(gfx, player));
}

bool			response_right(t_player *player, t_server *server)
{
  player->turn(player, PLAYER_RIGHT);
  player->send(player, "ok\n");
  server->gfx->apply(server->gfx, (t_list_action)(send_right_gfx), player);
  return (true);
}