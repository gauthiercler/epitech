/*
** parse_port.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/sources/Parser/parse_port.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 12:33:57 2017 Montagne Valentin
** Last update Thu Jun 22 12:33:58 2017 Montagne Valentin
*/

#include				<stdlib.h>
#include                                "parser/parse_arguments.h"

t_error					parse_port(unsigned int *port, char *error_msg)
{
  if (!is_digits(optarg))
    return (print_error(CRITICAL, error_msg));
  *port = (unsigned int)atoi(optarg);
  return (NOTHING);
}
