/*
** empty.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/player_list/empty.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 29 09:48:22 2017 Montagne Valentin
** Last update Thu Jun 29 09:48:22 2017 Montagne Valentin
*/

#include		"player.h"

static bool		free_player(t_player *player)
{
  if (player != NULL)
    player->destroy(player);
  return (true);
}

void			player_list_empty(t_player_list *self)
{
  self->apply(self, (t_list_action)(free_player), NULL);
}