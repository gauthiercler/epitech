/*
** handle_players.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/handle_players.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 15:13:35 2017 Antoine FORET
** Last update Thu Jun 29 15:13:35 2017 Antoine FORET
*/

#include 		"string_extended.h"
#include		"server.h"

static bool		store_command(t_player *self, t_parser *parser,
					 char *buff)
{
  t_command		*command;

  command = new_command();
  if (command == NULL)
  {
    fprintf(stderr, "[ERROR] Unable to store command.\n");
    return (false);
  }
  if (parser->parse_stream(AI, buff, command) != NOTHING)
  {
    fprintf(stderr, "[WARNING] Unable to parse command.\n");
    command->destroy(command);
    return (false);
  }
  if (self->command_list->size(self->command_list) > 10)
  {
    fprintf(stderr, "[WARNING] Ignoring command form player %d.\n",
	    self->id);
    command->destroy(command);
    return (false);
  }
  return (self->command_list->push(self->command_list, command));
}

static bool		player_parse_cmds(t_player *self, t_parser *parser)
{
  char			buff[PLAYER_BUFFER_SIZE + 1];
  ssize_t 		read;

  read = self->input_buffer->size_before(self->input_buffer, '\n');
  if (read != -1)
  {
    read = self->input_buffer->read(self->input_buffer, buff, (size_t)(read));
    if (read == -1)
      return (false);
    self->input_buffer->skip(self->input_buffer, 1);
    buff[read] = '\0';
    return (store_command(self, parser, buff));
  }
  return (true);
}

static bool		player_execute_cmds(t_player *self, t_server *server)
{
  t_command		*response;

  if (self->command_list->size(self->command_list) != 0)
  {
    response = (t_command *)(self->command_list->first(self->command_list));
    if (response != NULL && self->tick_stack >= response->tick)
    {
      if (response->response == NULL)
	return (false);
      response->exec(response, server, self);
      self->tick_stack -= response->tick;
      self->command_list->pop(self->command_list, response);
      response->destroy(response);
    }
    else if (response == NULL)
      self->tick_stack = 0;
  }
  return (true);
}

void			server_handle_players(t_server *self)
{
  self->players->apply(self->players, (t_list_action)(player_parse_cmds),
		       self->parser);
  self->players->apply(self->players, (t_list_action)(player_execute_cmds),
		       self);
}