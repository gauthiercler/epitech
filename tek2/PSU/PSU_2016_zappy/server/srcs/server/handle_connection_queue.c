/*
** handle_connection_queue.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/handle_connection_queue.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 13:38:25 2017 Antoine FORET
** Last update Thu Jun 29 13:38:25 2017 Antoine FORET
*/

#include	<stdlib.h>
#include	<string_extended.h>
#include	<memory.h>
#include	"server.h"

static void	add_to_team(t_player *player, t_server *server, t_team *team)
{
  char		msg_buff[PLAYER_BUFFER_SIZE];

  player->team = team;
  team->add_player(team, player);
  server->connection_queue->pop(server->connection_queue, player);
  server->players->push(server->players, player);
  snprintf(msg_buff, PLAYER_BUFFER_SIZE, "%ld\n%d %d\n",
	   team->place_available(team, server->config.nb_clients),
	   server->config.width, server->config.height);
  player->send(player, msg_buff);
}

static bool	join_team(t_player *player, t_server *server, char *buff)
{
  t_team	*team;
  size_t	remaining_players;

  team = server->teams->get_team(server->teams, buff);
  if (team == NULL)
  {
    fprintf(stderr, "[WARNING] Invalid team name asked (%s).\n", buff);
    server->watcher->untrack(server->watcher, player->socket);
    player->disconnect(player);
    return (false);
  }
  remaining_players = team->place_available(team, server->config.nb_clients);
  if (remaining_players > 0 &&
      team->players->size(team->players) < server->config.nb_clients)
    add_to_team(player, server, team);
  else if (remaining_players > 0)
    from_egg(player, server, team);
  else
  {
    fprintf(stderr, "[WARNING] No remaining space for player.\n");
    server->watcher->untrack(server->watcher, player->socket);
    player->disconnect(player);
    return (false);
  }
  return (true);
}

static bool	select_team(t_player *player, t_server *server)
{
  char		buff[PLAYER_BUFFER_SIZE + 1];
  ssize_t	to_read;

  to_read = player->input_buffer->size_before(player->input_buffer, '\n');
  if (to_read >= 0)
  {
    player->input_buffer->read(player->input_buffer, buff, (size_t)(to_read));
    player->input_buffer->skip(player->input_buffer, 1);
    buff[to_read] = '\0';
    if (join_team(player, server, buff))
      server->gfx->new_player(server->gfx, player);
  }
  return (true);
}

void		server_handle_connection_queue(t_server *self)
{
  self->connection_queue->apply(self->connection_queue,
				(t_list_action)(select_team), self);
}