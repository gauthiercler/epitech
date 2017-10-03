/*
** parse_nb_client.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/sources/Parser/parse_nb_client.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 14:18:33 2017 Montagne Valentin
** Last update Thu Jun 22 14:18:33 2017 Montagne Valentin
*/

#include			<stdlib.h>
#include                        "parser/parse_arguments.h"

t_error				parse_nb_client(char **av, t_config *conf)
{
  unsigned int			value;

  (void)av;
  if (!is_digits(optarg))
    return (print_error(CRITICAL,
			"-c option only accepts unsigned integers\n"));
  value = (unsigned int)atoi(optarg);
  if (value < 1)
    return (print_error(CRITICAL, "-c option only accepts nb > 1\n"));
  conf->nb_clients = value;
  return (NOTHING);
}