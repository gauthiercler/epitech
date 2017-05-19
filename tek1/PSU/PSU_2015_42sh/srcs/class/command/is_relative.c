/*
** is_relative.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/command/is_relative.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 21:48:57 2016 Antoine FORET
** Last update Sun Jun  5 19:32:21 2016 Gauthier Cler
*/

#include	"class/command.h"
#include	"libc.h"

/*
** check if command is relative
** @params self
** @return state
*/
t_bool		command_is_relative(t_command *self)
{
  return (in_string('/', self->params[0]));
}
