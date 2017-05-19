/*
** is_builtin.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/builtins/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May 30 14:53:06 2016 Vincent Dusautoir
** Last update Thu Jun  2 18:36:30 2016 Vincent Dusautoir
*/

#include	<string.h>
#include	"bool.h"
#include	"class/builtin.h"

/*
** Check if command is builtin
** @params self, command
** @return success -> TRUE, failure -> FALSE
*/
t_bool		builtin_is_builtin(t_builtin *self, char **command)
{
  unsigned int	index;

  index = 0;
  if (command[0] != NULL)
    {
      while (self->data[index]->name != NULL)
	{
	  if (strcmp(self->data[index]->name, command[0]) == 0 &&
	      self->data[index]->builtin != NULL)
	    return (TRUE);
	  index++;
	}
    }
  return (FALSE);
}
