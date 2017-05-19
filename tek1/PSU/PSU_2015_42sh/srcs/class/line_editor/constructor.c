/*
** constructor.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Jun  5 20:34:34 2016 Buyumad Anas
** Last update Sun Jun  5 20:35:42 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"class/line_editor.h"

/*
** Builds line_editor methods
** @params self
** @return void
*/
static void	line_editor_methods(t_line_editor *self)
{
  self->run = line_editor_run;
  self->destruct = line_editor_destruct;
  self->build_sequences = line_editor_build_sequences;
  self->set_terminal = line_editor_set_terminal;
  self->unset_terminal = line_editor_unset_terminal;
  self->get_input = line_editor_get_input;
  self->generate_input = line_editor_generate_input;
  self->assess_sequence = line_editor_assess_sequence;
  self->add_character = line_editor_add_character;
  self->remove_character = line_editor_remove_character;
  self->insert_new_character = line_editor_insert_character;
  self->delete_end_of_line = line_editor_delete_end_of_line;
  self->get_sequence = line_editor_get_sequence;
  self->print_sequence = line_editor_print_sequence;
  self->load_cursor_coordinates = line_editor_load_cursor_coordinates;
  self->parse_coordinates = line_editor_parse_coordinates;
  self->load_terminal_size = line_editor_load_terminal_size;
  self->input = NULL;
  self->input_index = 0;
  self->reload_cursor = true;
  self->reload_terminal = true;
}

/*
** Builds a new line_editor Object
** @params env
** @return line_editor; Success => object, Error => null
*/
t_line_editor	*new_line_editor(char **env)
{
  t_line_editor *line_editor;

  if ((line_editor = calloc(1, sizeof(t_line_editor))) == NULL)
    return (NULL);
  line_editor_methods(line_editor);
  if (line_editor_build_sequences(line_editor, env) == false)
    {
      line_editor->destruct(line_editor);
      return (NULL);
    }
  return (line_editor);
}
