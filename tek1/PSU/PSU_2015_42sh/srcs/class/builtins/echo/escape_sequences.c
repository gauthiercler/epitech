/*
** escape_sequences.c for echo in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/builtins/echo/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 30 23:40:49 2016 Buyumad Anas
** Last update Sun Jun  5 20:48:01 2016 Gauthier Cler
*/

#include	<string.h>
#include	<unistd.h>
#include	"libc.h"
#include	"class/echo.h"

/*
** Get the escape index of the current sequence
** @params self, string, index
** @return escape_index index
*/
static size_t	get_escape_index(t_escape *escapes, char *string, size_t index)
{
  size_t	iterator;

  iterator = 0;
  while (escapes[iterator].sequence)
    {
      if (strnkcmp(string, escapes[iterator].sequence, index,
		   strlen(escapes[iterator].sequence)))
	return (iterator);
      iterator += 1;
    }
  return (iterator);
}

/*
** Escapes the current sequence using the string and its index
** @params self, string, index
** @return void
*/
void		echo_escape(t_echo *self, char *string, size_t *index, t_io *io)
{
  size_t	escape_index;

  *index += 1;
  escape_index = get_escape_index(self->escapes, string, *index);
  if (self->escapes[escape_index].sequence)
    {
      write(io->out, &self->escapes[escape_index].character, 1);
      *index += strlen(self->escapes[escape_index].sequence);
    }
  else
    {
      if (string[*index] != '\\')
	write(io->out, &string[*index], 1);
      *index += 1;
    }
}
