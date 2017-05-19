/*
** destructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/builtins/echo/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May 30 13:18:30 2016 Vincent Dusautoir
** Last update Mon May 30 22:53:38 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"class/echo.h"

/*
** Frees all memory used by the echo object
** @params self
** @return void
*/
void		echo_destructor(t_builtin_base *self)
{
  if (self != NULL)
    free(self);
}
