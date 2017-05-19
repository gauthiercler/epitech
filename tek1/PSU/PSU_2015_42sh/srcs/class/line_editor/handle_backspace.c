/*
** handle_backspace.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Jun  3 20:04:54 2016 Buyumad Anas
** Last update Sun Jun  5 20:49:27 2016 Buyumad Anas
*/

#include	<ncurses.h>
#include	<term.h>
#include	"class/line_editor.h"

/*
** Backspace Handle
** @params self shell
** @return bool; Success => TRUE, Error => FALSE
*/
bool			line_editor_handle_backspace(t_line_editor *self, t_shell *shell)
{
  char			*delete_char;

  if (self->input_index > 0)
    {
      self->keys[L_KEY_LEFT].handle(self, shell);
      if ((delete_char = self->get_sequence("dc")) == NULL)
	return (false);
      if (tputs(delete_char, 1, self->print_sequence) == ERR)
	return (false);
      if (self->remove_character(self) == false)
	return (false);
    }
  return (true);
}
