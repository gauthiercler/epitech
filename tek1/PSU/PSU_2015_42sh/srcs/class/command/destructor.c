/*
** destructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/command/destructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 19:28:24 2016 Antoine FORET
** Last update Sun Jun  5 19:36:04 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/command.h"
#include	"libc.h"

/*
** destruct command object
** @params self
** @return void
*/
void		command_destructor(t_command *self)
{
  if (self != NULL)
    {
      if (self->terminate != NULL)
	self->terminate(self);
      if (self->left != NULL)
	self->left->destruct(self->left);
      if (self->right != NULL)
	self->right->destruct(self->right);
      if (self->params != NULL)
	destroy_array(self->params);
      free(self);
    }
}
