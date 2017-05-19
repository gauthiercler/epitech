/*
** destructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/signal_handler/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Thu Jun  2 17:32:24 2016 Vincent Dusautoir
** Last update Sun Jun  5 17:37:18 2016 Vincent Dusautoir
*/

#include	<stdlib.h>
#include	"class/signal_handler.h"

/*
** Free the signal_handler object
** @params self
** @return void
*/
void		signal_handler_destructor(t_signal_handler *self)
{
  if (self != NULL)
    free(self);
}
