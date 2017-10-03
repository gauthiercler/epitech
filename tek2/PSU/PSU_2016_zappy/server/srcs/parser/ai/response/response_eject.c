/*
** response_eject.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/parser/ai/response/response_eject.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Fri Jun 30 22:10:33 2017 Clement Nancelle
** Last update Fri Jun 30 22:10:33 2017 Clement Nancelle
*/

#include		"parse_stream.h"

static void		set_position(t_player_ref *ejector, t_player *player)
{
  if (ejector->player->direction == P_NORTH)
  {
    player->position.y = ejector->player->position.y - 1;
    player->position.x = ejector->player->position.x;
  }
  else if (ejector->player->direction == P_SOUTH)
  {
    player->position.y = ejector->player->position.y + 1;
    player->position.x = ejector->player->position.x;
  }
  else if (ejector->player->direction == P_WEST)
  {
    player->position.y = ejector->player->position.y;
    player->position.x = ejector->player->position.x - 1;
  }
  else
  {
    player->position.y = ejector->player->position.y;
    player->position.x = ejector->player->position.x + 1;
  }
}

static bool		send_eject_gfx(t_graph_client *gfx, t_player *player)
{
  return (gfx->send_player_position(gfx, player));
}

static bool		change_position(t_player *player,
					   t_player_ref *ejector)
{
  if (player != ejector->player
      && player->position.x == ejector->player->position.x
      && player->position.y == ejector->player->position.y)
  {
    set_position(ejector, player);
    ejector->server->map->convert(ejector->server->map, &player->position);
    ejector->pass_to += 1;
    return (ejector->server->gfx->apply(
      ejector->server->gfx, (t_list_action) send_eject_gfx, player));
  }
  return (true);
}

bool			response_eject(t_player *player, t_server *server)
{
  t_player_ref		player_ref;

  player_ref.server = server;
  player_ref.player = player;
  player_ref.pass_to = 0;
  if (server->players->apply(server->players, (t_list_action)change_position,
			     &player_ref) == false)
    return (false);
  if (player_ref.pass_to == 0)
    player->send(player, "ko\n");
  else
    player->send(player, "ok\n");
  return (true);
}