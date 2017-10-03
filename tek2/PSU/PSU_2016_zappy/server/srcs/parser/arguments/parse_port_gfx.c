/*
** parse_port_gfx.c for PSU_2016_zappy in /home/montag_v/rendu/PSU_2016_zappy/server/srcs/parser/arguments/parse_port_gfx.c
**
** Made by Valentin MONTAGNE
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sun Jul 02 08:53:39 2017 Valentin MONTAGNE
** Last update Sun Jul 02 08:53:39 2017 Valentin MONTAGNE
*/

#include		"parse_arguments.h"

t_error			parse_port_gfx(char **av, t_config *conf)
{
  (void) av;
  if (!is_digits(optarg))
    return (print_error(CRITICAL, "-g Invalid port\n"));
  conf->gfx_port = (uint16_t) atoi(optarg);
  return (NOTHING);
}