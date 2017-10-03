/*
** new.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/server/new.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 16:31:44 2017 Montagne Valentin
** Last update Mon Jun 26 16:31:44 2017 Montagne Valentin
*/

#include		<stdlib.h>
#include		"server.h"

static void		default_config(t_server *self)
{
  self->config.ai_port = DEFAULT_AI_PORT;
  self->config.gfx_port = DEFAULT_GFX_PORT;
  self->config.width = DEFAULT_WIDTH;
  self->config.height = DEFAULT_HEIGHT;
  self->config.id_increment = DEFAULT_FIRST_ID;
  self->config.max_level = DEFAULT_MAX_LEVEL;
  self->config.nb_clients = DEFAULT_NB_CLIENTS;
  self->config.nb_win = DEFAULT_NEEDED_WIN;
  self->config.team_names = NULL;
  self->config.time_hatching = DEFAULT_TIME_HATCHING;
  self->config.time_laying = DEFAULT_TIME_LAYING;
  self->config.food_time = DEFAULT_FOOD_HEALTH;
  self->config.frequency = DEFAULT_FREQUENCY;
  self->config.spawn_per_tick = DEFAULT_SPAWN_PER_TICK;
  self->config.spawn_rate.food = DEFAULT_FOOD_RATE;
  self->config.spawn_rate.linemate = DEFAULT_LINEMATE_RATE;
  self->config.spawn_rate.mendiane = DEFAULT_MENDIANE_RATE;
  self->config.spawn_rate.phiras = DEFAULT_PHIRAS_RATE;
  self->config.spawn_rate.sibur = DEFAULT_SIBUR_RATE;
  self->config.spawn_rate.thystame = DEFAULT_THUSTAME_RATE;
  self->config.spawn_rate.deraumere = DEFAULT_DERAUMERE;
  self->config.spawn_delay = DEFAULT_SPAWN_DELAY;
  self->config.spawn_regular_rate = DEFAULT_SPAWN_REG_RATE;
}

static bool		init_server(t_server *self)
{
  self->socket_ai = NULL;
  self->socket_gfx = NULL;
  self->map = NULL;
  self->teams = new_team_list();
  self->players = new_player_list();
  self->connection_queue = new_player_list();
  self->gfx = new_graph_client_list();
  self->chrono = new_chrono();
  self->parser = new_parser();
  self->watcher = new_socket_watcher();
  self->tick_stack = 0;
  default_config(self);
  if (self->teams == NULL ||
      self->players == NULL ||
      self->chrono == NULL ||
      self->parser == NULL ||
      self->watcher == NULL ||
      self->gfx == NULL ||
      self->connection_queue == NULL)
    return (false);
  return (true);
}

static void		init_methods(t_server *self)
{
  self->run = server_run;
  self->initialize = server_initialize;
  self->place_resources = server_place_resources;
  self->sync_gfx = server_sync_gfx;
  self->generate_map = server_generate_map;
  self->listen_ai = server_listen_ai;
  self->listen_gfx = server_listen_gfx;
  self->handle_network = server_handle_network;
  self->generate_tracking = server_generate_tracking;
  self->compute_timeout = server_compute_timeout;
  self->accept_clients = server_accept_clients;
  self->receive_data = server_receive_data;
  self->send_data = server_send_data;
  self->clean_players = server_clean_players;
  self->clean_gfx = server_clean_gfx;
  self->handle_connection_queue = server_handle_connection_queue;
  self->handle_players = server_handle_players;
  self->tick = server_tick;
  self->destroy = server_destroy;
}

t_server		*new_server()
{
  t_server		*self;

  self = malloc(sizeof(t_server));
  if (self == NULL)
    return (NULL);
  init_methods(self);
  if (!init_server(self))
  {
    self->destroy(self);
    return (NULL);
  }
  return (self);
}
