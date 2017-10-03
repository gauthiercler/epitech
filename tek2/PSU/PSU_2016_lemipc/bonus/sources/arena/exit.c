/*
** exit.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/arena/exit.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Mar 28 20:07:23 2017 Anas Buyumad
** Last update Tue Mar 28 20:07:23 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	"lem_ipc.h"

bool		exit_arena(t_ipc *data, t_player *player, bool won)
{
  if (won)
    data->memory->arena[CT(player->pos.x, player->pos.y)] = FREE_CELL;
  if (won && is_last_of_team(data->memory->arena, player))
  {
    data->memory->winning_team = player->team;
    data->memory->concurrent_players -= 1;
    if (player->streamer)
    {
      display_graphic(data);
      display_arena(data->memory->arena);
      display_winner(data);
      printf("The winning team is the team %d ! Congratz !\n",
	     data->memory->winning_team);
      printf("The match is over ! Thanks for Watching !\n");
    }
    sem_post(player->arena_handler);
    return (clean_ipc(data, player));
  }
  data->memory->concurrent_players -= 1;
  if (won)
    sem_post(player->arena_handler);
  return (close_semaphore(player));
}