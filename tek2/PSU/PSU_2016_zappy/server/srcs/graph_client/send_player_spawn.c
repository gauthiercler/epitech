/*
** send_player_spawn.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_player_spawn.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 11:41:00 2017 Montagne Valentin
** Last update Wed Jun 28 11:41:00 2017 Montagne Valentin
*/

#include		<stdio.h>
#include		<string.h>
#include		"graph_client.h"

bool			send_player_spawn(t_graph_client *self,
					      t_player *player)
{
  char			msg[MAXBUFFSIZE_PLAYERSPAWN];

  if (snprintf(msg, MAXBUFFSIZE_PLAYERSPAWN,
	       "pnw %d %d %d %d %d %s\n", player->id,
	      player->position.x, player->position.y, player->direction,
	      player->level, player->team->get_name(player->team)) == -1)
    return (false);
  return (self->send(self, msg));
}

static bool		send_player(t_player *player, t_graph_client *client)
{
  return (client->send_player_spawn(client, player));
}

bool			send_players_spawn(t_graph_client *self,
					       t_player_list *players)
{
  return (players->apply(players, (t_list_action)(send_player), self));
}