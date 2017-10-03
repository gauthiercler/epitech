/*
** init_player.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/player/init_player.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Mar 22 14:02:01 2017 Gauthier Cler
** Last update Wed Mar 22 14:02:01 2017 Gauthier Cler
*/

#include	"lem_ipc.h"

static bool	init_map(t_player *player)
{
  int		iterator;

  player->arena_map = malloc(sizeof(char *) * (ARENA_SS + 1));
  if (!player->arena_map)
    return (display_error("malloc"));
  iterator = 0;
  while (iterator < ARENA_SS)
  {
    player->arena_map[iterator] = malloc(sizeof(char) * (ARENA_SS + 1));
    if (!player->arena_map[iterator])
      return (display_error("malloc"));
    iterator += 1;
  }
  return (true);
}

bool		init_player(t_player *player, int team)
{
  player->pos.x = UNDEFINED;
  player->pos.y = UNDEFINED;
  player->alive = true;
  player->team = team;
  player->team_strat.team_channel = 1 + player->team;
  player->team_strat.order.order_content[0] = '\0';
  player->streamer = false;
  player->team_strat.is_captain = false;
  player->team_strat.target.x = ARENA_SS / 2;
  player->team_strat.target.y = ARENA_SS / 2;
  if (!init_map(player))
    return (false);
  return (true);
}