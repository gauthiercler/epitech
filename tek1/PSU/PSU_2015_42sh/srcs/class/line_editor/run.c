/*
** run.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Jun  5 20:34:17 2016 Buyumad Anas
** Last update Sun Jun  5 20:45:56 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	<string.h>
#include	"class/line_editor.h"

/*
** Runs the line_editor object and gets the input.
** @params self shell
** @return char * ; Success => Input , Error => NULL
*/
char		*line_editor_run(t_line_editor *self, t_shell *shell)
{
  self->generate_input(self);
  if (self->set_terminal(self) == false)
    return (NULL);
  if (self->reload_cursor)
    {
      if (self->load_cursor_coordinates(self) == false)
	return (NULL);
      self->reload_cursor = false;
    }
  if (self->reload_terminal)
    {
      if (self->load_terminal_size(self) == false)
	return (NULL);
      self->reload_terminal = false;
    }
  if (self->get_input(self, shell) == false)
    return (NULL);
  self->unset_terminal(self);
  self->input_index = 0;
  return (self->input);
}
