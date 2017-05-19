/*
** instruction.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/shell/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jun  2 15:55:12 2016 Gauthier Cler
** Last update Sun Jun  5 20:52:24 2016 Buyumad Anas
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"bool.h"
#include	"libc.h"

/*
** Get the instruction puts on the prompt
** @params self
** @return BOOLEAN : success -> true, failure -> false
*/
t_bool		shell_get_instruction(t_shell *self)
{
  if (isatty(0) == 1 && self->line_editor != NULL)
    {
      if ((self->instruction = self->line_editor->run(self->line_editor, self))
	  != NULL)
	return (TRUE);
    }
  else
    {
      if ((self->instruction = get_next_line(0)) != NULL)
	return (TRUE);
    }
  return (FALSE);
}

/*
** Free the instruction
** @params self
** @return void
*/
void		shell_instruction_destroy(t_shell *self)
{
  if (self->instruction != NULL)
    free(self->instruction);
}
