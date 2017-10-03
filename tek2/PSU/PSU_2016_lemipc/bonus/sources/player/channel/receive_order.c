/*
** receive_order.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/player/channel/receive_order.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Mar 29 11:54:34 2017 Anas Buyumad
** Last update Wed Mar 29 11:54:34 2017 Anas Buyumad
*/

#include	<sys/msg.h>
#include	<errno.h>
#include	<string.h>
#include	"lem_ipc.h"

bool		receive_order(t_player *player)
{
  if (!player->alive)
    return (true);
  if (msgget(player->team_strat.channel_key, 0644) == FAILED_CALL)
    return (true);
  if (msgrcv(player->team_strat.channel, &player->team_strat.order, 128,
	     player->team_strat.team_channel,
	     IPC_NOWAIT) == FAILED_CALL)
  {
    if (errno != ENOMSG)
      return (false);
  }
  if (strcmp(player->team_strat.order.order_content, CAPTAIN_DIES) == 0)
    player->team_strat.is_captain = true;
  return (true);
}