/*
** clean_ipc.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/ipc/clean_ipc.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Mar 22 14:52:24 2017 Gauthier Cler
** Last update Wed Mar 22 14:52:24 2017 Gauthier Cler
*/

#include	<sys/msg.h>
#include	<sys/shm.h>
#include	<errno.h>
#include	"lem_ipc.h"

bool		close_channel(t_player *player)
{
  if (msgget(player->team_strat.channel_key, 0644) == FAILED_CALL)
    return (true);
  if (msgctl(player->team_strat.channel, IPC_RMID, NULL) == FAILED_CALL)
  {
    if (errno != EIDRM)
      return (false);
  }
  return (true);
}

bool		close_semaphore(t_player *player)
{
  if (sem_close(player->arena_handler) == FAILED_CALL)
    return (display_error("sem_close"));
  return (true);
}

bool		clean_ipc(t_ipc *ipc, t_player *player)
{
  sem_post(player->arena_handler);
  if (!close_semaphore(player))
    return (false);
  if (!close_channel(player))
    return (false);
  if (sem_unlink(MAP_SEM_ID) == FAILED_CALL)
    return (display_error("sem_unlink"));
  if (shmdt(ipc->memory) == FAILED_CALL)
    return (display_error("shmdt"));
  if (shmctl(ipc->shmid, IPC_RMID, NULL) == FAILED_CALL)
    return (display_error("shmctl"));
  return (true);
}