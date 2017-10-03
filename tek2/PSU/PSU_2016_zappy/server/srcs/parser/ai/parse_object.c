/*
** parse_take.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/sources/parser/ai/parse_take.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 23 16:16:45 2017 Montagne Valentin
** Last update Fri Jun 23 16:16:45 2017 Montagne Valentin
*/

#include		<stdio.h>
#include		<string.h>
#include		<stdlib.h>
#include		"parse_stream.h"

static const char 		*dico[] =
  {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame",
    NULL
  };

static bool			is_valid(char *object_name)
{
  unsigned int			i;

  i = 0;
  while (dico[i] != NULL)
  {
    if (strcmp(dico[i], object_name) == 0)
      return (true);
    i += 1;
  }
  return (false);
}

t_error				parse_take(char *stream,
						  t_command *r)
{
  if (!is_valid(stream))
    return (CRITICAL);
  r->add_data(r, strdup(stream));
  return (NOTHING);
}

t_error				parse_drop(char *stream,
						  t_command *r)
{
  if (!is_valid(stream))
    return (CRITICAL);
  r->add_data(r, strdup(stream));
  return (NOTHING);
}