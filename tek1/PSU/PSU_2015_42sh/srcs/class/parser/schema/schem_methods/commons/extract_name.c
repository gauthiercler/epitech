/*
** extract_name.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/schem_methods/commons/extract_name.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 01 20:49:01 2016 Antoine FORET
** Last update Sun Jun  5 19:00:14 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/command.h"
#include	"libc.h"

/*
** extract name of request
** @params command, parser, request, index
** @return success -> TRUE, error -> FALSE
*/
t_bool		extract_name(t_command *command, t_parser *parser,
				   char **request, unsigned int index)
{
  if (request[index + 1] == NULL ||
      parser->get_schema(parser, request[index + 1]) != NULL)
    {
      fprintf(stderr, "%s\n", MISSING_NAME);
      return (FALSE);
    }
  command->params = (char **)request[index + 1];
  free(request[index]);
  request[index + 1] = NULL;
  request[index] = NULL;
  up_tab(&request[index], 2);
  return (TRUE);
}
