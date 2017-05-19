/*
** load_cursor_coord.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat Jun  4 14:05:02 2016 Buyumad Anas
** Last update Sun Jun  5 20:25:41 2016 Buyumad Anas
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"class/line_editor.h"

/*
** Loads cursor coordinates
** @params self
** @return bool; Success => TRUE, Error => FALSE
*/
bool		line_editor_load_cursor_coordinates(t_line_editor *self)
{
  char		answer[10];
  int		bytes_read;
  int		coords[2];

  printf("\033[6n");
  fflush(stdout);
  if ((bytes_read = read(0, answer, 10)) == -1)
    return (false);
  answer[bytes_read] = '\0';
  if (self->parse_coordinates(answer, coords) == false)
    return (false);
  self->cursor_coords[0] = coords[0];
  self->cursor_coords[1] = coords[1];
  return (true);
}
