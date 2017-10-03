/*
** simulation.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/player/simulation.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Mar 22 14:21:40 2017 Gauthier Cler
** Last update Wed Mar 22 14:21:40 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	"lem_ipc.h"

static bool	fight(t_ipc *data, t_player *player)
{
  if (!player->alive)
    return (true);
  if (player->team_strat.is_captain)
  {
    if (!command(data, player))
      return (false);
  }
  else
  {
    if (!follow_command(data, player))
      return (false);
  }
  target(data, player, &player->team_strat.target);
  return (true);
}

static void	start_turn(t_ipc *data, t_player *player, bool warmup)
{
  sem_wait(player->arena_handler);
  if (player->streamer && warmup)
    startup_match();
  if (player->pos.x == UNDEFINED || player->pos.y == UNDEFINED)
  {
    if (data->memory->concurrent_players > MAX_PLAYERS ||
      data->memory->concurrent_players >= ARENA_SIZE)
    {
      sem_post(player->arena_handler);
      close_semaphore(player);
      exit(0);
    }
    if (insert_player_in_arena(data->memory->arena, player))
      data->memory->concurrent_players += 1;
  }
}

static void	end_turn(t_player *player)
{
  if (player->streamer)
    usleep(ROUND_DELAY);
  sem_post(player->arena_handler);
  usleep(100);
}

bool		break_exit(t_ipc *data, t_player *player)
{
  end_turn(player);
  return (exit_arena(data, player, false));
}

bool		run_simulation(t_ipc *data, t_player *player)
{
  bool		warmup;
  char		broadcasting;

  warmup = true;
  while (player->alive || player->streamer)
  {
    start_turn(data, player, warmup);
    if (player->pos.x != UNDEFINED && player->pos.y != UNDEFINED)
    {
      if (!receive_order(player))
	return (false);
      if (!is_alive(data->memory->arena, player) && !player->streamer)
	return (break_exit(data, player));
      if (!fight(data, player))
	return (false);
      if (player->streamer)
	if ((broadcasting = broadcast(data, player)) != BROADCAST)
	  return (broadcasting != FAILED_CALL);
      if (!warmup && is_winner(data->memory->arena, player))
	return (exit_arena(data, player, true));
      ((warmup) ? warmup = false : 0);
    }
    end_turn(player);
  }
  return (exit_arena(data, player, false));
}