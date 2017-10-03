/*
** attack.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/player/attack.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Mar 27 17:27:51 2017 Anas Buyumad
** Last update Mon Mar 27 17:27:51 2017 Anas Buyumad
*/

#include	"lem_ipc.h"

static bool	is_potential_ally(t_pos *check_pos, t_pos *player_pos,
				     t_pos *target_pos)
{
  if (check_pos->x == target_pos->x && check_pos->y == target_pos->y)
    return (false);
  else if (check_pos->x == player_pos->x && check_pos->y == player_pos->y)
    return (false);
  return (true);
}

static bool	can_kill(char *arena, t_player *player, t_pos *target_pos)
{
  t_pos		check_pos;
  int		translated_pos;

  check_pos.x = target_pos->x - 1;
  while (check_pos.x <= target_pos->x + 1)
  {
    check_pos.y = target_pos->y - 1;
    while (check_pos.y <= target_pos->y + 1)
    {
      if (is_potential_ally(&check_pos, &player->pos, target_pos))
      {
	translated_pos = CT(check_pos.x, check_pos.y);
	if (translated_pos >= 0 && translated_pos < arena_size)
	{
	  if (arena[translated_pos] == player->team + 48)
	    return (true);
	}
      }
      check_pos.y += 1;
    }
    check_pos.x += 1;
  }
  return (false);
}

bool		attack(t_ipc *data, t_player *player, t_pos *target_pos)
{
  int		delta;

  delta = abs(player->pos.x - target_pos->x) +
	  abs(player->pos.y - target_pos->y);
  if (delta > 1)
  {
    if (delta == 2)
    {
      if ((player->pos.x == target_pos->x) || (player->pos.y == target_pos->y))
	return (false);
    }
    else
      return (false);
  }
  if (data->memory->arena[CT(target_pos->x, target_pos->y)] == TOMB_CELL ||
      data->memory->arena[CT(target_pos->x, target_pos->y)] == FREE_CELL ||
    is_wall(data->memory->arena[CT(target_pos->x, target_pos->y)]))
    return (true);
  if (can_kill(data->memory->arena, player, target_pos))
    data->memory->arena[CT(target_pos->x, target_pos->y)] = TOMB_CELL;
  return (true);
}
