/*
** run.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/env/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May 30 14:58:51 2016 Gauthier Cler
** Last update Tue May 31 13:50:45 2016 Gauthier Cler
*/

#include	"class/builtin.h"
#include	"class/env.h"

/*
** Assess and execute builtin env command
** @params self, arguments, env
** @return int success -> BUILTIN_SUCCESS, failure BUILTIN_ERROR
*/
int		env_run(t_builtin_base *builtin, char **request,
			t_shell *shell, t_io *io)
{
  (void)builtin;
  if (request[1] != NULL)
    {
      fprintf(stderr, "env: %s: Aucun fichier ou dossier de ce type\n",
	      request[1]);
      return (BUILTIN_ERROR);
    }
  shell->env->display(shell->env, io->out);
  return (BUILTIN_SUCCESS);
}
