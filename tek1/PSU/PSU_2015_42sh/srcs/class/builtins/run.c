/*
** run.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/builtins/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May 30 14:45:18 2016 Vincent Dusautoir
** Last update Thu Jun  2 18:44:01 2016 Vincent Dusautoir
*/

#include	<string.h>
#include	"class/env_manager.h"
#include	"class/builtin.h"

/*
** Run all builtins in the object
** @params self, command, env_manager, io
** @return success -> builtin's run, failure -> BUILTIN_ERROR
*/
int		builtin_run(t_builtin *self, char **command,
			    t_shell *shell, t_io *io)
{
  unsigned int	index;

  index = 0;
  while (self->data[index]->name != NULL)
    {
      if (strcmp(self->data[index]->name, command[0]) == 0)
	return (self->data[index]->builtin->run(self->data[index]->builtin,
						command, shell, io));
      index++;
    }
  return (BUILTIN_ERROR);
}
