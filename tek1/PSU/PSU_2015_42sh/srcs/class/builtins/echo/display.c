/*
** display.c for echo in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/builtins/echo/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 30 23:27:07 2016 Buyumad Anas
** Last update Sun Jun  5 20:47:50 2016 Gauthier Cler
*/

#include	<string.h>
#include	<unistd.h>
#include	"libc.h"
#include	"class/echo.h"

/*
** Displays the string
** @params self, string
** @return int
*/
static int	display_string(t_echo *self, char *string, t_io *io,
			       t_shell *shell)
{
  size_t	iterator;

  iterator = 0;
  if (strlen(string) > 1 && string[0] == '$')
    {
      if (self->display_variable(self, string, shell) == BUILTIN_ERROR)
	return (BUILTIN_ERROR);
    }
  else
    {
      while (string[iterator])
	{
	  if (string[iterator] == '\\' && self->escape_flag)
	    self->escape(self, string, &iterator, io);
	  else
	    write(io->out, &string[iterator++], 1);
	}
    }
  return (BUILTIN_SUCCESS);
}

/*
** Displays the command
** @params self, command
** @return void
*/
int		echo_display(t_echo *self, char **command, t_io *io,
			     t_shell *shell)
{
  size_t	iterator;
  size_t	strings;

  if ((self->echo_style == BSD || self->echo_style == BOTH) &&
      self->newline_flag)
    iterator = 2;
  else
    iterator = 1;
  strings = count(command);
  while (iterator < strings)
    {
      if (display_string(self, command[iterator], io, shell) == BUILTIN_ERROR)
	return (BUILTIN_ERROR);
      iterator += 1;
      (command[iterator]) ? write(io->out, " ", 1) : 0;
    }
  if (self->echo_style == SYSV || self->echo_style == NONE)
    write(io->out, "\n", 1);
  else
    {
      if (!self->newline_flag)
	write(io->out, "\n", 1);
    }
  return (BUILTIN_SUCCESS);
}
