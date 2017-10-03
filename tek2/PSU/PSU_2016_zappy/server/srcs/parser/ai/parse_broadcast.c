/*
** parse_broadcast.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/sources/parser/ai/parse_broadcast.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 23 16:10:23 2017 Montagne Valentin
** Last update Fri Jun 23 16:10:23 2017 Montagne Valentin
*/

#include		<string.h>
#include		"parse_stream.h"

t_error				parse_broadcast(char *stream,
						       t_command *r)
{
  r->add_data(r, strdup(stream));
  return (NOTHING);
}