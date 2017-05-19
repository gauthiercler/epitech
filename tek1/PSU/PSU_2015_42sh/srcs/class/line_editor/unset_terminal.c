/*
** unset_terminal.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jun  2 01:51:28 2016 Gauthier Cler
** Last update Sun Jun  5 20:29:15 2016 Buyumad Anas
*/

#include	<string.h>
#include	<stdio.h>
#include	<errno.h>
#include	<sys/ioctl.h>
#include	"class/line_editor.h"

/*
** Unsets up the terminal mode
** @params self
** @return bool; Success => TRUE, Error => FALSE
*/
bool		line_editor_unset_terminal(t_line_editor *self)
{
  if (ioctl(0, TCSETS, &self->terminal_cf.oldattr) == -1)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      return (false);
    }
 return (true);
}
