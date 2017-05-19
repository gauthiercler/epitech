/*
** constructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/builtins/alias/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 13:27:07 2016 Vincent Dusautoir
** Last update Sun Jun  5 17:07:41 2016 Vincent Dusautoir
*/

#include	<stdlib.h>
#include	"class/alias.h"

/*
** Set methods of alias object
** @params self
** @return void
*/
static void	alias_methods(t_alias *self)
{
  self->run = alias_run;
  self->destruct = alias_destructor;
}

/*
** Create the alias object
** @params void
** @return success -> alias, failure -> NULL
*/
t_alias		*new_alias(void)
{
  t_alias	*alias;

  if ((alias = malloc(sizeof(t_alias))) == NULL)
    return (NULL);
  alias_methods(alias);
  return (alias);
}
