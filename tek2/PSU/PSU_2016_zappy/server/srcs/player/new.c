/*
** new.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/player/new.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 14:10:33 2017 Montagne Valentin
** Last update Mon Jun 26 14:10:33 2017 Montagne Valentin
*/

#include	<stdlib.h>
#include	"player.h"
#include	"config.h"

static void	init_player_methods(t_player *self)
{
  self->tick = player_tick;
  self->take = player_take;
  self->turn = player_turn;
  self->drop = player_drop;
  self->move = player_move;
  self->get_cardinal = player_get_cardinal;
  self->level_up = player_level_up;
  self->need_write = player_need_write;
  self->send = player_send;
  self->send_network = player_send_network;
  self->disconnect = player_disconnect;
  self->destroy = player_delete;
}

static bool	init_player(t_player *self, t_team *team,
			       unsigned int id, t_position *pos)
{
  self->id = id;
  self->team = team;
  self->position.x = ((pos == NULL) ? 0 : pos->x);
  self->position.y = ((pos == NULL) ? 0 : pos->y);
  self->direction = 0;
  self->level = MIN_LVL;
  self->hungry = 0;
  self->command_list = new_command_list();
  self->tick_stack = 0;
  self->inventory = new_inventory();
  self->inventory->food += 10;
  self->dead = false;
  self->change = false;
  self->input_buffer = new_circular_buffer(PLAYER_BUFFER_SIZE);
  self->output_buffer = new_circular_buffer(PLAYER_BUFFER_SIZE);
  return (self->command_list != NULL &&
	  self->inventory != NULL &&
	  self->input_buffer != NULL &&
	  self->output_buffer != NULL);
}

t_player	*new_player(t_team *team, unsigned int id,
			    t_position *pos, t_client *socket)
{
  t_player	*self;

  self = malloc(sizeof(t_player));
  if (self == NULL)
    return (NULL);
  init_player_methods(self);
  self->socket = socket;
  if (!init_player(self, team, id, pos))
  {
    self->destroy(self);
    return (NULL);
  }
  return (self);
}
