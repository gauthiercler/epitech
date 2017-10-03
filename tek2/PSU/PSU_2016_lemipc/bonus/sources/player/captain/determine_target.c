/*
** determine_target.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/player/captain/determine_target.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Mar 29 14:15:31 2017 Anas Buyumad
** Last update Wed Mar 29 14:15:31 2017 Anas Buyumad
*/

#include	"lem_ipc.h"

static bool	find_target(char *arena, t_player *player,
			       t_pos *check_pos, t_pos *first_match)
{
  char		cell;

  if ((check_pos->x >= 0 && check_pos->x < arena_ss) &&
      (check_pos->y >= 0 && check_pos->y < arena_ss))
  {
    cell = arena[CT(check_pos->x, check_pos->y)];
    if (cell != FREE_CELL && cell != TOMB_CELL && !is_wall(cell)
	&& cell != player->team + 48)
    {
      player->team_strat.target.x = check_pos->x;
      player->team_strat.target.y = check_pos->y;
      if (first_match->x == UNDEFINED && first_match->y == UNDEFINED)
      {
	first_match->x = check_pos->x;
	first_match->y = check_pos->y;
      }
      if (check_prox_allies(arena, player, 3))
	return (true);
    }
  }
  return (false);
}

static void	reset_pos(t_player *player, t_pos *first_match)
{
  if (first_match->x == UNDEFINED)
    first_match->x = arena_ss / 2;
  if (first_match->y == UNDEFINED)
    first_match->y = arena_ss / 2;
  player->team_strat.target.x = first_match->x;
  player->team_strat.target.y = first_match->y;
}

void		determine_target(char *arena, t_player *player)
{
  t_pos		check_pos;
  t_pos		first_matching;
  int		offset;

  first_matching.x = UNDEFINED;
  first_matching.y = UNDEFINED;
  offset = 1;
  while (offset < arena_ss)
  {
    check_pos.y = player->pos.y - offset;
    while (check_pos.y <= player->pos.y + offset)
    {
      check_pos.x = player->pos.x - offset;
      while (check_pos.x <= player->pos.x + offset)
      {
	if (find_target(arena, player, &check_pos, &first_matching))
	  return ;
	check_pos.x += 1;
      }
      check_pos.y += 1;
    }
    offset += 1;
  }
  reset_pos(player, &first_matching);
}