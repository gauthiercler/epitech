/*
** send_player_inventory.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_player_inventory.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 13:44:52 2017 Montagne Valentin
** Last update Wed Jun 28 13:44:52 2017 Montagne Valentin
*/

#include		<string.h>
#include		<stdio.h>
#include		"graph_client.h"

bool			send_player_inventory(t_graph_client *self,
						  t_player *player)
{
  char			msg[MAXBUFFSIZE_PLAYERINV];

  if (sprintf(msg, "pin %d %d %d %d %d %d %d %d\n",
	      player->id, player->inventory->food,
	      player->inventory->linemate, player->inventory->deraumere,
	      player->inventory->sibur, player->inventory->mendiane,
	      player->inventory->phiras, player->inventory->thystame)
      == -1)
    return (false);
  return (self->client->send(self->client, msg, strlen(msg), true) != -1);
}