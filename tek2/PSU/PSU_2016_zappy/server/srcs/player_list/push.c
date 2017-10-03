/*
** push.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/player_list/push.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Wed Jun 28 15:22:33 2017 Clement Nancelle
** Last update Wed Jun 28 15:22:33 2017 Clement Nancelle
*/

#include			"player.h"

bool				player_list_push(t_player_list *self, t_player *player)
{
  return (self->list->push_front(self->list, player));
}