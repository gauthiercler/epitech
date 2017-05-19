/*
** generator.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/schem_methods/or/generator.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 14:08:08 2016 Antoine FORET
** Last update Sun Jun  5 19:05:23 2016 Gauthier Cler
*/

#include		<stdlib.h>
#include		<string.h>
#include		"class/command.h"

/*
** check or
** @params command
** @return success -> command, error -> NULL
*/
static t_command	*or_checker(t_command *command)
{
  if (command->left == NULL || command->right == NULL)
    {
      command->destruct(command);
      return (NULL);
    }
  return (command);
}

/*
** generate new or command
** @params self, parser, request, io
** @return success -> command, error -> NULL
*/
t_command		*or_generate(t_schema *self, t_parser *parser,
				     char **request, t_io *io)
{
  unsigned int		index;
  t_command		*command;
  t_schema		*and;

  and = parser->get_schema(parser, AND_TOKEN);
  index = self->get_occurence(self, request);
  if (and != NULL &&
      and->get_occurence(and, request) < index &&
      strcmp(request[and->get_occurence(and, request)], and->token) == 0)
    return (and->generate(and, parser, request, io));
  if ((command = new_command(NULL)) == NULL)
    return (NULL);
  free(request[index]);
  request[index] = NULL;
  command->run = or_run;
  command->left = parser->import(parser, request, io);
  if (command->left != NULL)
    command->right = parser->import(parser, &request[index + 1], io);
  return (or_checker(command));
}
