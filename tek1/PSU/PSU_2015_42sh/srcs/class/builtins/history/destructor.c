/*
** destructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/builtins/history/destructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 20:17:18 2016 Antoine FORET
** Last update Sat Jun 04 20:17:18 2016 Antoine FORET
*/

#include	<malloc.h>
#include	"class/history.h"

/*
** Free memory used by the history bultin
** @params self
** @return void
*/
void		history_destructor(t_builtin_base *builtin)
{
  t_history	*self;

  self = (t_history *)builtin;
  if (self != NULL)
    free(self);
}

