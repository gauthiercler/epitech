/*
** run.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/command/simple_left/run.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 16:13:05 2016 Antoine FORET
** Last update Sun Jun  5 19:39:04 2016 Gauthier Cler
*/

#include	<fcntl.h>
#include	<unistd.h>
#include	<errno.h>
#include	<memory.h>
#include	"class/command.h"
#include	"libc.h"

/*
** Run simple left redir
** @params self, shell, io
** @return return value
*/
int		simple_left_run(t_command *self, t_shell *shell, t_io *io)
{
  int		status;
  int		fd;
  t_io		save;

  if ((fd = open((char *)self->params, O_RDONLY)) == -1)
    {
      fprintf(stderr, "%s: %s.\n", (char *)self->params, strerror(errno));
      self->right = NULL;
      return (257);
    }
  set_io(&save, io->in, io->out);
  set_io(io, fd, io->out);
  status = self->left->run(self->left, shell, io);
  close(fd);
  set_io(io, save.in, save.out);
  self->right = NULL;
  return (status);
}
