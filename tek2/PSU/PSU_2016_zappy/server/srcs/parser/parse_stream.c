/*
** parse_stream.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/sources/parser/parse_stream.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 23 14:59:43 2017 Montagne Valentin
** Last update Fri Jun 23 14:59:43 2017 Montagne Valentin
*/

#include		"parser.h"
#include		"parse_stream.h"

t_error			parse_stream(t_parsing_type type,
					    char *stream,
					    t_command *r)
{
  if (type == AI)
    return (parse_ai(stream, r));
  else
    return (parse_graphical(stream, r));
}