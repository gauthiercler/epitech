/*
** parse_philas_rate.c for PSU_2016_zappy in /home/montag_v/rendu/PSU_2016_zappy/server/srcs/parser/arguments/parse_philas_rate.c
**
** Made by Valentin MONTAGNE
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat Jul 01 19:36:46 2017 Valentin MONTAGNE
** Last update Sat Jul 01 19:36:46 2017 Valentin MONTAGNE
*/

#include		"parse_arguments.h"

t_error			parse_phiras_rate(char **av, t_config *conf)
{
  (void)av;
  return (parse_rate(&conf->spawn_rate.phiras));
}