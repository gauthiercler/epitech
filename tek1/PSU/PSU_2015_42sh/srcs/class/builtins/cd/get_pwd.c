/*
** get_pwd.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/cd/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat May 28 10:58:19 2016 Gauthier Cler
** Last update Tue May 31 22:21:03 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<errno.h>
#include	"class/cd.h"

/*
** Get the actual pwd with getcwd call
** @params self
** @return t_bool success -> TRUE, failure -> FALSE
*/
t_bool		cd_get_pwd(t_cd *self)
{
  if (self->pwd != NULL)
    free(self->pwd);
  self->pwd = getcwd(NULL, 0);
  if (self->pwd == NULL)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      return (FALSE);
    }
  return (TRUE);
}
