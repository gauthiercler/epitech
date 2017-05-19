/*
** load_terminal_size.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat Jun  4 16:24:00 2016 Buyumad Anas
** Last update Sun Jun  5 20:25:59 2016 Buyumad Anas
*/

#include		<sys/ioctl.h>
#include		"class/line_editor.h"

/*
** Loads terminal size
** @params self
** @return bool; Success => TRUE, Error => FALSE
*/
bool			line_editor_load_terminal_size(t_line_editor *self)
{
  struct winsize	ws;

  if (ioctl(0, TIOCGWINSZ, &ws) == -1)
    return (false);
  self->terminal_size[0] = ws.ws_col;
  self->terminal_size[1] = ws.ws_row;
  return (true);
}
