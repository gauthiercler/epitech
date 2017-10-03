/*
** from_egg.c for PSU_2016_zappy in /home/montag_v/rendu/PSU_2016_zappy/server/srcs/server/from_egg.c
**
** Made by Valentin MONTAGNE
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sun Jul 02 17:57:02 2017 Valentin MONTAGNE
** Last update Sun Jul 02 17:57:02 2017 Valentin MONTAGNE
*/

#include		<string.h>
#include		<stdio.h>
#include		"server.h"

bool			send_egg_hatched(t_graph_client *gfx, t_egg *egg)
{
  char			buffer[100];

  memset(buffer, 0, 100);
  sprintf(buffer, "eex %d\n", egg->id);
  return (gfx->send(gfx, buffer));
}

static void	no_egg(t_player *player, t_server *server, t_team *team)
{
  fprintf(stderr,
	  "[WARNING] Player trying to join team %s without slot or egg.\n",
	  team->name);
  server->watcher->untrack(server->watcher, player->socket);
  player->disconnect(player);
  sleep(1);
}

void		from_egg(t_player *player, t_server *server, t_team *team)
{
  char		msg_buff[PLAYER_BUFFER_SIZE];
  t_egg		*egg;

  if (team->nb_eggs(team) <= 0)
    return (no_egg(player, server, team));
  egg = team->first_egg(team);
  player->team = team;
  player->position.x = egg->position.x;
  player->position.y = egg->position.y;
  player->direction = (unsigned int)(rand() % 4);
  player->id = egg->id;
  server->gfx->apply(server->gfx, (t_list_action)send_egg_hatched, egg);
  team->pop_egg(team);
  team->add_player(team, player);
  server->connection_queue->pop(server->connection_queue, player);
  server->players->push(server->players, player);
  snprintf(msg_buff, PLAYER_BUFFER_SIZE, "%ld\n%d %d\n",
	   team->place_available(team, server->config.nb_clients),
	   server->config.width, server->config.height);
  player->send(player, msg_buff);
}