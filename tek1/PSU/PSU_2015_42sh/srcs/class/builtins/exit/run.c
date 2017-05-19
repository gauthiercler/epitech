/*
** run.c for exit in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/builtins/exit/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 30 14:23:15 2016 Buyumad Anas
** Last update Tue May 31 14:15:33 2016 Gauthier Cler
*/

#include	"class/exit.h"

/*
** Runs the exit command.
** @params builtin, command, env
** @return int (exit value / error)
*/
int		exit_run(t_builtin_base *builtin, char **command,
			 t_shell *shell, t_io *io)
{
  t_exit	*self;

  (void)io;
  (void)shell;
  self = (t_exit *)builtin;
  if (!self->checker(command))
    return (BUILTIN_ERROR);
  if (command[1] == NULL)
    return (0);
  return (self->get_value(command[1]));
}
