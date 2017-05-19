/*
** prompt.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/shell/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May  9 21:33:11 2016 Vincent Dusautoir
** Last update Sun Jun  5 18:39:11 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdio.h>
#include	"class/shell.h"

/*
** Write the prompt on the screen
** @params self
** @return self
*/
t_shell		*shell_prompt(t_shell *self)
{
  t_env_entry	*pwd;
  t_env_entry	*user;

  if (isatty(0) == 1)
    {
      if ((user = self->env->find(self->env, "USER")) != NULL)
	printf("[%s]", user->value);
      if ((pwd = self->env->find(self->env, "PWD")) != NULL)
	printf("%s", pwd->value);
      printf(PROMPT_MESSAGE);
      fflush(stdout);
    }
  return (self);
}
