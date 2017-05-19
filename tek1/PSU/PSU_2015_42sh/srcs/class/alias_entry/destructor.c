/*
** destructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/alias_entry/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 13:04:56 2016 Vincent Dusautoir
** Last update Sun Jun  5 17:17:29 2016 Vincent Dusautoir
*/

#include	<stdlib.h>
#include	"class/alias_entry.h"

/*
** Free an alias_entry object
** @params self
** @return void
*/
void		alias_entry_destructor(t_alias_entry *self)
{
  unsigned int	index;

  index = 0;
  if (self != NULL)
    {
      if (self->previous != NULL)
	self->previous->next = self->next;
      if (self->next != NULL)
	self->next->previous = self->previous;
      if (self->command != NULL)
	{
	  while (self->command[index])
	    {
	      free(self->command[index]);
	      index++;
	    }
	  free(self->command);
	}
      if (self->alias != NULL)
	free(self->alias);
      free(self);
    }
}
