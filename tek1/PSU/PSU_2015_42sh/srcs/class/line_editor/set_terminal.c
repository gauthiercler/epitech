/*
** set_terminal.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jun  2 00:30:00 2016 Gauthier Cler
** Last update Sun Jun  5 20:29:05 2016 Buyumad Anas
*/

#include	<errno.h>
#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<sys/ioctl.h>
#include	<unistd.h>
#include	"class/line_editor.h"

/*
** Sets up the terminal mode
** @params self
** @return bool; Success => TRUE, Error => FALSE
*/
bool		line_editor_set_terminal(t_line_editor *self)
{
  if (ioctl(0, TCGETS, &self->terminal_cf.oldattr) == -1)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      return (false);
    }
  self->terminal_cf.newattr = self->terminal_cf.oldattr;
  self->terminal_cf.newattr.c_lflag &= ~(ICANON | ECHO);
  if (ioctl(0, TCSETS, &self->terminal_cf.newattr) == -1)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      return (false);
    }
  return (true);
}
