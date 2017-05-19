/*
** constructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/constructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 15:18:42 2016 Antoine FORET
** Last update Sun Jun  5 18:57:13 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/schema.h"

/*
** generate a new schema object
** @params token, generate and find_in function pointers
** @return success -> schema object error -> NULL
*/
t_schema	*new_schema(const char *token,
			    t_command *(*generate)(t_schema *self,
					t_parser *parser,
					char **request, t_io *io),
			    t_bool (*find_in)(t_schema *self, char **request))
{
  t_schema	*schema;

  if ((schema = malloc(sizeof(t_schema))) == NULL)
    return (NULL);
  schema->token = token;
  schema->generate = generate;
  schema->find_in = ((find_in == NULL) ? schema_find_in : find_in);
  schema->destruct = schema_destructor;
  schema->get_occurence = schema_get_occurance;
  return (schema);
}
