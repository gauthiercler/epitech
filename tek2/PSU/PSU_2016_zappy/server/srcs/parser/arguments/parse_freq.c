/*
** parse_freq.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/sources/Parser/parse_freq.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 14:23:37 2017 Montagne Valentin
** Last update Thu Jun 22 14:23:37 2017 Montagne Valentin
*/

#include			<stdlib.h>
#include                        "parser/parse_arguments.h"

t_error				parse_freq(char **av, t_config *conf)
{
  unsigned int			value;

  (void)av;
  if (!is_digits(optarg))
    return (print_error(CRITICAL,
			"-f option only accepts unsigned integers\n"));
  value = (unsigned int)atoi(optarg);
  if (value < 2 || value > 10000)
    return (print_error(CRITICAL,
			"-f option only accepts values 2 < freq < 10000\n"));
  conf->frequency = value;
  return (NOTHING);
}