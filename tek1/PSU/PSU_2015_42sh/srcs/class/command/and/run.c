/*
** run.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/command/and/run.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 13:44:37 2016 Antoine FORET
** Last update Sun Jun  5 19:44:29 2016 Gauthier Cler
*/

#include	"class/command.h"
#include	"libc.h"

/*
** Run and
** @params self, shell, io
** @return return value
*/
int		and_run(t_command *self, t_shell *shell, t_io *io)
{
  int		status;
  t_io		save;

  set_io(&save, io->in, io->out);
  status = 256;
  if (self->left != NULL)
    status = self->left->run(self->left, shell, io);
  set_io(io, save.in, save.out);
  if (status % 256 == 0 && self->right != NULL)
    status = self->right->run(self->right, shell, io);
  set_io(io, save.in, save.out);
  return (status);
}
