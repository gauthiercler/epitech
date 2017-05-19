/*
** destructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/builtins/unalias/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 14:51:09 2016 Vincent Dusautoir
** Last update Sun Jun  5 17:09:39 2016 Vincent Dusautoir
*/

#include	<stdlib.h>
#include	"class/builtin.h"
#include	"class/unalias.h"

/*
** Free all the unalias object
** @params self
** @return self
*/
void		unalias_destructor(t_builtin_base *self)
{
  t_unalias	*unalias;

  if (self != NULL)
    {
      unalias = (t_unalias *)self;
      free(unalias);
    }
}
