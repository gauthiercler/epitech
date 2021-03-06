/*
** run.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/setenv/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May 30 16:29:05 2016 Gauthier Cler
** Last update Sun Jun  5 20:44:36 2016 Gauthier Cler
*/

#include	"libc.h"
#include	"class/setenv.h"

/*
** Assess and execute the setenv builtin command
** @params self, arguments, environment
** @return success -> BUILTIN_SUCCESS, failure BUILTIN_ERROR
*/
int		setenv_run(t_builtin_base *builtin, char **request,
			   t_shell *shell, t_io *io)
{
  t_setenv	*self;

  self = (t_setenv *)builtin;
  if (!self->checker(request))
    return (BUILTIN_ERROR);
  if (request[1] == NULL)
    shell->env->display(shell->env, io->out);
  else
    shell->env->set(shell->env, request[1], request[2]);
  return (BUILTIN_SUCCESS);
}
