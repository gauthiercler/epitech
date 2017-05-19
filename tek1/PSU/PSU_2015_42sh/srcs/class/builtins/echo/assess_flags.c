/*
** assess_flags.c for echo in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/builtins/echo/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 30 23:12:43 2016 Buyumad Anas
** Last update Mon May 30 23:30:01 2016 Buyumad Anas
*/

#include	<string.h>
#include	"class/echo.h"

/*
** Assesses the different flag values
** @params self, command
** @return void
*/
void		echo_assess_flags(t_echo *self, char **command)
{
  if (self->echo_style == SYSV || self->echo_style == BOTH)
    self->escape_flag = TRUE;
  else
    self->escape_flag = FALSE;
  if (command[0] != NULL && command[1] != NULL)
    self->newline_flag = !(strcmp(command[1], "-n"));
  else
    self->newline_flag = FALSE;
}
