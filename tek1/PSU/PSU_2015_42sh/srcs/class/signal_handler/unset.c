/*
** unset.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/signal_handler/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Thu Jun  2 17:59:15 2016 Vincent Dusautoir
** Last update Sun Jun  5 19:14:46 2016 Vincent Dusautoir
*/

#include	<unistd.h>
#include	<signal.h>
#include	"class/signal_handler.h"

/*
** Set all handled signal to ignore
** @params self
** @return void
*/
void		signal_handler_unset(t_signal_handler *self)
{
  unsigned int	index;

  index = 0;
  if (isatty(0) != 0)
    {
      while (index != NBR_CATCH_SIGNAL)
	{
	  signal(self->catched_signal[index], SIG_IGN);
	  index++;
	}
    }
}
