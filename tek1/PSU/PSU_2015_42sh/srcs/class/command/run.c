/*
** run.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/schem_methods/execution/run.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 19:31:32 2016 Antoine FORET
** Last update Sun Jun  5 19:30:22 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/command.h"

/*
** run command
** @params self, shell, io
** @return status
*/
int		command_run(t_command *self, t_shell *shell, t_io *io)
{
  char		*path;
  int		status;

  status = 256;
  if (self->params != NULL && self->params[0] != NULL)
    {
      if (shell->builtin->is_builtin(shell->builtin, self->params))
	status = shell->builtin->run(shell->builtin, self->params, shell, io);
      else if (self->is_relative(self))
	status = self->exec(self->params[0], self->params, shell, io) + 256;
      else
	{
	  path = self->search_path(shell->env, self->params[0]);
	  status = self->exec(path, self->params, shell, io) + 256;
	  if (path != NULL)
	    free(path);
	}
    }
  return (status);
}
