/*
** handle_right.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jun  2 11:55:43 2016 Gauthier Cler
** Last update Sun Jun  5 20:51:21 2016 Buyumad Anas
*/

#include	<ncurses.h>
#include	<string.h>
#include	<term.h>
#include	"class/line_editor.h"

/*
** Multi line Right handle
** @params self
** @return bool; Success => TRUE, Error => FALSE
*/
static bool	right_multi_line(t_line_editor *self)
{
  char		*move_right;
  size_t	iterator;

  iterator = 0;
  if ((move_right = self->get_sequence("do")) == NULL)
    return (false);
  if (tputs(move_right, 1, self->print_sequence) == ERR)
    return (false);
  while (iterator < self->terminal_size[0] - 2)
    {
      if ((move_right = self->get_sequence("le")) == NULL)
	return (false);
      if (tputs(move_right, 1, self->print_sequence) == ERR)
	return (false);
      iterator += 1;
    }
  self->input_index += 1;
  return (true);
}

/*
** Right Handle
** @params self shell
** @return bool; Success => TRUE, Error => FALSE
*/
bool		line_editor_handle_right(t_line_editor *self, t_shell *shell)
{
  char		*move_right;

  (void)shell;
  if (self->input_index < strlen(self->input))
    {
      if (self->load_cursor_coordinates(self) == false)
	return (false);
      if (self->cursor_coords[0] == self->terminal_size[0])
	{
	  if (right_multi_line(self) == false)
	    return (false);
	}
      else
	{
	  if (self->load_cursor_coordinates(self) == false)
	    return (false);
	  if ((move_right = self->get_sequence("nd")) == NULL)
	    return (false);
	  if (tputs(move_right, 1, self->print_sequence) == ERR)
	    return (false);
	  self->input_index += 1;
	}
    }
  return (true);
}
