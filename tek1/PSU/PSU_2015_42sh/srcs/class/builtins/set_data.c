/*
** set_data.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/builtins/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May 30 14:23:00 2016 Vincent Dusautoir
** Last update Sun Jun  5 16:34:46 2016 Vincent Dusautoir
*/

#include	<stdlib.h>
#include	"class/env.h"
#include	"class/setenv.h"
#include	"class/echo.h"
#include	"class/cd.h"
#include	"class/unsetenv.h"
#include	"class/exit.h"
#include	"class/which.h"
#include	"class/history.h"
#include	"class/alias.h"
#include	"class/unalias.h"

/*
** Init the data array
** @params self
** @return void
*/
static void	builtin_init_data(t_builtin *self)
{
  unsigned int	index;

  index = 0;
  while (index != NB_BUILTINS + 1)
    {
      if ((self->data[index] = malloc(sizeof(t_data_builtins))) != NULL)
	{
	  self->data[index]->name = NULL;
	  self->data[index]->builtin = NULL;
	}
      index++;
    }
}

/*
** Add builtins in array
** @params self, name, builtin
** @return void
*/
static void	builtin_add_data(t_builtin *self, char *name,
				 t_builtin_base *builtin)
{
  unsigned int	index;

  index = 0;
  while (self->data[index]->name != NULL)
    index++;
  self->data[index]->name = name;
  self->data[index]->builtin = builtin;
}

/*
** Set builtins in data array
** @params self
** @return void
*/
void		builtin_set_data(t_builtin *self)
{
  builtin_init_data(self);
  builtin_add_data(self, "env", (t_builtin_base *)new_env());
  builtin_add_data(self, "exit", (t_builtin_base *)new_exit());
  builtin_add_data(self, "cd", (t_builtin_base *)new_cd());
  builtin_add_data(self, "setenv", (t_builtin_base *)new_setenv());
  builtin_add_data(self, "unsetenv", (t_builtin_base *)new_unsetenv());
  builtin_add_data(self, "echo", (t_builtin_base *)new_echo());
  builtin_add_data(self, "which", (t_builtin_base *)new_which());
  builtin_add_data(self, "history", (t_builtin_base *)new_history());
  builtin_add_data(self, "alias", (t_builtin_base *)new_alias());
  builtin_add_data(self, "unalias", (t_builtin_base *)new_unalias());
}
