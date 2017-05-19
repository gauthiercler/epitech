/*
** get.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env/get.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 13:38:01 2016 Antoine FORET
** Last update Mon May 30 14:41:02 2016 Gauthier Cler
*/

#include	"class/env_manager.h"

/*
** Check if there is any entry of given index, if so return it else return NULL
** @params self, entry_index
** @return success -> entry, failure -> NULL
*/
t_env_entry	*env_manager_get(t_env_manager *self, unsigned int index)
{
  if (index < self->size)
    return (self->values[index]);
  else
    return (NULL);
}
