/*
** send.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/player/send.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 10:45:02 2017 Antoine FORET
** Last update Thu Jun 29 10:45:02 2017 Antoine FORET
*/

#include	<stdio.h>
#include	<string.h>
#include	"player.h"

bool		player_send(t_player *self, const char *message)
{
  size_t	message_length;

  message_length = strlen(message);
  if (message_length > self->output_buffer->get_remaining_space(
    self->output_buffer))
  {
    fprintf(stderr, "[WARNING] Too long response skipped.\n");
    return (false);
  }
  self->output_buffer->write(self->output_buffer, message, message_length);
  return (true);
}