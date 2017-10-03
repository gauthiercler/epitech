/*
** size.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/player_list/size.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 14:04:44 2017 Montagne Valentin
** Last update Mon Jun 26 14:04:44 2017 Montagne Valentin
*/

#include		<stddef.h>
#include		"player.h"

size_t			player_list_size(t_player_list *self)
{
  return (self->list->size(self->list));
}