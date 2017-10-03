/*
** parse_rate.c for PSU_2016_zappy in /home/montag_v/rendu/PSU_2016_zappy/server/srcs/parser/arguments/parse_rate.c
**
** Made by Valentin MONTAGNE
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat Jul 01 20:12:46 2017 Valentin MONTAGNE
** Last update Sat Jul 01 20:12:46 2017 Valentin MONTAGNE
*/

#include		"parse_arguments.h"

t_error			parse_rate(float *rate)
{
  int			r;

  if (is_digits(optarg))
    r = atoi(optarg);
  else
    return (print_error(LERROR, "Rate options are unsigned int.\n"));
  if (r < 0 || r > 500)
    return (print_error(LERROR, "Rate options are only between 0 and 500.\n"));
  *rate = (float)r;
  return (NOTHING);
}