/*
** command.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/player/captain/command.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 30 18:17:47 2017 Anas Buyumad
** Last update Thu Mar 30 18:17:47 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	<solver.h>

bool		command(t_ipc *data, t_player *player)
{
  char		order_string[128];

  determine_target(data->memory->arena, player);
  sprintf(order_string, "%d:%d", player->team_strat.target.x,
	  player->team_strat.target.y);
  if (!emit_order(player, order_string))
    return (false);
  return (true);
}