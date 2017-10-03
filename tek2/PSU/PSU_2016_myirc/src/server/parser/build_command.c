/*
** build_command.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/parser/build_command.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 00:10:08 2017 Anas Buyumad
** Last update Thu Jun 01 00:10:08 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	<arpa/inet.h>
#include	<memory.h>
#include	<stdlib.h>
#include	"common/error.h"
#include	"common/parser.h"
#include	"server/buffer.h"
#include	"server/parser.h"

static bool	build_arguments(t_command *command, char **tokens)
{
  size_t	iterator;

  iterator = 0;
  if ((command->args = malloc(sizeof(char *) *
				(command->nb_args + 1))) == NULL)
  {
    throw_error("malloc", __func__, &operational, CRITICAL);
    return (false);
  }
  while (iterator < command->nb_args)
  {
    if ((command->args[iterator] = strdup(tokens[iterator + 1])) == NULL)
    {
      throw_error("strdup", __func__, &operational, CRITICAL);
      return (false);
    }
    iterator += 1;
  }
  command->args[iterator] = NULL;
  return (true);
}

static void	init_input(char *input, t_client *client,
			      t_command *command)
{
  strip_crlf(input);
  fprintf(stdout,
	  "[Building Command :: Size & CRLF Match]\n"
	    "IP -> %s\nID -> %d\nName -> %s\n--> (%lu) [%s]\n\n",
	  inet_ntoa(client->socket.address.sin_addr),
	  client->id,
	  strlen(client->name) ?
	  client->name : "(None)", strlen(input), input);
  memset(command, 0, sizeof(t_command));
  memcpy(command->raw_input, input, strlen(input));
}

void		build_command(t_cmd_buffer *buffer, t_client *client,
				  char *input)
{
  t_command	command;
  char		**tokens;

  init_input(input, client, &command);
  if ((tokens = split(input, " ")) == NULL)
    return (throw_error("split", __func__, &operational, CRITICAL));
  command.client_id = client->id;
  tokens[0] ?
  (command.type = assess_command(tokens[0])) : (command.type = NONE);
  if (tokens[0])
  {
    command.nb_args = (uint8_t)count_indexes(tokens + 1);
    if (!build_arguments(&command, tokens))
      return ;
  }
  else
  {
    command.nb_args = 0;
    command.args = NULL;
  }
  free(tokens);
  if (!buffer_push(buffer, &command))
    fprintf(stdout, "ERROR Couldn't push command...\n");
}