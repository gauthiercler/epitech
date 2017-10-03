/*
** is_winner.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/arena/is_winner.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 23 15:33:12 2017 Anas Buyumad
** Last update Thu Mar 23 15:33:12 2017 Anas Buyumad
*/

#include	"lem_ipc.h"

bool		is_winner(char *arena, t_player *player)
{
  t_pos		pos;

  if ((player->streamer && !player->alive) || !player->alive)
    return (false);
  pos.x = 0;
  while (pos.x < arena_ss)
  {
    pos.y = 0;
    while (pos.y < arena_ss)
    {
      if (pos.x != player->pos.x || pos.y != player->pos.y)
      {
	if ((arena[CT(pos.x, pos.y)] != FREE_CELL) &&
	  (arena[CT(pos.x, pos.y)] != player->team + 48) &&
	  !(is_wall(arena[CT(pos.x, pos.y)])))
	  return (false);
      }
      pos.y += 1;
    }
    pos.x += 1;
  }
  return (true);
}