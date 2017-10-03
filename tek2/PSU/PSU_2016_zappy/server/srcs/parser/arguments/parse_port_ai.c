/*
** parse_port_ai.c for PSU_2016_zappy in /home/montag_v/rendu/PSU_2016_zappy/server/srcs/parser/arguments/parse_port_ai.c
**
** Made by Valentin MONTAGNE
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sun Jul 02 08:51:30 2017 Valentin MONTAGNE
** Last update Sun Jul 02 08:51:30 2017 Valentin MONTAGNE
*/

#include		"parse_arguments.h"

t_error			parse_port_ai(char **av, t_config *conf)
{
  (void) av;
  if (!is_digits(optarg))
    return (print_error(CRITICAL, "-p Invalid port\n"));
  conf->ai_port = (uint16_t) atoi(optarg);
  return (NOTHING);
}