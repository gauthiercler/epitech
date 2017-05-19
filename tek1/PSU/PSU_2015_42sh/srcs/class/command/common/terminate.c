/*
** terminate.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/command/common/terminate.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 01 19:21:36 2016 Antoine FORET
** Last update Sun Jun  5 19:44:17 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/command.h"

/*
** clean redirection
** @params self
** @return void
*/
void		redirection_terminate(t_command *self)
{
  if (self != NULL)
    {
      if (self->params != NULL)
	free(self->params);
      self->params = NULL;
    }
}
