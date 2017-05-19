/*
** delete_character.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Jun  3 22:59:28 2016 Buyumad Anas
** Last update Sun Jun  5 20:15:15 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	<string.h>
#include	"class/line_editor.h"

/*
** Removes a character of the input on the current index
** @params self
** @return bool; Success => TRUE, Error => FALSE
*/
bool		line_editor_remove_character(t_line_editor *self)
{
  char		*temporary;
  size_t	iterator;
  size_t	index;

  if (strlen(self->input))
    {
      iterator = 0;
      index = 0;
      if ((temporary = malloc(sizeof(char) * (strlen(self->input)))) == NULL)
	return (false);
      while (self->input[iterator])
	{
	  if (iterator != self->input_index)
	    {
	      temporary[index] = self->input[iterator];
	      index += 1;
	    }
	  iterator += 1;
	}
      temporary[index] = '\0';
      free(self->input);
      self->input = temporary;
    }
  return (true);
}
