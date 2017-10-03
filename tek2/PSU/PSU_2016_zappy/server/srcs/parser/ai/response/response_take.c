/*
** response_take.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/parser/ai/response/response_take.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 30 17:11:02 2017 Montagne Valentin
** Last update Fri Jun 30 17:11:02 2017 Montagne Valentin
*/

#include		<stdio.h>
#include		<string.h>
#include		"parse_stream.h"

static const char 		*dico[] =
  {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame",
    NULL
  };

static bool		drop_from_player_tile(t_map *map,
						 t_player *player, t_ore ore)
{
  t_tile		*tile;

  tile = map->get_tile_by_position(map, &player->position);
  return (tile->remove_ore(tile, ore));
}

static void		send_to_gfx(t_list *list, t_server *server,
				       t_player *player)
{
  t_graph_client	*gfx;
  t_list_node		*tmp;
  t_tile		*tile;

  tmp = list->list;
  tile = server->map->get_tile_by_position(server->map, &player->position);
  while (tmp)
  {
    gfx = tmp->data;
    gfx->send_cell_content(gfx, &player->position, tile);
    gfx->send_player_inventory(gfx, player);
    tmp = tmp->next;
  }
}

bool			response_take(t_player *player, t_server *server)
{
  unsigned int		idx;
  char			*param;

  (void)server;
  param = player->command_list->first(player->command_list)->params;
  idx = 0;
  while (dico[idx])
  {
    if (strcmp(param, dico[idx]) == 0)
    {
      if (!drop_from_player_tile(server->map, player, (t_ore)idx)
	  || !player->take(player, (t_ore)idx))
	return (player->send(player, "ko\n"));
      send_to_gfx(server->gfx->list, server, player);
      return (player->send(player, "ok\n"));
    }
    idx += 1;
  }
  return (false);
}