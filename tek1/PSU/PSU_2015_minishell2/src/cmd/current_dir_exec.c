/*
** current_dir_exec.c for current_dir_exec in /home/gogo/rendu/PSU_2015_minishell2
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr  2 19:18:38 2016 Gauthier Cler
** Last update Tue Apr 19 00:03:40 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	"mysh.h"

int		current_dir_exec(t_env *env, char **cmd)
{
  pid_t		pid;
  int		status;

  if (cmd[0][0] != '.' && cmd[0][0] != '/')
    return (format(2, "%s: Command not found.\n", cmd[0]));
  if (access(cmd[0], F_OK | X_OK) != 0)
    return (format(2, "%s: Command not found.\n", cmd[0]));
  pid = fork();
  if (pid == -1)
    return (format(2, "Failed to fork\n"));
  if (pid == 0)
    {
      (env->redir == true) ? dup2(env->fd_file, 1) : 0;
      execve(cmd[0], cmd, env->env);
      exit(1);
    }
  else
    {
      waitpid(pid, &status, WUNTRACED | WCONTINUED);
      if (WIFSIGNALED(status))
        if (WTERMSIG(status) == 11)
          format(2, "Segmentation Fault\n");
    }
  return (SUCCESS);
}
