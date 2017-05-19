/*
** delete_end_of_line.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat Jun  4 12:00:53 2016 Buyumad Anas
** Last update Sun Jun  5 20:16:25 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	<string.h>
#include	"class/line_editor.h"

/*
** Gets length of the end string
** @params string, index
** @return size_t ; size
*/
static size_t	end_length(char *string, size_t index)
{
  size_t	size;

  size = 0;
  while (string[index])
    {
      size += 1;
      index += 1;
    }
  return (size);
}

/*
** Deletes the end of the line starting from the cursor to the right
** @params self
** @return bool; Success => TRUE, Error => FALSE
*/
bool		line_editor_delete_end_of_line(t_line_editor *self)
{
  size_t	length;
  size_t	end;

  length = strlen(self->input);
  end = end_length(self->input, self->input_index);
  if ((self->input = realloc(self->input,
			     sizeof(char) * ((length + 1) - end))) == NULL)
    return (false);
  self->input[length - end] = '\0';
  return (true);
}
