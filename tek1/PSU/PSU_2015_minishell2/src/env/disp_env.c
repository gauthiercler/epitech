/*
** disp_env.c for disp_env in /home/gogo/rendu/PSU_2015_minishell2/src/env
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr  2 16:33:36 2016 Gauthier Cler
** Last update Tue Apr 12 23:00:48 2016 Gauthier Cler
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"mysh.h"

int		disp_env(t_env *env)
{
  int		i;
  pid_t		pid;
  int		status;

  i = 0;
  if ((pid = fork()) == -1)
    return (format(2, "Failed to fork\n"));
  if (pid == 0)
    {
      if (env->redir == true)
	dup2(env->fd_file, 1);
      while (env->env[i])
	{
	  format(1, "%s\n", env->env[i]);
	  i += 1;
	}
      exit(1);
    }
  else
    wait(&status);
  return (SUCCESS);
}
