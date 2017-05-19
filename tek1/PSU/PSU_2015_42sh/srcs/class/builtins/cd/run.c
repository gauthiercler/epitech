/*
** new_request.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/cd/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat May 28 00:28:33 2016 Gauthier Cler
** Last update Sun Jun  5 11:38:19 2016 Gauthier Cler
*/

#include	<string.h>
#include	<stdlib.h>
#include	"class/cd.h"
#include	"class/builtin.h"
#include	"libc.h"

/*
** perform cd builtin
** @params self, request, shell, io
** @return success -> BUILTIN_SUCCESS, error -> BUILTIN_ERROR
*/
int		cd_run(t_builtin_base *builtin, char **request,
		       t_shell *shell, t_io *io)
{
  t_cd		*self;

  (void)io;
  if (count(request) > 2)
    {
      fprintf(stderr, "cd: Too many arguments.\n");
      return (BUILTIN_ERROR);
    }
  self = (t_cd *)builtin;
  self->request_type = self->get_type(request[1]);
  if (self->process(self, shell->env, request[1]) == FALSE)
    return (BUILTIN_ERROR);
  return (BUILTIN_SUCCESS);
}
