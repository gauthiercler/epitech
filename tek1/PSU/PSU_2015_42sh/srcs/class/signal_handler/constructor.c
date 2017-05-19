/*
** constructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/signal_handler/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Thu Jun  2 17:28:38 2016 Vincent Dusautoir
** Last update Sun Jun  5 18:37:49 2016 Gauthier Cler
*/

#include		<stdlib.h>
#include		<signal.h>
#include		"class/signal_handler.h"

/*
** Set handled signal in array
** @params self
** @return void
*/
static void		signal_handler_catched_array(t_signal_handler *self)
{
  self->catched_signal[0] = SIGINT;
  self->catched_signal[1] = SIGQUIT;
  self->catched_signal[2] = SIGIOT;
  self->catched_signal[3] = SIGUSR1;
  self->catched_signal[4] = SIGTERM;
  self->catched_signal[5] = SIGTSTP;
  self->catched_signal[6] = SIGTTIN;
  self->catched_signal[7] = SIGTTOU;
  self->catched_signal[8] = SIGXFSZ;
  self->catched_signal[9] = SIGPROF;
  self->catched_signal[10] = SIGPWR;
}

/*
** Set signal_handler methods
** @params self
** @return void
*/
static void		signal_handler_methods(t_signal_handler *self)
{
  self->set = signal_handler_set;
  self->unset = signal_handler_unset;
  self->destruct = signal_handler_destructor;
}

/*
** Create a new signal_handler object
** @params void
** @return success -> signal_handler, failure -> NULL
*/
t_signal_handler	*new_signal_handler(void)
{
  t_signal_handler	*signal_handler;

  if ((signal_handler = malloc(sizeof(t_signal_handler))) == NULL)
    return (NULL);
  signal_handler_methods(signal_handler);
  signal_handler_catched_array(signal_handler);
  return (signal_handler);
}
