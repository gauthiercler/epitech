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

static void	clean_map(char *arena, const char character)
{
  int		iterator;

  iterator = 0;
  while (iterator < arena_size)
  {
    arena[iterator] = character;
    iterator += 1;
  }
}

void		fill_line(char *arena, char *line, int y_idx)
{
  int		x_idx;

  x_idx = 0;
  while (x_idx < arena_ss)
  {
    arena[CT(x_idx, y_idx)] = line[x_idx];
    x_idx += 1;
  }
}

void		fill_map(char *arena, char *file)
{
  FILE		*fp;
  char		*line;
  size_t	length;
  int		i;

  i = 0;
  if (!(fp = fopen(file, "r")))
    return ;
  line = NULL;
  length = 0;
  while (getline(&line, &length, fp) != -1)
  {
    printf("%s", line);
    fill_line(arena, line, i);
    i += 1;
  }
  fclose(fp);
}

bool		lem_ipc_with_map(char *path_to_key, char *team, char *file)
{
  t_ipc		data;
  t_player	player;

  init_random();
  init_player(&player, atoi(team));
  if (!init_ipc(&data, path_to_key, &player))
    return (false);
  if (!init_map(&player))
    return (false);
  if (player.streamer)
  {
    sem_wait(player.arena_handler);
    clean_map(data.memory->arena, FREE_CELL);
    fill_map(data.memory->arena, file);
    sem_post(player.arena_handler);
  }
  if (player.streamer)
  {
    data.memory->concurrent_players = 0;
    printf("Welcome to the colosseum, enjoy the battle !\n");
  }
  run_simulation(&data, &player);
  clean_cached_map(&player);
  return (true);
}

bool		lem_ipc(char *path_to_key, char *team)
{
  t_ipc		data;
  t_player	player;

  init_random();
  init_player(&player, atoi(team));
  if (!init_ipc(&data, path_to_key, &player))
    return (false);
  if (!init_map(&player))
    return (false);
  if (player.streamer)
  {
    sem_wait(player.arena_handler);
    clean_map(data.memory->arena, FREE_CELL);
    sem_post(player.arena_handler);
  }
  if (player.streamer)
  {
    data.memory->concurrent_players = 0;
    printf("Welcome to the colosseum, enjoy the battle !\n");
  }
  run_simulation(&data, &player);
  clean_cached_map(&player);
  return (true);
}
