/*
** insert_character.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Jun  2 14:51:08 2016 Buyumad Anas
** Last update Sun Jun  5 20:25:00 2016 Buyumad Anas
*/

#include	<string.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<ncurses.h>
#include	<term.h>
#include	"class/line_editor.h"

/*
** Inserts a character into the input at the index
** @params self, character
** @return bool; Success => TRUE, Error => FALSE
*/
static bool	insert_middle_character(t_line_editor *self,
					unsigned char character)
{
  size_t	iterator;
  size_t	length;
  char		save;
  char		swap;

  length = strlen(self->input);
  if ((self->input = realloc(self->input,
			     sizeof(char) * (strlen(self->input) + 2))) == NULL)
    return (false);
  iterator = self->input_index;
  save = self->input[iterator];
  self->input[iterator] = character;
  iterator += 1;
  while (iterator < length + 1)
    {
      swap = self->input[iterator];
      self->input[iterator] = save;
      save = swap;
      iterator += 1;
    }
  self->input[iterator] = '\0';
  self->input_index += 1;
  return (true);
}

/*
** Inserts a character into the input at the index
** @params self, character
** @return bool; Success => TRUE, Error => FALSE
*/
bool		line_editor_insert_character(t_line_editor *self,
					     unsigned char character)
{
  char		*insertion;

  if ((insertion = self->get_sequence("im")) == NULL)
    return (false);
  if (tputs(insertion, 1, self->print_sequence) == ERR)
    return (false);
  write(1, &character, 1);
  if ((insertion = self->get_sequence("ei")) == NULL)
    return (false);
  if (tputs(insertion, 1, self->print_sequence) == ERR)
    return (false);
  if (insert_middle_character(self, character) == false)
    return (false);
  return (true);
}
