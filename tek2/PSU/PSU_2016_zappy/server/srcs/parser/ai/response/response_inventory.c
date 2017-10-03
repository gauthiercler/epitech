/*
** response_inventory.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/parser/ai/response/response_inventory.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Fri Jun 30 15:57:02 2017 Clement Nancelle
** Last update Fri Jun 30 15:57:03 2017 Clement Nancelle
*/

#include		<stdio.h>
#include		<memory.h>
#include		"parse_stream.h"

bool			response_inventory(t_player *player, t_server *server)
{
  char			info[170];

  (void)server;
  if (sprintf(info, "[ food %d,"
    " linemate %d,"
    " deraumere %d,"
    " sibur %d,"
    " mendiane %d,"
    " phiras %d,"
    " thystame %d ]\n",
	  player->inventory->food,
	  player->inventory->linemate,
	  player->inventory->deraumere,
	  player->inventory->sibur,
	  player->inventory->mendiane,
	  player->inventory->phiras,
	  player->inventory->thystame) < 0)
    return (false);
  return (player->send(player, info));
}