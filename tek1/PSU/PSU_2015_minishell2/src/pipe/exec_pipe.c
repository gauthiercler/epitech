/*
** exec_pipe.c for exec_pipe in /home/gogo/rendu/PSU_2015_minishell2/src/pipe
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr  5 14:38:27 2016 Gauthier Cler
** Last update Thu Apr 14 00:39:10 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	"mysh.h"

int		first_pipe_exec(char *instruction, t_env *env)
{
  pid_t		pid;

  if ((pid = fork()) == -1)
    return (format(2, "Failed to fork\n"));
  if (pid == 0)
    {
      dup2(env->fd[1], 1);
      close(env->fd[0]);
      launch_command(instruction, env);
      exit(1);
    }
  else
    {
      close(env->fd[1]);
      env->save = env->fd[0];
    }
  return (SUCCESS);
}

int		multi_pipe_exec(char *instruction, t_env *env)
{
  pid_t		pid;

  if ((pid = fork()) == -1)
    return (format(2, "Failed to fork\n"));
  if (pid == 0)
    {
      dup2(env->save, 0);
      dup2(env->fd[1], 1);
      close(env->fd[0]);
      launch_command(instruction, env);
      exit(1);
    }
  else
    {
      close(env->fd[1]);
      close(env->save);
      env->save = env->fd[0];
    }
  return (SUCCESS);
}

int		end_pipe_exec(char *instruction, t_env *env)
{
  pid_t		pid;

  if ((pid = fork()) == -1)
    return (format(2, "Failed to fork\n"));
  if (pid == 0)
    {
      if (env->redir_pipe == true)
	env->redir = true;
      dup2(env->fd[0], 0);
      close(env->save);
      close(env->fd[1]);
      launch_command(instruction, env);
      exit(1);
    }
  else
    {
      close(env->fd[0]);
      close(env->fd[1]);
      close(env->save);
    }
  return (SUCCESS);
}
