/*
** run.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/unsetenv/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May 30 17:39:37 2016 Gauthier Cler
** Last update Tue May 31 20:49:20 2016 Vincent Dusautoir
*/

#include	"class/unsetenv.h"
#include	"class/builtin.h"

/*
** Assess and execute the unsetenv builtin command
** @params self, arguments, environment
** @return success -> BUILTIN_SUCCESS, failure -> BUILTIN_ERROR
*/
int		unsetenv_run(t_builtin_base *builtin, char **request,
			     t_shell *shell, t_io *io)
{
  int		count;

  (void)builtin;
  (void)io;
  count = 1;
  if (request[1] == NULL)
    {
      fprintf(stderr, "%s: Too few arguments.\n", request[0]);
      return (BUILTIN_ERROR);
    }
  while (request[count])
    shell->env->remove(shell->env, request[count++]);
  return (BUILTIN_SUCCESS);
}
