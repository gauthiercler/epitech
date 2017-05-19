/*
** destructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/schema/destructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 15:20:53 2016 Antoine FORET
** Last update Sun Jun  5 18:56:06 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/schema.h"

/*
** destruct schema
** @params self
** @return void
*/
void		schema_destructor(t_schema *self)
{
  if (self != NULL)
    {
      free(self);
    }
}
