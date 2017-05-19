/*
** destructor.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/cd/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat May 28 00:09:18 2016 Gauthier Cler
** Last update Tue May 31 00:16:36 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/cd.h"

/*
** Free cd bultin object and pwd
** @params self
** @return void
*/
void		cd_destructor(t_builtin_base *builtin)
{
  t_cd		*self;

  self = (t_cd *)builtin;
  if (self->pwd != NULL)
    free(self->pwd);
  if (self != NULL)
    free(self);
}
