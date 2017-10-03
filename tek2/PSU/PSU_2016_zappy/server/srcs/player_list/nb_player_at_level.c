/*
** nb_player_at_level.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/player_list/nb_player_at_level.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Wed Jun 28 14:14:46 2017 Clement Nancelle
** Last update Wed Jun 28 14:14:46 2017 Clement Nancelle
*/

#include		"player.h"

size_t			player_list_nb_at_level(t_player_list *self, unsigned int lev)
{
  size_t		size;
  t_player		*tmp_player;
  t_list_node		*tmp;

  size = 0;
  tmp = self->list->list;
  tmp_player = tmp->data;
  while (tmp != NULL)
  {
    if (tmp_player->level == lev)
      size += 1;
    tmp = tmp->next;
  }
  return (size);
}