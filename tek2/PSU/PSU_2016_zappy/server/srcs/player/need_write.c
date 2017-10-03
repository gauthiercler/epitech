/*
** need_write.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/player/need_write.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 23:33:55 2017 Antoine FORET
** Last update Wed Jun 28 23:33:55 2017 Antoine FORET
*/

#include	"player.h"

bool		player_need_write(t_player *self)
{
  return (self->output_buffer->get_remaining_read(self->output_buffer) != 0);
}