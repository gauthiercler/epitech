/*
** find_in.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/find_in.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 15:26:39 2016 Antoine FORET
** Last update Sun Jun  5 18:55:37 2016 Gauthier Cler
*/

#include	<string.h>
#include	"class/schema.h"

/*
** find correct schema
** @params self, request
** @return success -> TRUE error -> FALSE
*/
t_bool		schema_find_in(t_schema *self, char **request)
{
  unsigned int	index;

  index = 0;
  while (request[index] != NULL)
    {
    if (strcmp(request[index], self->token) == 0)
	return (TRUE);
      index++;
    }
  return (FALSE);
}
