/*
** handle_left.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jun  2 11:55:11 2016 Gauthier Cler
** Last update Sun Jun  5 20:50:43 2016 Buyumad Anas
*/

#include	<ncurses.h>
#include	<term.h>
#include	"class/line_editor.h"

/*
** Multi line Left handle
** @params self
** @return bool; Success => TRUE, Error => FALSE
*/
static bool	left_multi_line(t_line_editor *self)
{
  char		*move_left;
  size_t	iterator;

  iterator = 0;
  if ((move_left = self->get_sequence("up")) == NULL)
    return (false);
  if (tputs(move_left, 1, self->print_sequence) == ERR)
    return (false);
  while (iterator < self->terminal_size[0])
    {
      if ((move_left = self->get_sequence("nd")) == NULL)
	return (false);
      if (tputs(move_left, 1, self->print_sequence) == ERR)
	return (false);
      iterator += 1;
    }
  self->input_index -= 1;
  return (true);
}

/*
** Left handle
** @params self shell
** @return bool; Success => TRUE, Error => FALSE
*/
bool		line_editor_handle_left(t_line_editor *self, t_shell *shell)
{
  char		*move_left;

  (void)shell;
  if (self->input_index > 0)
    {
      if (self->load_cursor_coordinates(self) == false)
	return (false);
      if ((int)self->cursor_coords[0] == 1)
	{
	  if (left_multi_line(self) == false)
	    return (false);
	}
      else
	{
	  if ((move_left = self->get_sequence("le")) == NULL)
	    return (false);
	  if (tputs(move_left, 1, self->print_sequence) == ERR)
	    return (false);
	  self->input_index -= 1;
	}
    }
  return (true);
}
