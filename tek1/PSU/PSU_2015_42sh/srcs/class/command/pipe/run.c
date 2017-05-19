/*
** run.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/command/pipe/run.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 10:19:53 2016 Antoine FORET
** Last update Sun Jun  5 19:40:14 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<wait.h>
#include	"class/command.h"
#include	"libc.h"

/*
** Run pipe exec
** @params self, shell, io, status
** @return void
*/
static void	exec_pipe(t_command *self, t_shell *shell, t_io *io,
			     int *status)
{
  if (self != NULL && self->run != NULL)
    *status = self->run(self, shell, io);
}

/*
** Run pipe method exec
** @params self, shell, io
** @return return value
*/
int		pipe_run(t_command *self, t_shell *shell, t_io *io)
{
  int		fds[2];
  t_io		save;
  int		pid;
  int		status;
  int		status_child;

  pipe(fds);
  set_io(&save, io->in, io->out);
  pid = fork();
  status = 256;
  if (pid == 0)
    {
      close(fds[0]);
      set_io(io, save.in, fds[1]);
      exec_pipe(self->left, shell, io, &status);
      exit(status);
    }
  close(fds[1]);
  set_io(io, fds[0], save.out);
  exec_pipe(self->right, shell, io, &status);
  close(fds[0]);
  waitpid(pid, &status_child, WCONTINUED);
  status_child = WEXITSTATUS(status_child) + 256;
  set_io(io, save.in, save.out);
  return ((status > status_child) ? status : status_child);
}
