/*
** generator.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/schem_methods/and/generator.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 13:34:49 2016 Antoine FORET
** Last update Sun Jun  5 18:59:17 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<string.h>
#include	"class/command.h"

/*
** check and error and destruct
** @params command, error boolean
** @return success -> command, error -> NULL
*/
t_command	*and_checker(t_command *command, t_bool error)
{
  if (error)
    {
      command->destruct(command);
      return (NULL);
    }
  return (command);
}

/*
** generate command objectfor and
** @params self, parser, request, io
** @return success -> command, error -> NULL
*/
t_command	*and_generate(t_schema *self, t_parser *parser,
				char **request, t_io *io)
{
  unsigned int	index;
  t_schema	*or;
  t_command	*command;
  t_bool	error;

  error = FALSE;
  or = parser->get_schema(parser, OR_TOKEN);
  index = self->get_occurence(self, request);
  if (or != NULL &&
      or->get_occurence(or, request) < index &&
      strcmp(request[or->get_occurence(or, request)], or->token) == 0)
    return (or->generate(or, parser, request, io));
  if ((command = new_command(NULL)) == NULL)
    return (NULL);
  free(request[index]);
  request[index] = NULL;
  command->run = and_run;
  if (request[0] != NULL &&
      (command->left = parser->import(parser, request, io)) == NULL)
    error = TRUE;
  if ((command->left != NULL || request[index + 1] != NULL) &&
      (command->right = parser->import(parser, &request[index + 1], io)) ==
      NULL)
    error = TRUE;
  return (and_checker(command, error));
}
