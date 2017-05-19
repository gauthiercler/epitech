/*
** generator.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/schem_methods/semicolon/generator.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 20:43:01 2016 Antoine FORET
** Last update Sun Jun  5 19:09:06 2016 Gauthier Cler
*/

#include		<stdlib.h>
#include		"class/schema.h"
#include		"libc.h"

/*
** check semicolom
** @params command, error boolean
** @return success -> command, error -> NULL
*/
static t_command	*semicolon_checker(t_command *command, t_bool error)
{
  if (error)
    {
      command->destruct(command);
      return (NULL);
    }
  return (command);
}

/*
** import command in command object
** @params parser, request, error
** @return command
*/
static t_command	*import_command(t_parser *parser, char **request,
					t_bool *error)
{
  t_io			io;
  t_command		*command;

  set_io(&io, 0, 0);
  command = NULL;
  if (request[0] != NULL)
    {
      if ((command = parser->import(parser, request, &io)) == NULL)
	*error = TRUE;
    }
  return (command);
}

/*
** Generate new semicolon object command
** @params self, parser, request, io
** @return success -> command, error NULL
*/
t_command		*semicolon_generate(t_schema *self, t_parser *parser,
					    char **request, t_io *io)
{
  unsigned int		index;
  t_command		*command;
  t_bool		error;

  index = self->get_occurence(self, request);
  if ((command = new_command(NULL)) == NULL)
    return (NULL);
  free(request[index]);
  request[index] = NULL;
  error = FALSE;
  command->run = semicoma_run;
  command->left = import_command(parser, request, &error);
  command->right = import_command(parser, &request[index + 1], &error);
  return (semicolon_checker(command, error));
  (void)io;
}
