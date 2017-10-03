/*
** pop.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/player_list/pop.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Wed Jun 28 15:25:31 2017 Clement Nancelle
** Last update Wed Jun 28 15:25:31 2017 Clement Nancelle
*/

#include			"player.h"

bool				player_list_pop(t_player_list *self, t_player *player)
{
  return (self->list->pop_data(self->list, player));
}