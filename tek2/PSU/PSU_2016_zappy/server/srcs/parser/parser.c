/*
** parser.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/sources/parser.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 10:55:58 2017 Montagne Valentin
** Last update Thu Jun 22 10:56:00 2017 Montagne Valentin
*/

#include			<stdlib.h>
#include                        "parser.h"

static void			init_methods(t_parser *p)
{
  p->parse_arguments = &parse_arguments;
  p->parse_stream = &parse_stream;
  p->destroy = &destroy_parser;
}

t_parser			*new_parser()
{
  t_parser			*parser;

  parser = malloc(sizeof(t_parser));
  if (parser == NULL)
    return (NULL);
  init_methods(parser);
  return (parser);
}

void				destroy_parser(t_parser *self)
{
  free(self);
}