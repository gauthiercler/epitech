/*
** handle_clear.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat Jun  4 04:46:22 2016 Buyumad Anas
** Last update Sun Jun  5 21:01:14 2016 Buyumad Anas
*/

#include	<stdio.h>
#include	<ncurses.h>
#include	<term.h>
#include	"class/line_editor.h"

/*
** Clear Handle
** @params self
** @return bool; Success => TRUE, Error => FALSE
*/
bool			line_editor_handle_clear(t_line_editor *self,
						 t_shell *shell)
{
  char			*clear_sequence;

  if ((clear_sequence = self->get_sequence("cl")) == NULL)
    return (false);
  if (tputs(clear_sequence, 1, self->print_sequence) == ERR)
    return (false);
  shell_prompt(shell);
  printf("%s", self->input);
  fflush(stdout);
  return (true);
}
