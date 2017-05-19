/*
** destructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/builtins/alias/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 13:54:09 2016 Vincent Dusautoir
** Last update Sun Jun  5 17:08:09 2016 Vincent Dusautoir
*/

#include	<stdlib.h>
#include	"class/alias.h"

/*
** Free all the alias object
** @params self
** @return void
*/
void		alias_destructor(t_builtin_base *self)
{
  t_alias	*alias;

  alias = (t_alias *)self;
  if (alias != NULL)
    free(alias);
}
