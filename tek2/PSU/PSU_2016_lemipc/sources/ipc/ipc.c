/*
** ipc.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/ipc/ipc.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Mar 22 14:42:28 2017 Gauthier Cler
** Last update Wed Mar 22 14:42:28 2017 Gauthier Cler
*/

#include	"lem_ipc.h"
#include 	<stdio.h>

static void	clean_map(char *arena, t_player *player, const char character)
{
  size_t	iterator;

  iterator = 0;
  sem_wait(player->arena_handler);
  while (iterator < ARENA_SIZE)
  {
    arena[iterator] = character;
    iterator += 1;
  }
  sem_post(player->arena_handler);
}

bool		lem_ipc(char *path_to_key, char *team)
{
  t_ipc		data;
  t_player	player;

  init_random();
  if (!init_player(&player, atoi(team)))
    return (false);
  if (!init_ipc(&data, path_to_key, &player))
    return (false);
  if (player.streamer)
    clean_map(data.memory->arena, &player, FREE_CELL);
  if (player.streamer)
  {
    data.memory->concurrent_players = 0;
    printf("Welcome to the colosseum, enjoy the battle !\n");
  }
  run_simulation(&data, &player);
  clean_cached_map(&player);
  return (true);
}
