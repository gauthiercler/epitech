/*
** destructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_entry/destructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 19:24:09 2016 Antoine FORET
** Last update Sun Jun  5 20:50:55 2016 Gauthier Cler
*/

#include	<malloc.h>
#include	"class/history_entry.h"

/*
** Free memory used by an history entry object
** @params self
** @return void
*/
void		history_entry_destructor(t_history_entry *self)
{
  if (self != NULL)
    {
      if (self->command != NULL)
	free(self->command);
      free(self);
    }
}
