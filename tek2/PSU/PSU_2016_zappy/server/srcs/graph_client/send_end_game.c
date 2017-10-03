/*
** send_end_game.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_end_game.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 16:06:33 2017 Montagne Valentin
** Last update Wed Jun 28 16:06:33 2017 Montagne Valentin
*/

#include		<string.h>
#include		<stdio.h>
#include		"graph_client.h"

bool			send_end_game(t_graph_client *self,
					  char *team_name)
{
  char			msg[MAXBUFFSIZE_ENDOFGAME + strlen(team_name)];

  if (sprintf(msg, "seg %s", team_name) == -1)
    return (false);
  return (self->client->send(self->client, msg, strlen(msg), true) != -1);
}