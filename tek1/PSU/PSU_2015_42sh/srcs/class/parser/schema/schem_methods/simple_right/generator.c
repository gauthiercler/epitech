/*
** generator.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/schem_methods/simple_right/generator.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 20:59:24 2016 Antoine FORET
** Last update Sun Jun  5 19:11:18 2016 Gauthier Cler
*/

#include		"class/command.h"
#include		"libc.h"

/*
** check simple right redir
** @params command
** @return success -> command, error -> NULL
*/
static t_command	*simple_right_checker(t_command *command)
{
  if (command->left == NULL)
    {
      command->destruct(command);
      return (NULL);
    }
  return (command);
}

/*
** generate simple right redirection object
** @params self, parser, request, io
** @return success -> command, error -> NULL
*/
t_command		*simple_right_generate(t_schema *self, t_parser *parser,
					       char **request, t_io *io)
{
  unsigned int		index;
  t_command		*command;

  if (io->out != FALSE)
    return (ambiguous_redirect(FALSE));
  index = self->get_occurence(self, request);
  if ((command = new_command(NULL)) == NULL)
    return (NULL);
  if (!extract_name(command, parser, request, index))
  {
    command->destruct(command);
    return (NULL);
  }
  io->out = TRUE;
  command->left = parser->import(parser, request, io);
  io->out = FALSE;
  command->run = simple_right_run;
  command->terminate = redirection_terminate;
  return (simple_right_checker(command));
}
