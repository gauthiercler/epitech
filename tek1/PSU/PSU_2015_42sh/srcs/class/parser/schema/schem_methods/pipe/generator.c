/*
** generator.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/schem_methods/pipe/generator.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 10:18:13 2016 Antoine FORET
** Last update Sun Jun  5 19:06:43 2016 Gauthier Cler
*/

#include		<stdlib.h>
#include		"class/command.h"
#include		"libc.h"

/*
** Check pipe
** @params command
** @return success -> command, error -> NULL
*/
static t_command	*pipe_checker(t_command *command)
{
  if (command->left == NULL || command->right == NULL)
    {
      command->destruct(command);
      return (NULL);
    }
  return (command);
}

/*
** generate new pipe object command
** @params self, parser, request, io
** @return success -> pipe object command, error -> NULL
*/
t_command		*pipe_generate(t_schema *self, t_parser *parser,
				       char **request, t_io *io)
{
  unsigned int		index;
  t_command		*command;
  t_io			save;

  index = self->get_occurence(self, request);
  if ((command = new_command(NULL)) == NULL)
    return (NULL);
  free(request[index]);
  request[index] = NULL;
  command->run = pipe_run;
  set_io(&save, io->in, TRUE);
  command->left = parser->import(parser, request, &save);
  set_io(&save, TRUE, io->out);
  if (command->left != NULL)
    command->right = parser->import(parser, &request[index + 1], &save);
  return (pipe_checker(command));
}
