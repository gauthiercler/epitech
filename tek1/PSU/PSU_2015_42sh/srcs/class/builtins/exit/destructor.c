/*
** destructor.c for exit in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/builtins/exit/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 30 13:53:27 2016 Buyumad Anas
** Last update Mon May 30 22:53:47 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"class/exit.h"

/*
** Frees all memory used by the exit object
** @params self
** @return void
*/
void		exit_destructor(t_builtin_base *self)
{
  if (self != NULL)
    free(self);
}
