/*
** add_character.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Jun  2 14:25:21 2016 Buyumad Anas
** Last update Sun Jun  5 20:05:18 2016 Buyumad Anas
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"class/line_editor.h"

/*
** Adds a character to the end of the input.
** @params self, character
** @return bool ; Success => True, Error => False
*/
static bool	add_character(t_line_editor *self, unsigned char character)
{
  if (self->input == NULL)
    {
      if ((self->input = malloc(sizeof(char) * 2)) == NULL)
	return (false);
    }
  else
    {
      if ((self->input =
	   realloc(self->input,
		   sizeof(char) * (strlen(self->input) + 2))) == NULL)
	return (false);
    }
  self->input[self->input_index] = character;
  self->input[self->input_index + 1] = '\0';
  self->input_index += 1;
  self->cursor_coords[0] += 1;
  write(1, &character, 1);
  return (true);
}

/*
** Adds a character to the end of the input.
** @params self, character
** @return bool ; Success => True, Error => False
*/
bool		line_editor_add_character(t_line_editor *self,
					  unsigned char character)
{
  if (self->input == NULL)
    {
      if (add_character(self, character) == false)
	return (false);
    }
  else if (self->input_index != strlen(self->input))
    {
      if (self->insert_new_character(self, character) == false)
	return (false);
    }
  else
    {
      if (add_character(self, character) == false)
	return (false);
    }
  return (true);
}
