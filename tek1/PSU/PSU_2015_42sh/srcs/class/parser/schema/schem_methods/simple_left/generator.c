/*
** generator.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/schem_methods/simple_left/generator.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 15:17:06 2016 Antoine FORET
** Last update Sun Jun  5 19:10:47 2016 Gauthier Cler
*/

#include		"class/schema.h"
#include		"libc.h"

/*
** check simple left redir
** @params command
** @return success -> command, error -> NULL
*/
static t_command	*simple_left_checker(t_command *command)
{
  if (command->left == NULL)
    {
      command->destruct(command);
      return (NULL);
    }
  return (command);
}

/*
** generate simple left redirection object
** @params self, parser, request, io
** @return success -> command, error -> NULL
*/
t_command		*simple_left_generate(t_schema *self, t_parser *parser,
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
  command->run = simple_left_run;
  command->terminate = redirection_terminate;
  return (simple_left_checker(command));
}
