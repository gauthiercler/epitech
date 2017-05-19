/*
** signal_handler.h for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/includes/class/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Thu Jun  2 17:33:39 2016 Vincent Dusautoir
** Last update Sun Jun  5 17:59:46 2016 Vincent Dusautoir
*/

#ifndef SIGNAL_HANDLER_H_
# define SIGNAL_HANDLER_H_

typedef 			struct s_signal_handler t_signal_handler;

#ifndef NBR_CATCH_SIGNAL
# define NBR_CATCH_SIGNAL	(11)
#endif /* !NBR_CATCH_SIGNAL */

struct				s_signal_handler
{
  int				catched_signal[NBR_CATCH_SIGNAL];
  void				(*destruct)(t_signal_handler *);
  void				(*set)(t_signal_handler *);
  void				(*unset)(t_signal_handler *);
};

t_signal_handler		*new_signal_handler();
void				signal_handler_destructor(t_signal_handler *);
void				signal_handler_set(t_signal_handler *);
void				signal_handler_unset(t_signal_handler *);

#endif /* SIGNAL_HANDLER_H_ */
