/*
** import.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/import.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 14:49:45 2016 Antoine FORET
** Last update Sun Jun  5 18:42:32 2016 Gauthier Cler
*/

#include	"class/parser.h"

/*
** import a request
** @params self, request, io
** @return t_command result of generate()
*/
t_command	*parser_import(t_parser *self, char **request, t_io *io)
{
  unsigned int	index;

  index = 0;
  while (!self->schema[index]->find_in(self->schema[index], request))
    index++;
  return (self->schema[index]->generate(self->schema[index], self, request,
					io));
}
