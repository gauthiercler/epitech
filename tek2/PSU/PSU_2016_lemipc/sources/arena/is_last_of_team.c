/*
** is_last_of_team.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/arena/is_last_of_team.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Mar 28 16:56:55 2017 Anas Buyumad
** Last update Tue Mar 28 16:56:55 2017 Anas Buyumad
*/

#include	"lem_ipc.h"

bool		is_last_of_team(char *arena, t_player *player)
{
  t_pos		pos;

  pos.x = 0;
  while (pos.x < ARENA_SS)
  {
    pos.y = 0;
    while (pos.y < ARENA_SS)
    {
      if (pos.x != player->pos.x || pos.y != player->pos.y)
      {
	if (arena[CT(pos.x, pos.y)] == player->team + 48)
	{
	  return (false);
	}
      }
      pos.y += 1;
    }
    pos.x += 1;
  }
  return (true);
}