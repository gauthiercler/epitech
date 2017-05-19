/*
** generate_input.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Jun  2 18:45:35 2016 Buyumad Anas
** Last update Sun Jun  5 20:17:12 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"class/line_editor.h"

/*
** Generates the basic input (\0)
** @params self
** @return bool; Success => TRUE, Error => FALSE
*/
bool		line_editor_generate_input(t_line_editor *self)
{
  if ((self->input = malloc(sizeof(char) * 1)) == NULL)
    return (false);
  self->input[0] = '\0';
  return (true);
}
