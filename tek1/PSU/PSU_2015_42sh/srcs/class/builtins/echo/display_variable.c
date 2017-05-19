/*
** display_variable.c for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/builtins/echo/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Jun  5 07:54:35 2016 Buyumad Anas
** Last update Sun Jun  5 20:47:35 2016 Gauthier Cler
*/

#include	<stdio.h>
#include	"class/echo.h"

/*
** display echo variable
** @params self, string, shell
** @return success -> BUILTIN_SUCCESS, error -> BUILTIN_ERROR
*/
int		echo_display_variable(t_echo *self, char *string,
				      t_shell *shell)
{
  t_env_entry	*entry;
  char		*variable;

  (void)self;
  variable = string + 1;
  entry = shell->env->find(shell->env, variable);
  if (entry == NULL)
    {
      printf("%s: Undefined variable.\n", variable);
      return (BUILTIN_ERROR);
    }
  else
    printf("%s", entry->value);
  fflush(stdout);
  return (BUILTIN_SUCCESS);
}
