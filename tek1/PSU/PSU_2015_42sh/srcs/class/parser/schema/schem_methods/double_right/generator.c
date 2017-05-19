/*
** generator.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/schem_methods/double_right/generator.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 21:18:13 2016 Antoine FORET
** Last update Sun Jun  5 19:02:38 2016 Gauthier Cler
*/

#include		"class/command.h"
#include		"libc.h"

/*
** check double right
** @params command
** @return success -> command, error -> NULL
*/
static t_command	*double_right_checker(t_command *command)
{
  if (command->left == NULL)
    {
      command->destruct(command);
      return (NULL);
    }
  return (command);
}

/*
** generate double right command
** @params selfn parser, request, io
** @return success -> command, error -> NULL
*/
t_command		*double_right_generate(t_schema *self, t_parser *parser,
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
  command->run = double_right_run;
  command->terminate = redirection_terminate;
  return (double_right_checker(command));
}
