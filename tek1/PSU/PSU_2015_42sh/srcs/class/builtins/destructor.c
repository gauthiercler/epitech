/*
** destructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/builtins/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May 30 14:40:49 2016 Vincent Dusautoir
** Last update Thu Jun  2 18:35:45 2016 Vincent Dusautoir
*/

#include	<stdlib.h>
#include	"class/builtin.h"

/*
** Destruct builtin object
** @params self
** @return void
*/
void		builtin_destructor(t_builtin *self)
{
  unsigned int	index;

  index = 0;
  if (self != NULL)
    {
      while (index != NB_BUILTINS + 1)
	{
	  if (self->data[index]->builtin != NULL)
	    self->data[index]->builtin->destruct(self->data[index]->builtin);
	  free(self->data[index]);
	  index++;
	}
      free(self);
    }
}
