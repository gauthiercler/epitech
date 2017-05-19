/*
** exec.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/command/exec.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 21:50:37 2016 Antoine FORET
** Last update Sun Jun  5 19:35:37 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/wait.h>
#include	<memory.h>
#include	<errno.h>
#include	"class/command.h"

/*
** display status of command
** @params status
** @return void
*/
static void	command_display_status(int status)
{
  int		writed;

  writed = 0;
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == SIGSEGV)
	writed += write(2, "Segmentation fault", 18);
      if (WTERMSIG(status) == SIGFPE)
	writed += write(2, "Floating exception", 18);
      if (WTERMSIG(status) == SIGILL)
	writed += write(2, "Illegal instruction", 19);
      if (WTERMSIG(status) == SIGKILL)
	writed += write(2, "Killed", 6);
      if (WTERMSIG(status) == SIGUSR1)
	writed += write(2, "User signal 1", 13);
      if (WTERMSIG(status) == SIGUSR2)
	writed += write(2, "User signal 2", 13);
      if (WCOREDUMP(status))
	writed += write(2, " (core dumped)", 14);
      if (writed > 0)
	write(2, "\n", 2);
    }
}

/*
** Check if command is runnable
** @params path, params
** @return success -> TRUE, error -> FALSE
*/
static t_bool	is_runnable(const char *path, char **params)
{
  if (path == NULL || access(path, F_OK))
    {
      fprintf(stderr, "%s: Command not found.\n", params[0]);
      return (FALSE);
    }
  else if (access(path, F_OK | X_OK))
    {
      fprintf(stderr, "%s: %s.\n", params[0], strerror(errno));
      return (FALSE);
    }
  return (TRUE);
}

/*
** execute command
** @params path, params, shell, io
** @return return value
*/
int		command_exec(const char *path, char **params,
				t_shell *shell, t_io *io)
{
  int		pid;
  int		status;

  if (!is_runnable(path, params))
    return (1);
  else if ((pid = fork()) == 0)
    {
      shell->signal_handler->set(shell->signal_handler);
      dup2(io->in, 0);
      dup2(io->out, 1);
      if (execve(path, params, shell->env->export(shell->env)) == -1)
	fprintf(stderr, "%s: %s.\n", path, strerror(errno));
      exit(257);
    }
  else
    {
      waitpid(pid, &status, WCONTINUED);
      command_display_status(status);
    }
  return (WEXITSTATUS(status));
}
