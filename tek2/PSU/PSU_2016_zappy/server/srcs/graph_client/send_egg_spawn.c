/*
** send_egg_spawn.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_egg_spawn.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 15:33:10 2017 Montagne Valentin
** Last update Wed Jun 28 15:33:10 2017 Montagne Valentin
*/

#include		<string.h>
#include		<stdio.h>
#include		"graph_client.h"

bool			send_egg_spawn(t_graph_client *self,
					    t_egg *egg)
{
  char			msg[MAXBUFFSIZE_EGGSPAWN];

  if (snprintf(msg, MAXBUFFSIZE_EGGSPAWN, "enw %d %d %d %s\n", egg->id,
	      egg->position.x, egg->position.y,
	      egg->team->get_name(egg->team)) == -1)
    return (false);
  return (self->send(self, msg));
}

static bool		send_egg(t_egg *egg, t_graph_client *client)
{
  return (client->send_egg_spawn(client, egg));
}

static bool		team_broadcast(t_team *team, t_graph_client *client)
{
  return (team->eggs->apply(team->eggs, (t_list_action)(send_egg), client));
}

bool			send_eggs_spawn(t_graph_client *self,
					    t_team_list *team)
{
  return (team->apply(team, (t_list_action)(team_broadcast), self));
}