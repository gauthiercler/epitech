/*
** assess_sequence.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Jun  2 12:09:04 2016 Buyumad Anas
** Last update Sun Jun  5 20:47:46 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	<string.h>
#include	"class/line_editor.h"

/*
** Handles the eot termination sequence
** @params self
** @return size_t
*/
static size_t	handle_eot(t_line_editor *self)
{
  if (!strlen(self->input))
    {
      self->unset_terminal(self);
      free(self->input);
      return (1);
    }
  return (2);
}

/*
** Finds the corresponding sequence
** @params self, input shell
** @return size_t ; Exit shell => 1, Success => 2, Error => 3
*/
size_t		line_editor_assess_sequence(t_line_editor *self,
					    unsigned char *input, t_shell *shell)
{
  size_t	iterator;

  iterator = 0;
  while (self->keys[iterator].sequence)
    {
      if (strcmp(self->keys[iterator].sequence, (char *)input) == 0)
	{
	  if (iterator == L_EOT)
	    return (handle_eot(self));
	  if (iterator != L_TAB)
	    {
	      if (self->keys[iterator].handle(self, shell) == false)
		return (1);
	    }
	  return (2);
	}
      iterator += 1;
    }
  return (3);
}
