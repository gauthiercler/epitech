/*
** insert_player.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/player/insert_player.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Mar 22 15:40:02 2017 Anas Buyumad
** Last update Wed Mar 22 15:40:02 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	"lem_ipc.h"

bool		insert_player_in_arena(char *arena, t_player *player)
{
  if (get_free_spot(arena, &player->pos))
  {
    arena[CT(player->pos.x, player->pos.y)] = player->team + 48;
    printf("The crowd roars as a new fighter enters the arena !\n");
    return (true);
  }
  return (false);
}