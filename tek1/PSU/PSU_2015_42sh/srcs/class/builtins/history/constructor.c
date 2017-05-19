/*
** constructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history/constructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 20:04:27 2016 Antoine FORET
** Last update Sat Jun 04 20:04:27 2016 Antoine FORET
*/

#include	<malloc.h>
#include	"class/history.h"

/*
** define history bultin methods
** @params self
** @return void
*/
static void	history_methods(t_history *history)
{
  history->destruct = history_destructor;
  history->run = history_run;
}

/*
** Generate an new history bultin object
** @params void
** @return success -> history object, failure -> NULL
*/
t_history	*new_history()
{
  t_history	*history;

  if ((history = malloc(sizeof(t_history))) == NULL)
    return (NULL);
  history_methods(history);
  return (history);
}
