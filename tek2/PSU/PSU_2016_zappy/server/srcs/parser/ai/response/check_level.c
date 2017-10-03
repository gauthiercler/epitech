/*
** check_level.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/parser/ai/response/check_level.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Sun Jul 02 05:22:51 2017 Clement Nancelle
** Last update Sun Jul 02 05:22:51 2017 Clement Nancelle
*/

#include	"parse_stream.h"

bool		check_level(t_player *player, unsigned int *data)
{
  if (player->level == (*data + 1))
    return (true);
  return (false);
}