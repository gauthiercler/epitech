/*
** emit_order.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/player/channel/emit_order.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Mar 29 11:54:17 2017 Anas Buyumad
** Last update Wed Mar 29 11:54:17 2017 Anas Buyumad
*/

#include	<sys/msg.h>
#include	<string.h>
#include	<errno.h>
#include	"lem_ipc.h"

bool		emit_order(t_player *player, char *message)
{
  if (msgget(player->team_strat.channel_key, 0644) == FAILED_CALL)
    return (true);
  player->team_strat.order.order_type = player->team_strat.team_channel;
  strcpy(player->team_strat.order.order_content, message);
  if (msgsnd(player->team_strat.channel, &player->team_strat.order,
	 strlen(player->team_strat.order.order_content) + 1,
	     IPC_NOWAIT)== FAILED_CALL)
  {
    if (errno != EAGAIN)
      return (false);
  }
  return (true);
}