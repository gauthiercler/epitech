/*
** broadcast.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/player/streamer/broadcast.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Mar 28 20:06:12 2017 Anas Buyumad
** Last update Tue Mar 28 20:06:12 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	"lem_ipc.h"

char		broadcast(t_ipc *data, t_player *player)
{
  display_graphic(data);
  display_arena(data->memory->arena);
  printf("Concurent players : %d\n", data->memory->concurrent_players);
  if (arena_is_empty(data->memory->arena))
  {
    display_winner(data);
    printf("The winning team is the team %d ! Congratz !\n",
	   data->memory->winning_team);
    printf("The match is over ! Thanks for Watching !\n");
    close_graphic(data);
    if (!exit_arena(data, player, false))
      return (FAILED_CALL);
    return (END_BCAST);
  }
  return (BROADCAST);
}