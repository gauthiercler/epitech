/*
** run.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/command/double_left/run.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 01 09:42:49 2016 Antoine FORET
** Last update Sun Jun  5 19:43:47 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<string.h>
#include	<wait.h>
#include	<unistd.h>
#include	"class/command.h"
#include	"libc.h"

/*
** get input from token
** @prams token
** @return input result
*/
static char	*get_input(const char *token)
{
  char		*input;
  char		*result;
  char		*tmp;

  if ((result = strdup("")) != NULL)
    {
      (isatty(0) == 1) ? fprintf(stdout, "? ") : 0;
      fflush(stdout);
      while ((input = get_next_line(0)) != NULL && strcmp(input, token) != 0)
	{
	  if ((tmp = strcat_ret_only(result, input, '\n')) != NULL)
	    {
	      free(result);
	      result = tmp;
	    }
	  free(input);
	  (isatty(0) == 1) ? fprintf(stdout, "? ") : 0;
	  fflush(stdout);
	}
    }
  return (result);
}

/*
** run buffer
** @params buffer, fd
** @return void
*/
static void	run_buffer(char *buffer, int *fd)
{
  close(fd[0]);
  write(fd[1], buffer, strlen(buffer));
  exit(0);
}

/*
** Run double left redir
** @params self, shell, io
** @return return value
*/
int		double_left_run(t_command *self, t_shell *shell, t_io *io)
{
  t_io		save;
  int		status;
  char		*input;
  int		pid;
  int		fds[2];

  status = 257;
  set_io(&save, io->in, io->out);
  if (self->params != NULL && (input = get_input((char *)self->params)) != NULL)
    {
      pipe(fds);
      if ((pid = fork()) == 0)
	run_buffer(input, fds);
      close(fds[1]);
      set_io(io, fds[0], io->out);
      if (self->left != NULL)
	status = self->left->run(self->left, shell, io);
      close(fds[0]);
      waitpid(pid, NULL, WCONTINUED);
      free(input);
    }
  set_io(io, save.in, save.out);
  return (status);
}
