/*
** generator.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/schem_methods/execution/generator.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 19:12:29 2016 Antoine FORET
** Last update Sun Jun  5 19:03:29 2016 Gauthier Cler
*/

#include	"class/schema.h"

/*
** generate exec command
** @params self, parser, request, io
** @return success -> command, error -> false
*/
t_command	*exec_generate(t_schema *self, t_parser *parser, char **request,
				t_io *io)
{
  if (request == NULL || request[0] == NULL)
    {
      fprintf(stderr, "Invalid null command.\n");
      return (NULL);
    }
  return (new_command(request));
  (void)io;
  (void)parser;
  (void)self;
}
