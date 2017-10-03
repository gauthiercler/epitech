/*
** init_ipc.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/init/init_ipc.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Mar 22 13:54:04 2017 Gauthier Cler
** Last update Wed Mar 22 13:54:04 2017 Gauthier Cler
*/

#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/msg.h>
#include	<sys/shm.h>
#include	<fcntl.h>
#include	<errno.h>
#include	"lem_ipc.h"

static bool	broadcast_captains(t_player *player)
{
  t_player	mock_player;
  int		i;

  i = 0;
  mock_player.team_strat.channel_key = player->team_strat.channel_key;
  mock_player.team_strat.channel = player->team_strat.channel;
  while (i < 10)
  {
    mock_player.team = i;
    mock_player.team_strat.team_channel = 1 + mock_player.team;
    if (!emit_order(&mock_player, CAPTAIN_DIES))
      return (false);
    i += 1;
  }
  return (true);
}

static bool	init_channel(t_player *player)
{
  player->team_strat.channel =
    msgget(player->team_strat.channel_key, IPC_CREAT | IPC_EXCL | 0644);
  if (player->team_strat.channel != FAILED_CALL)
  {
    if (!broadcast_captains(player))
      return (false);
  }
  else if (player->team_strat.channel == FAILED_CALL && errno == EEXIST)
  {
    player->team_strat.channel =
      msgget(player->team_strat.channel_key, IPC_CREAT | 0644);
    if (player->team_strat.channel == FAILED_CALL)
      return (false);
  }
  else
    return (false);
  return (true);
}

static bool	init_semaphore(t_player *player)
{
  player->arena_handler = sem_open(MAP_SEM_ID, O_CREAT | O_EXCL,
				   S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, 1);
  if (player->arena_handler == SEM_FAILED && errno == EEXIST)
  {
    player->arena_handler = sem_open(MAP_SEM_ID, O_CREAT,
				     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, 1);
    if (player->arena_handler == SEM_FAILED)
      return (false);
  }
  else if (player->arena_handler == SEM_FAILED)
    return (false);
  return (true);
}

static bool	init_memory(t_ipc *data, t_player *player)
{
  data->shmid = shmget(data->key, sizeof(t_memory),
		       IPC_CREAT | IPC_EXCL | 0644);
  if (data->shmid != FAILED_CALL)
    player->streamer = true;
  else if (data->shmid == FAILED_CALL && errno == EEXIST)
  {
    data->shmid = shmget(data->key, sizeof(t_memory), IPC_CREAT | 0644);
    if (data->shmid == FAILED_CALL)
      return (false);
  }
 else
    return (false);
  return (true);
}

bool		init_ipc(t_ipc *data, char *key, t_player *player)
{
  data->key = ftok(key, '$');
  if (data->key == FAILED_CALL)
    return (display_error("ftok"));
  player->team_strat.channel_key = ftok(key, '*');
  if (player->team_strat.channel_key == FAILED_CALL)
    return (display_error("ftok"));
  if (!init_memory(data, player))
    return (display_error("shmget"));
  data->memory = (t_memory *)shmat(data->shmid, (void *)0, 0);
  if (data->memory == (t_memory *)FAILED_CALL)
    return (display_error("shmat"));
  if (!init_semaphore(player))
    return (display_error("sem_open"));
  if (!init_channel(player))
    return (display_error("msgget"));
  return (true);
}