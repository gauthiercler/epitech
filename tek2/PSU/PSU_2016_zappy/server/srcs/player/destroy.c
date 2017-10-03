/*
** destroy.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/player/destroy.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 14:22:58 2017 Montagne Valentin
** Last update Mon Jun 26 14:22:58 2017 Montagne Valentin
*/

#include	<stdlib.h>
#include	"player.h"

void		player_delete(t_player *self)
{
  if (self->inventory != NULL)
    self->inventory->destroy(self->inventory);
  if (self->input_buffer != NULL)
    self->input_buffer->destroy(self->input_buffer);
  if (self->output_buffer != NULL)
    self->output_buffer->destroy(self->output_buffer);
  if (self->socket != NULL)
    self->socket->destroy(self->socket);
  if (self->command_list != NULL)
  {
    self->command_list->empty(self->command_list);
    self->command_list->destroy(self->command_list);
  }
  free(self);
}
