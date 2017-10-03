/*
** new.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/new.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 16:16:56 2017 Montagne Valentin
** Last update Wed Jun 28 16:16:56 2017 Montagne Valentin
*/

#include		<stdlib.h>
#include		"graph_client.h"

static void		init_methods(t_graph_client *self)
{
  self->send_map_size = send_map_size;
  self->send_cell_content = send_cell_content;
  self->send_player_spawn = send_player_spawn;
  self->send_player_position = send_player_position;
  self->send_player_lvl = send_player_lvl;
  self->send_player_inventory = send_player_inventory;
  self->send_player_end = send_player_end;
  self->send_player_broadcast = send_player_broadcast;
  self->send_player_inc = send_player_inc;
  self->send_player_end_inc = send_player_end_inc;
  self->send_player_death = send_player_death;
  self->send_egg_spawn = send_egg_spawn;
  self->send_egg_open = send_egg_open;
  self->send_time = send_time;
  self->send_end_game = send_end_game;
  self->send_msg = send_msg;
  self->send_unknown = send_unknown;
  self->send= graph_client_send;
  self->send_network = graph_client_send_network;
  self->need_write = graph_client_need_write;
  self->send_map = send_map;
  self->send_players_spawn = send_players_spawn;
  self->send_eggs_spawn = send_eggs_spawn;
  self->destroy = graph_client_destroy;
}

static bool		init(t_graph_client *self, t_client *client)
{
  self->client = client;
  self->input_buffer = new_circular_buffer(PLAYER_BUFFER_SIZE);
  self->output_buffer = new_circular_buffer(PLAYER_BUFFER_SIZE);
  return (self->input_buffer != NULL &&
	  self->output_buffer != NULL);
}

t_graph_client 		*new_graphical_transmitter(t_client *client)
{
  t_graph_client 	*self;

  self = malloc(sizeof(t_graph_client));
  if (self == NULL)
    return (NULL);
  init_methods(self);
  if (!init(self, client))
  {
    self->destroy(self);
    return (NULL);
  }
  return (self);
}
