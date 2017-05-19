/*
** get_schema.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/get_schema.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 14:49:51 2016 Antoine FORET
** Last update Sun Jun  5 18:44:09 2016 Gauthier Cler
*/

#include	<string.h>
#include	"class/parser.h"

/*
** get schema from token
** @params self, token
** @return success -> schema error -> NULL
*/
t_schema	*parser_get_schema(t_parser *self, const char *token)
{
  unsigned int	index;

  index = 0;
  while (index < NB_TOKENS)
    {
      if (self->schema[index]->token != NULL &&
	strcmp(self->schema[index]->token, token) == 0)
	return (self->schema[index]);
      index++;
    }
  return (NULL);
}
