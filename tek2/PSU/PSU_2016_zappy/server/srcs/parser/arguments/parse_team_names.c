/*
** parse_team_names.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/sources/Parser/parse_team_names.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 14:28:40 2017 Montagne Valentin
** Last update Thu Jun 22 14:28:40 2017 Montagne Valentin
*/

#include			<stdio.h>
#include			<stdlib.h>
#include                        "parser/parse_arguments.h"

static void			epur_str(char **str)
{
  while ((*str)[0] == ' ' || (*str)[0] == '\t')
    (*str) += 1;

}

static unsigned int		count_names(char **av)
{
  unsigned int			count;

  count = 0;
  while (av[count])
  {
    epur_str(&av[count]);
    if (av[count][0] == '-')
      break;
    count += 1;
  }
  return (count + 1);
}

t_error				parse_team_names(char **av, t_config *conf)
{
  unsigned int 			i;
  unsigned int			nb;

  epur_str(&optarg);
  if (optarg[0] == '-')
    return (print_error(CRITICAL, "Error: No name after -n\n"));
  nb = count_names(av + optind);
  if (conf->team_names != NULL)
    free(conf->team_names);
  conf->team_names = malloc(sizeof(char *) * (nb + 1));
  conf->team_names[0] = av[optind - 1];
  i = 0;
  while (i < nb)
  {
    conf->team_names[i + 1] = av[optind + i];
    i += 1;
  }
  conf->team_names[i] = NULL;
  return (NOTHING);
}