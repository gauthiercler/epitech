/*
** destructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/shell/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May  9 21:25:47 2016 Vincent Dusautoir
** Last update Thu Jun  2 18:08:45 2016 Vincent Dusautoir
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"libc.h"

/*
** Free all memory used to store shell object
** @params self
** @return void
*/
void		shell_destructor(t_shell *self)
{
  if (isatty(0) == 1)
    printf("%s\n", EXIT_MESSAGE);
  if (self != NULL)
    {
      if (self->parser != NULL)
	self->parser->destruct(self->parser);
      if (self->env != NULL)
	self->env->destruct(self->env);
      if (self->builtin != NULL)
	self->builtin->destruct(self->builtin);
      if (self->signal_handler != NULL)
	self->signal_handler->destruct(self->signal_handler);
      if (self->line_editor != NULL)
	self->line_editor->destruct(self->line_editor);
      if (self->history_manager != NULL)
	self->history_manager->destruct(self->history_manager);
      free(self);
    }
}
