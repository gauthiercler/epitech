/*
** constructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/builtins/unalias/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 14:43:22 2016 Vincent Dusautoir
** Last update Sun Jun  5 17:09:17 2016 Vincent Dusautoir
*/

#include	<stdlib.h>
#include	"class/unalias.h"

/*
** Set methods of unalias object
** @params self
** @return void
*/
static void	unalias_methods(t_unalias *self)
{
  self->run = unalias_run;
  self->destruct = unalias_destructor;
}

/*
** Create the unalias object
** @params void
** @return success -> unalias, failure -> NULL
*/
t_unalias	*new_unalias(void)
{
  t_unalias	*unalias;

  if ((unalias = malloc(sizeof(t_unalias))) == NULL)
    return (NULL);
  unalias_methods(unalias);
  return (unalias);
}
