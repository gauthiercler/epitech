/*
** run.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/builtins/echo/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Jun  5 20:36:08 2016 Buyumad Anas
** Last update Sun Jun  5 20:48:05 2016 Gauthier Cler
*/

#include	"class/echo.h"

/*
** Runs the echo command.
** @params builtin, command, env
** @return int (exit value / error)
*/
int		echo_run(t_builtin_base *builtin, char **command,
			 t_shell *shell, t_io *io)
{
  t_echo	*self;

  (void)shell;
  self = (t_echo *)builtin;
  self->assess_style(self);
  self->assess_flags(self, command);
  if (self->display(self, command, io, shell) == BUILTIN_ERROR)
    return (BUILTIN_ERROR);
  return (BUILTIN_SUCCESS);
}
