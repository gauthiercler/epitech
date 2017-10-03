/*
** parse_width.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/sources/Parser/parse_width.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 14:03:33 2017 Montagne Valentin
** Last update Thu Jun 22 14:03:33 2017 Montagne Valentin
*/

#include			<stdlib.h>
#include                        "parser/parse_arguments.h"

t_error				parse_width(char **av, t_config *conf)
{
  unsigned int			value;

  (void)av;
  if (!is_digits(optarg))
    return (print_error(CRITICAL,
			"-x option only accepts unsigned integers\n"));
  value = (unsigned int)atoi(optarg);
  if (value < 10 || value > 30)
    return (print_error(CRITICAL,
			"-x option only accepts x in range 10 < x < 30\n"));
  conf->width = value;
  return (NOTHING);
}