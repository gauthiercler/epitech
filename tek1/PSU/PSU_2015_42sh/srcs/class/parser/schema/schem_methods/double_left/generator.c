/*
** generator.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/schem_methods/double_left/generator.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 01 09:31:55 2016 Antoine FORET
** Last update Sun Jun  5 19:01:57 2016 Gauthier Cler
*/

#include		"class/command.h"
#include		"libc.h"

/*
** check double left
** @params command
** @return success -> command, error -> NULL
*/
static t_command	*double_left_checker(t_command *command)
{
  if (command->left == NULL)
    {
      command->destruct(command);
      return (NULL);
    }
  return (command);
}

/*
** generate double left command
** @params selfn parser, request, io
** @return success -> command, error -> NULL
*/
t_command		*double_left_generate(t_schema *self, t_parser *parser,
					      char **request, t_io *io)
{
  unsigned int		index;
  t_command		*command;

  if (io->in != FALSE)
    return (ambiguous_redirect(TRUE));
  index = self->get_occurence(self, request);
  if ((command = new_command(NULL)) == NULL)
    return (NULL);
  if (!extract_name(command, parser, request, index))
    {
      command->destruct(command);
    return (NULL);
    }
  io->in = TRUE;
  command->left = parser->import(parser, request, io);
  io->in = FALSE;
  command->run = double_left_run;
  command->terminate = redirection_terminate;
  return (double_left_checker(command));
}
