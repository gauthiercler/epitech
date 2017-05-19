/*
** get_input.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jun  2 15:56:18 2016 Gauthier Cler
** Last update Thu Jun  9 01:14:06 2016 Buyumad Anas
*/

#include		<string.h>
#include		<unistd.h>
#include		"class/line_editor.h"

/*
** Handles the user_input
** @params self, input shell
** @return bool; Success => TRUE, Error => FALSE
*/
bool			handle_input(t_line_editor *self, unsigned char *input,
				     t_shell *shell)
{
  size_t		state;

  state = self->assess_sequence(self, input, shell);
  if (state == 1)
    return (false);
  else if (state == 3)
    {
      if (input[0] <= 126 && strlen((char *)input) == 1)
	{
	  if (self->add_character(self, input[0]) == false)
	    return (false);
	}
    }
  return (true);
}

/*
** Gets the user input
** @params self shell
** @return bool; Success => TRUE, Error => FALSE
*/
bool			line_editor_get_input(t_line_editor *self,
					      t_shell *shell)
{
  unsigned char		input[4097];
  int			bytes_read;

  while ((bytes_read = read(0, input, 4096)) > 0 && input[0] != '\n')
    {
      input[bytes_read] = '\0';
      if (handle_input(self, input, shell) == false)
	return (false);
    }
  if (input[0] == '\n')
    write(1, "\n", 1);
  return (true);
}
