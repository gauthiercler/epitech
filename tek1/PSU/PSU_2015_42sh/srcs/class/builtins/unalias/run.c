/*
** run.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/builtins/unalias/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 14:48:58 2016 Vincent Dusautoir
** Last update Sun Jun  5 20:44:13 2016 Gauthier Cler
*/

#include	"libc.h"
#include	"class/builtin.h"
#include	"class/unalias.h"

/*
** Run unalias to remove one or more alias
** @params builtin, request, shell, io
** @return success -> BUILTIN_SUCCESS, failure -> BUILTIN_ERROR
*/
int		unalias_run(t_builtin_base *builtin, char **request,
			    t_shell *shell, t_io *io)
{
  unsigned int	index;

  (void)builtin;
  (void)io;
  if (count(request) >= 2)
    {
      index = 1;
      while (request[index] != NULL)
	{
	  shell->parser->alias_manager
	  ->destructone(shell->parser->alias_manager, request[index]);
	  index++;
	}
    }
  else
    {
      dprintf(2, "unalias: Too few arguments.\n");
      return (BUILTIN_ERROR);
    }
  return (BUILTIN_SUCCESS);
}
