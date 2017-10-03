/*
** response_unknown.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/parser/ai/response/response_unknown.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat Jul 01 12:49:32 2017 Montagne Valentin
** Last update Sat Jul 01 12:49:32 2017 Montagne Valentin
*/

#include		"parse_stream.h"

bool			response_unknown(t_player *player, t_server *server)
{
  (void)server;
  return (player->send(player, "ko\n"));
}