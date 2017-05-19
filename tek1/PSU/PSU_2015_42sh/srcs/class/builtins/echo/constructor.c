/*
** constructor.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/builtins/echo/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Jun  5 20:36:19 2016 Buyumad Anas
** Last update Sun Jun  5 20:46:31 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/echo.h"

/*
** fill echo escape sequences in tab
** @params self
** @return void
*/
static void	echo_fill_separate(t_echo *self)
{
  self->escapes[0].sequence = "\\\\";
  self->escapes[0].character = '\\';
  self->escapes[1].sequence = "\\a";
  self->escapes[1].character = '\a';
  self->escapes[2].sequence = "\\b";
  self->escapes[2].character = '\b';
  self->escapes[3].sequence = "\\c";
  self->escapes[3].character = '\0';
  self->escapes[4].sequence = "\\e";
  self->escapes[4].character = '\e';
  self->escapes[5].sequence = "\\f";
  self->escapes[5].character = '\f';
  self->escapes[6].sequence = "\\n";
  self->escapes[6].character = '\n';
  self->escapes[7].sequence = "\\r";
  self->escapes[7].character = '\r';
  self->escapes[8].sequence = "\\t";
  self->escapes[8].character = '\t';
  self->escapes[9].sequence = "\\v";
  self->escapes[9].character = '\v';
  self->escapes[10].sequence = NULL;
  self->escapes[10].character = '\0';
}

/*
** Assigns the available methods for the echo object
** @params self
** @return void
*/
static void	echo_methods(t_echo *self)
{
  self->run = echo_run;
  self->destruct = echo_destructor;
  self->assess_style = echo_assess_style;
  self->assess_flags = echo_assess_flags;
  self->display = echo_display;
  self->display_variable = echo_display_variable;
  self->escape = echo_escape;
  echo_fill_separate(self);
  self->string_mode = TRUE;
}

/*
** Generates a new echo object.
** @params none
** @return success -> exit, failure -> NULL
*/
t_echo		*new_echo(void)
{
  t_echo	*echo;

  if ((echo = malloc(sizeof(t_echo))) == NULL)
    return (NULL);
  echo_methods(echo);
  return (echo);
}
