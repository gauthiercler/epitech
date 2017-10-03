/*
** destroy.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/player_list/destroy.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 14:06:19 2017 Montagne Valentin
** Last update Mon Jun 26 14:06:19 2017 Montagne Valentin
*/

#include		<stdlib.h>
#include		"player.h"

void			player_list_destroy(t_player_list *self)
{
  if (self->list != NULL)
    self->list->destroy(self->list);
  free(self);
}