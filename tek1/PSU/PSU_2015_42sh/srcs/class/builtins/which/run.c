/*
** run.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/which/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Jun  4 00:35:47 2016 Gauthier Cler
** Last update Sun Jun  5 20:43:41 2016 Gauthier Cler
*/

#include		<stdlib.h>
#include		<string.h>
#include		"class/which.h"

/*
** Check builtins
** @params command, shell
** @return success -> TRUE, error -> FALSE
*/
static t_bool		builtin_checker(char *command, t_shell *shell)
{
  int			index;

  index = 0;
  while (index < NB_BUILTINS)
    {
      if (strcmp(command, shell->builtin->data[index]->name) == 0)
	return (TRUE);
      index += 1;
    }
  return (FALSE);
}

/*
** find bin whith path
** @params self, command, shell, io
** @return success -> TRUE, error -> FALSE
*/
static t_bool		which_find_bin(t_which *self, char **command,
				       t_shell *shell, t_io *io)
{
  int			index;
  t_bool		ret_value;
  char			*path;

  (void)self;
  ret_value = TRUE;
  index = 1;
  while (command[index])
    {
      if (builtin_checker(command[index], shell) == TRUE)
	dprintf(io->out, "%s: shell built-in command.\n", command[index]);
      else if ((path = command_search_path(shell->env, command[index])) != NULL)
	{
	  dprintf(io->out, "%s\n", path);
	  free(path);
	}
      else
	{
	  ret_value = FALSE;
	  dprintf(2, "%s: Command not found.\n", command[index]);
	}
      index += 1;
    }
  return (ret_value);
}

/*
** run which command
** @params builtin, command, shell, io
** @return success -> BUILTIN_SUCCESS, error BUILTIN_ERROR
*/
int			which_run(t_builtin_base *builtin, char **command,
				  t_shell *shell, t_io *io)
{
  t_which		*self;

  self = (t_which *)builtin;
  if (!self->checker(command))
    return (BUILTIN_ERROR);
  if (which_find_bin(self, command, shell, io) == FALSE)
    return (BUILTIN_ERROR);
  return (BUILTIN_SUCCESS);
}
