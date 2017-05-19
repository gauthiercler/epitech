/*
** run.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/command/semicolon/run.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 21:00:03 2016 Antoine FORET
** Last update Sun Jun  5 19:39:22 2016 Gauthier Cler
*/

#include	"libc.h"
#include	"class/command.h"

/*
** Run semicolon
** @params self, shell, io
** @return return value
*/
int		semicoma_run(t_command *self, t_shell *shell, t_io *io)
{
  int		status;

  set_io(io, 0, 1);
  status = 256;
  if (self->left != NULL)
    status = self->left->run(self->left, shell, io);
  set_io(io, 0, 1);
  if (self->right != NULL)
    status = self->right->run(self->right, shell, io);
  set_io(io, 0, 1);
  return (status);
}
