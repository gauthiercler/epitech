/*
** response_connect_number.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/parser/ai/response/response_connect_number.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Fri Jun 30 18:37:40 2017 Clement Nancelle
** Last update Fri Jun 30 18:37:40 2017 Clement Nancelle
*/

#include			<memory.h>
#include			<stdio.h>
#include			"parse_stream.h"

bool				response_connect_nbr(t_player *player,
							 t_server *server)
{
  t_team			*tmp;
  char				buffer[MAXBUFFSIZE_EGGOPEN];

  memset(buffer, 0, MAXBUFFSIZE_EGGOPEN);
  tmp = server->teams->get_team(server->teams, player->team->name);
  sprintf(buffer, "%u\n", tmp->slots);
  return (player->send(player, buffer));
}