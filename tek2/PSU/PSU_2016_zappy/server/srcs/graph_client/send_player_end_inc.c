/*
** send_player_end_inc.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_player_end_inc.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 15:29:21 2017 Montagne Valentin
** Last update Wed Jun 28 15:29:21 2017 Montagne Valentin
*/

#include		<string.h>
#include		<stdio.h>
#include		"graph_client.h"

bool			send_player_end_inc(t_graph_client *self,
						t_position pos,
						bool success)
{
  char			msg[MAXBUFFSIZE_PLAYERINCND];

  if (sprintf(msg, "pie %d %d %d\n", pos.x, pos.y, success) == -1)
    return (false);
  return (self->client->send(self->client, msg, strlen(msg), true) != -1);
}