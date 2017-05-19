/*
** get_occurence.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/schem_methods/get_occurence.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 20:47:11 2016 Antoine FORET
** Last update Sun Jun  5 18:52:47 2016 Gauthier Cler
*/

#include	<string.h>
#include	"class/parser.h"

/*
** get the schema occurence
** @params self, request
** @return success -> index error -> 0
*/
unsigned int	schema_get_occurance(t_schema *self, char **request)
{
  unsigned int	index;

  index = 0;
  while (request[index] != NULL)
    {
      if (strcmp(request[index], self->token) == 0)
	return (index);
      index++;
    }
  return (0);
}
