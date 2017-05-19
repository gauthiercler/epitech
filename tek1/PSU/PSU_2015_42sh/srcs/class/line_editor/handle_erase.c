/*
** handle_erase.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat Jun  4 11:20:48 2016 Buyumad Anas
** Last update Sun Jun  5 20:50:29 2016 Buyumad Anas
*/

#include	<ncurses.h>
#include	<stdlib.h>
#include	<string.h>
#include	<term.h>
#include	"class/line_editor.h"

/*
** Erase Handle
** @params self shell
** @return bool; Success => TRUE, Error => FALSE
*/
bool		line_editor_handle_erase(t_line_editor *self, t_shell *shell)
{
  char		*erase_sequence;

  (void)shell;
  if (strlen(self->input) > 0)
    {
      if (self->delete_end_of_line(self) == false)
	return (false);
      if ((erase_sequence = self->get_sequence("ce")) == NULL)
	return (false);
      if (tputs(erase_sequence, 1, self->print_sequence) == ERR)
	return (false);
    }
  return (true);
}
