/*
** initialize.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/initialize.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 13:02:36 2017 Antoine FORET
** Last update Wed Jun 28 13:02:36 2017 Antoine FORET
*/

#include		<stdio.h>
#include		<signal.h>
#include		<time.h>
#include		"server.h"

static t_server		*server = NULL;

static const char	*default_teams[] =
  {
    "Team1",
    "Team2",
    "Team3",
    "Team4",
    NULL
  };

static void		signal_handler()
{
  fprintf(stderr, "[INFO] Halt signal received.\n");
  if (server != NULL)
    server->running = false;
}

static void		init_halt(t_server *self)
{
  struct sigaction	handler;

  server = self;
  sigemptyset(&handler.sa_mask);
  handler.sa_flags = 0;
  handler.sa_handler = signal_handler;
  sigaction(SIGINT, &handler, NULL);
}

static bool		default_team(t_config *config)
{
  unsigned int		i;

  config->team_names = malloc(sizeof(char *) * (NB_DEFAULT_TEAMS + 1));
  if (config->team_names == NULL)
    return (false);
  i = 0;
  while (i < NB_DEFAULT_TEAMS)
  {
    config->team_names[i] = (char *)default_teams[i];
    i += 1;
  }
  config->team_names[i] = NULL;
  return (true);
}

static bool		init_teams(t_server *self)
{
  unsigned int		idx;
  t_team		*team;

  idx = 0;
  if (self->config.team_names == NULL)
    if (!default_team(&self->config))
      return (false);
  while (self->config.team_names[idx] != NULL)
  {
    team = new_team(self->config.team_names[idx]);
    if (team == NULL)
      return (false);
    self->teams->add_team(self->teams, team);
    idx += 1;
  }
  return (true);
}

bool			server_initialize(t_server *self, int argc, const char *argv[])
{
  fprintf(stderr, "[INFO] Initializing server.\n");
  if (self->parser->parse_arguments(argc, (char **)(argv), &self->config) ==
      CRITICAL)
  {
    fprintf(stderr, "[ERROR] Unable to use parameters.\n");
    return (false);
  }
  if (!init_teams(self) ||
      !self->generate_map(self) ||
      !self->listen_ai(self) ||
      !self->listen_gfx(self))
    return (false);
  init_halt(self);
  srand((unsigned int)(time(NULL)));
  self->teams->dump(self->teams);
  return (true);
}