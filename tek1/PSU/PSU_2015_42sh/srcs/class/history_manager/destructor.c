/*
** destructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/destructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 16:42:43 2016 Antoine FORET
** Last update Sat Jun 04 16:42:43 2016 Antoine FORET
*/

#include		<malloc.h>
#include		"class/history_manager.h"

/*
** Free memory used by an history manager object
** @params self
** @return void
*/
void			history_manager_destructor(t_history_manager *self)
{
  if (self != NULL)
  {
    self->clear(self);
    if (self->options.file != NULL)
      free(self->options.file);
    free(self);
  }
}