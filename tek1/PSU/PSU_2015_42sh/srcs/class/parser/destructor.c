/*
** destructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/destructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 13:30:17 2016 Antoine FORET
** Last update Sun Jun  5 18:47:02 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/parser.h"

/*
** destruct all schema
** @params self
** @return void
*/
static void	parser_destruct_shema(t_parser *self)
{
  unsigned int	index;

  index = 0;
  while (index < NB_TOKENS)
    {
      if (self->schema[index] != NULL)
	free(self->schema[index]);
      index++;
    }
}

/*
** destruct parser
** @params self
** @return void
*/
void		parser_destructor(t_parser *self)
{
  if (self != NULL)
    {
      parser_destruct_shema(self);
      if (self->alias_manager != NULL)
	self->alias_manager->destruct(self->alias_manager);
      free(self);
    }
}
