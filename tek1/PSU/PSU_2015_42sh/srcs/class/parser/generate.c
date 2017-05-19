/*
** generate.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/generate.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 13:34:47 2016 Antoine FORET
** Last update Sun Jun  5 18:43:13 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/parser.h"

/*
** Generate parser
** @params self, history manager, command
** @return success -> command error -> NULL
*/
t_command	*parser_generate(t_parser *self, t_history_manager *history,
				  char *command_str)
{
  char		**request;
  t_command	*command;
  t_io		io;

  if ((request = self->explode(self, command_str)) == NULL)
    return (NULL);
  if (history != NULL)
  {
    if ((request = history->run(history, self, request)) == NULL)
      return (NULL);
    history->add_request(history, request);
  }
  io.in = FALSE;
  io.out = FALSE;
  if (request[0] != NULL)
    command = self->import(self, request, &io);
  else
    command = new_command(NULL);
  free(request);
  return (command);
}
