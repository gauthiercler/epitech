/*
** is_alive.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/player/is_alive.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 23 16:58:06 2017 Anas Buyumad
** Last update Thu Mar 23 16:58:06 2017 Anas Buyumad
*/

#include	"lem_ipc.h"

static void	transfer_order(t_player *player)
{
  if (!emit_order(player, player->team_strat.order.order_content))
    exit(EXIT_FAILURE);
}

static void	captain_died(t_player *player)
{
  if (!emit_order(player, CAPTAIN_DIES))
    exit(EXIT_FAILURE);
}

bool		is_alive(char *arena, t_player *player)
{
  if (player->alive == false)
    return (false);
  if (player->pos.x == UNDEFINED && player->pos.y == UNDEFINED)
    return (true);
  if (arena[CT(player->pos.x, player->pos.y)] == TOMB_CELL)
  {
    player->alive = false;
    arena[CT(player->pos.x, player->pos.y)] = FREE_CELL;
    if (player->team_strat.is_captain)
      captain_died(player);
    else
      transfer_order(player);
    return (false);
  }
  return (true);
}