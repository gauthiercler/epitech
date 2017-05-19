/*
** path_exec.c for path_exec in /home/gogo/rendu/PSU_2015_minishell2
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr  2 19:07:54 2016 Gauthier Cler
** Last update Tue Apr 19 00:02:32 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"mysh.h"

char		*check_access(char *bin, char **path)
{
  int		i;
  char		*tmp;
  char		*abs;

  i = 0;
  while (path[i])
    {
      tmp = my_strcat(path[i], "/");
      abs = my_strcat(tmp, bin);
      if (access(abs, F_OK | X_OK) == 0)
	{
	  (tmp != NULL) ? free(tmp) : 0;
	  return (abs);
	}
      (tmp != NULL) ? free(tmp) : 0;
      (abs != NULL) ? free(abs) : 0;
      i += 1;
    }
  return (NULL);
}

int		path_exec(t_env *env, char **cmd, char **path)
{
  char		*access;
  pid_t		pid;
  int		status;

  if (path == NULL || cmd[0][0] == '/' || cmd[0][0] == '.')
    return (ERROR);
  if ((access = check_access(cmd[0], path)) == NULL)
    return (ERROR);
  if ((pid = fork()) == -1)
    return (format(2, "Failed to fork\n"));
  if (pid == 0)
    {
      (env->redir == true) ? dup2(env->fd_file, 1) : 0;
      execve(access, cmd, env->env);
      exit(1);
    }
  else
    {
      waitpid(pid, &status, WUNTRACED | WCONTINUED);
      if (WIFSIGNALED(status))
	if (WTERMSIG(status) == 11)
	  format(2, "Segmentation Fault\n");
      (access != NULL) ? free(access) : 0;
    }
  return (SUCCESS);
}
