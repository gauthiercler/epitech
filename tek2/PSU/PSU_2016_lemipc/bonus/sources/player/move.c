/*
** move.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/player/move.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 23 17:51:51 2017 Anas Buyumad
** Last update Thu Mar 23 17:51:51 2017 Anas Buyumad
*/

#include	"lem_ipc.h"

bool		(*move_ptr[4])(t_pos *pos, t_player *player) =
  {
    move_left,
    move_right,
    move_up,
    move_down
  };

bool		move_left(t_pos *pos, t_player *player)
{
  if ((pos->x = player->pos.x - 1) < 0)
    return (false);
  pos->y = player->pos.y;
  return (true);
}

bool		move_right(t_pos *pos, t_player *player)
{
  if ((pos->x = player->pos.x + 1) > arena_ss - 1)
    return (false);
  pos->y = player->pos.y;
  return (true);
}

bool		move_up(t_pos *pos, t_player *player)
{
  pos->x = player->pos.x;
  if ((pos->y = player->pos.y - 1) < 0)
    return (false);
  return (true);
}

bool		move_down(t_pos *pos, t_player *player)
{
  pos->x = player->pos.x;
  if ((pos->y = player->pos.y + 1) > arena_ss - 1)
    return (false);
  return (true);
}

bool		move(char *arena, t_player *player, t_dir direction)
{
  t_pos		pos;

  if (!move_ptr[direction](&pos, player))
    return (false);
  if (arena[CT(pos.x, pos.y)] == FREE_CELL)
  {
    arena[CT(pos.x, pos.y)] = player->team + 48;
    arena[CT(player->pos.x, player->pos.y)] = FREE_CELL;
    player->pos.x = pos.x;
    player->pos.y = pos.y;
    return (true);
  }
  return (false);
}
