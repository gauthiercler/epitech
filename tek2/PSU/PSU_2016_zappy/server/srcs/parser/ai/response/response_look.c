/*
** response_look.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/parser/ai/response/response_look.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 30 14:11:21 2017 Montagne Valentin
** Last update Fri Jun 30 14:11:21 2017 Montagne Valentin
*/

#include			<string.h>
#include			<stdio.h>
#include 			<string_extended.h>
#include			"parse_stream.h"

static const t_position		dir[] =
  {
    { 0, 1 },
    { -1, 0 },
    { 0, -1 },
    { 1, 0 }
  };

static const t_position		to_read[] =
  {
    { 1, 0 },
    { 0, -1 },
    { -1, 0 },
    { 1, 0 }
  };

static unsigned int	get_nb_cell(unsigned int level)
{
  unsigned int		cell;
  unsigned int		i;

  cell = 0;
  i = 0;
  while (i < level + 1)
  {
    cell += i * 2 + 1;
    i += 1;
  }
  return (cell);
}

static unsigned int	fill_cells(t_map *map,
				      t_player *player,
				      char **cells,
				      unsigned int range)
{
  t_tile		*tile;
  t_position		begin;
  unsigned int		idx;

  idx = 0;
  begin.x = (player->position.x + dir[player->direction].x * range)
	    + -to_read[player->direction].x * range;
  begin.y = (player->position.y + dir[player->direction].y * range)
	    + -to_read[player->direction].y * range;
  while (idx < range * 2 + 1)
  {
    tile = map->get_tile_by_position(map, &begin);
    cells[idx] = tile->to_str(tile);
    begin.x += to_read[player->direction].x;
    begin.y += to_read[player->direction].y;
    idx += 1;
  }
  return (idx);
}

static char		**get_look(t_player *player,
				      t_map *map,
				      unsigned int nb_cell)
{
  char			**cells;
  unsigned int		dec;
  unsigned int		idx;

  cells = malloc(sizeof(char *) * (nb_cell + 1));
  if (cells == NULL)
    return (NULL);
  dec = fill_cells(map, player, cells, 0);
  idx = 1;
  while (idx <= player->level)
  {
    dec += fill_cells(map, player, cells + dec, idx);
    idx += 1;
  }
  cells[nb_cell] = NULL;
  return (cells);
}

bool			response_look(t_player *player, t_server *server)
{
  char			**cells;
  unsigned int		nb_cell;
  char			*msg;
  bool			ret;

  nb_cell = get_nb_cell(player->level);
  cells = get_look(player, server->map, nb_cell);
  if (cells == NULL)
    return (false);
  msg = tab_to_str(cells);
  ret = false;
  if (msg != NULL)
  {
    ret = player->send(player, msg);
    free(msg);
  }
  free_explode(cells);
  return (ret);
}