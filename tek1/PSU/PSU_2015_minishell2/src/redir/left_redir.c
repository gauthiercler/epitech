/*
** left_redir.c for left_redir in /home/gogo/rendu/PSU_2015_minishell2/src/redir
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr  9 17:10:21 2016 Gauthier Cler
** Last update Tue Apr 19 11:25:42 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sys/wait.h>
#include	<fcntl.h>
#include	"mysh.h"

int		change_fd(t_redir *redir, t_env *env)
{
  pid_t		pid;
  int		status;

  if ((pid = fork()) == -1)
    return (format(2, "Failed to fork\n"));
  if (pid == 0)
    {
      dup2(env->fd_file, 0);
      launch_command(redir->arg1, env);
      exit(1);
    }
  else
    wait(&status);
  return (SUCCESS);
}

int		left_redir(t_redir *redir, t_env *env)
{
  if (my_strlen(redir->arg2) == 0)
    return (format(2, "Missing name for redirect.\n"));
  if (check_pipe(redir->arg1) == SUCCESS)
    return (format(1, "Ambiguous input redirect.\n"));
  if ((env->fd_file = open(redir->arg2, O_RDONLY)) == -1)
    return (format(2, "Error while opening %s.\n", redir->arg2));
  if (redir->type == LEFT)
    change_fd(redir, env);
  close(env->fd_file);
  return (SUCCESS);
}
