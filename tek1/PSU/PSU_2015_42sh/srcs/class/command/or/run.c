/*
** or.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/command/run.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 14:09:43 2016 Antoine FORET
** Last update Sun Jun  5 19:41:11 2016 Gauthier Cler
*/

#include	"class/command.h"
#include	"libc.h"

/*
** Run or
** @params self, shell, io
** @return return value
*/
int		or_run(t_command *self, t_shell *shell, t_io *io)
{
  int		status;
  t_io		save;

  set_io(&save, io->in, io->out);
  status = self->left->run(self->left, shell, io);
  set_io(io, save.in, save.out);
  if (status % 256 != 0)
    status = self->right->run(self->right, shell, io);
  set_io(io, save.in, save.out);
  return (status);
}
