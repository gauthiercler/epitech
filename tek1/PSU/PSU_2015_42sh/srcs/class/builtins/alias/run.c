/*
** run.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/builtins/alias/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 13:43:14 2016 Vincent Dusautoir
** Last update Sun Jun  5 20:36:05 2016 Gauthier Cler
*/

#include	"libc.h"
#include	"class/builtin.h"
#include	"class/alias.h"

/*
** Run the alias builtin
** @params builtin, request, shell, io
** @return BUILTIN_SUCCESS
*/
int		alias_run(t_builtin_base *builtin, char **request,
			  t_shell *shell, t_io *io)
{
  (void)builtin;
  if (count(request) == 1)
    {
      shell->parser->alias_manager->display(shell->parser->alias_manager,
					  io->out);
    }
  else if (count(request) == 2)
    {
      shell->parser->alias_manager->displayone(shell->parser->alias_manager,
					       request[1], io->out);
    }
  else if (count(request) >= 3)
    {
      shell->parser->alias_manager->add(shell->parser->alias_manager,
					request[1],
					&request[2]);
    }
  return (BUILTIN_SUCCESS);
}
