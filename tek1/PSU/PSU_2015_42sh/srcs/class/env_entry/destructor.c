/*
** destructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env_entry/destructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 13:15:45 2016 Antoine FORET
** Last update Sun Jun  5 19:28:22 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/env_manager.h"

/*
** Free memory used by the env_entry object
** @params self
** @return void
*/
void		env_entry_destructor(t_env_entry *self)
{
  if (self != NULL)
    {
      if (self->key != NULL)
	free(self->key);
      if (self->value != NULL)
	free(self->value);
      free(self);
    }
}
