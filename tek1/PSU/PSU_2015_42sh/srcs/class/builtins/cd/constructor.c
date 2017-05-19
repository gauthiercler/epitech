/*
** constructor.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/cd/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat May 28 00:09:04 2016 Gauthier Cler
** Last update Sun Jun  5 20:39:02 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/cd.h"

/*
** Define methods available for the cd builtin object
** @params self
** @return void
*/
static void	cd_methods(t_cd *self)
{
  self->run = cd_run;
  self->get_pwd = cd_get_pwd;
  self->get_old_pwd = cd_get_old_pwd;
  self->get_type = cd_get_request_type;
  self->process = cd_process_request;
  self->destruct = cd_destructor;
}

/*
** Generate a new builtin cd object
** @params void
** @return success -> cd object, failure NULL
*/
t_cd		*new_cd(void)
{
  t_cd		*cd;

  if ((cd = malloc(sizeof(t_cd))) == NULL)
    return (NULL);
  cd_methods(cd);
  cd->pwd = NULL;
  return (cd);
}
