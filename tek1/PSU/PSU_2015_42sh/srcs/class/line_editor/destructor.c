/*
** destructor.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/line_editor/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jun  2 01:20:33 2016 Gauthier Cler
** Last update Sun Jun  5 20:16:48 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"class/line_editor.h"

/*
** Destroys a line_editor object
** @params self
** @return void;
*/
void		line_editor_destruct(t_line_editor *self)
{
  int		count;

  count = 0;
  while (count < NB_SEQUENCES)
    {
      if (self->keys[count].sequence != NULL)
	free(self->keys[count].sequence);
      count += 1;
    }
  if (self != NULL)
    free(self);
}
