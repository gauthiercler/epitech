/*
** response_inc_begin.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/parser/ai/response/response_inc_begin.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat Jul 01 14:54:12 2017 Montagne Valentin
** Last update Sat Jul 01 14:54:12 2017 Montagne Valentin
*/

#include				<stdio.h>
#include				"parse_stream.h"

static const unsigned int		inc[INC_LVL_MAX][INC_OBJECTS] =
  {
    { 1, 1, 0, 0, 0, 0, 0 },
    { 2, 1, 1, 1, 0, 0, 0 },
    { 2, 2, 0, 1, 0, 2, 0 },
    { 4, 1, 1, 2, 0, 1, 0 },
    { 4, 1, 2, 1, 3, 0, 0 },
    { 6, 1, 2, 3, 0, 1, 0 },
    { 6, 2, 2, 2, 2, 2, 1 }
  };

static bool		is_valid(t_tile *tile, unsigned int lvl)
{
  if (tile->player_list->apply(tile->player_list,
			       (t_list_action)check_level, &lvl) == false)
    return (false);
  return (tile->nb_players(tile) == inc[lvl][I_PLAYERS]
      && tile->inventory->linemate == inc[lvl][I_LINEMATE]
      && tile->inventory->deraumere == inc[lvl][I_DERAUMERE]
      && tile->inventory->sibur == inc[lvl][I_SIBUR]
      && tile->inventory->mendiane == inc[lvl][I_MENDIANE]
      && tile->inventory->phiras == inc[lvl][I_PHIRAS]
      && tile->inventory->thystame == inc[lvl][I_THYSTAME]);
}

static void		send_to_gfx(t_list *list,
				       t_player *player,
				       bool end,
				       bool success)
{
  t_graph_client	*gfx;
  t_list_node		*tmp;

  tmp = list->list;
  while (tmp)
  {
    gfx = tmp->data;
    if (!end)
      gfx->send_player_inc(gfx, player);
    else
      gfx->send_player_end_inc(gfx, player->position, success);
    tmp = tmp->next;
  }
}

bool			response_inc_begin(t_player *player, t_server *server)
{
  t_command		*cmd;

  cmd = new_command();
  if (cmd == NULL)
    return (false);
  cmd->fill(cmd, INCANTATION, INC_TICK, response_inc_end);
  player->command_list->push(player->command_list, cmd);
  send_to_gfx(server->gfx->list, player, false, false);
  if (is_valid(server->map->get_tile_by_position
    (server->map, &player->position), player->level - 1))
    return (player->send(player, "Elevation underway\n"));
  else
    return (player->send(player, "ko\n"));
}

static bool		level_up_all(t_player *player, void *params)
{
  t_graph_client_list	*gfx;

  gfx = params;
  if (player != NULL)
    player->level_up(player, gfx);
  return (true);
}

bool			response_inc_end(t_player *player, t_server *server)
{
  t_tile		*tile;
  char			msg[128];
  bool			success;

  success = is_valid(server->map->get_tile_by_position
    (server->map, &player->position), player->level - 1);
  send_to_gfx(server->gfx->list, player, true, success);
  if (success)
  {
    tile = server->map->get_tile_by_position(server->map, &player->position);
    tile->player_list->apply(tile->player_list,
			     (t_list_action)level_up_all, server->gfx);
    snprintf(msg, 127, "Current level: %d\n", player->level);
    return (player->send(player, msg));
  }
  else
    return (player->send(player, "ko\n"));
}