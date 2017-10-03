/*
** follow_command.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/player/follow_command.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 30 18:20:50 2017 Anas Buyumad
** Last update Thu Mar 30 18:20:51 2017 Anas Buyumad
*/

#include	<string.h>
#include	"lem_ipc.h"

static bool	is_ally(char *arena, t_pos *check_pos, t_player *player)
{
  char		cell;

  if ((check_pos->x >= 0 && check_pos->x < arena_ss) &&
      (check_pos->y >= 0 && check_pos->y < arena_ss))
  {
    if (check_pos->x != player->pos.x && check_pos->y != player->pos.y)
    {
      cell = arena[CT(check_pos->x, check_pos->y)];
      if (cell == player->team + 48)
	return (true);
    }
  }
  return (false);
}

bool		check_prox_allies(char *arena, t_player *player, int range)
{
  t_pos		check_pos;
  int		offset;

  offset = 1;
  while (offset < range)
  {
    check_pos.y = player->pos.y - offset;
    while (check_pos.y <= player->pos.y + offset)
    {
      check_pos.x = player->pos.x - offset;
      while (check_pos.x <= player->pos.x + offset)
      {
	if (is_ally(arena, &check_pos, player))
	  return (true);
	check_pos.x += 1;
      }
      check_pos.y += 1;
    }
    offset += 1;
  }
  return (false);
}

static bool	check_worth(t_ipc *data, t_player * player)
{
  t_pos		initial_pos;
  int		delta_order;
  int		delta_self;

  initial_pos.x = player->team_strat.target.x;
  initial_pos.y = player->team_strat.target.y;
  determine_target(data->memory->arena, player);
  delta_order = abs(player->pos.x - initial_pos.x)
		+ abs(player->pos.y - initial_pos.y);
  delta_self = abs(player->pos.x - player->team_strat.target.x)
	       + abs(player->pos.y - player->team_strat.target.y);
  if (((delta_order - arena_ss / 2) < delta_self) ||
      !check_prox_allies(data->memory->arena, player, 1))
  {
    player->team_strat.target.x = initial_pos.x;
    player->team_strat.target.y = initial_pos.y;
  }
  return (true);
}

bool		follow_command(t_ipc *data, t_player *player)
{
  char		*y_pos;

  if (strlen(player->team_strat.order.order_content) > 0)
  {
    player->team_strat.target.x = atoi(player->team_strat.order.order_content);
    y_pos = index(player->team_strat.order.order_content, ':');
    if (y_pos != NULL && y_pos + 1 != '\0')
      player->team_strat.target.y = atoi(y_pos + 1);
  }
  if (!emit_order(player, player->team_strat.order.order_content))
    return (false);
  if (!check_worth(data, player))
    return (false);
  return (true);
}
