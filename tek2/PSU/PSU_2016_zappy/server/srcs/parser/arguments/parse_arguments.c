/*
** parse_arguments.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/sources/Parser/parse_arguments.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 11:19:12 2017 Montagne Valentin
** Last update Thu Jun 22 11:19:12 2017 Montagne Valentin
*/

#include 				<stdio.h>
#include                                "parser/parse_arguments.h"

static const t_response 		responses[RESPONSE_LENGTH] =
  {
    { 'p', parse_port_ai },
    { 'g', parse_port_gfx},
    { 'x', parse_width },
    { 'y', parse_height },
    { 'c', parse_nb_client },
    { 'f', parse_freq },
    { 'n', parse_team_names },
    { 'h', print_help },
    { 'F', parse_food_rate },
    { 'L', parse_linemate_rate },
    { 'D', parse_deraumere_rate },
    { 'S', parse_sibur_rate },
    { 'M', parse_mendiane_rate },
    { 'P', parse_phiras_rate },
    { 'T', parse_thystame_rate }
  };

static t_error				find_response(int chara, char **av,
							     t_config *conf)
{
  t_error				ret;
  unsigned int				i;

  i = 0;
  while (i < RESPONSE_LENGTH)
  {
    if (responses[i].chara == chara)
    {
      if ((ret = responses[i].resp(av, conf)) != NOTHING)
	return (ret);
      break;
    }
    i += 1;
  }
  if (i == RESPONSE_LENGTH)
    return (
      print_error(LERROR,
		  "ERROR Couldn't understand param : %s\n", av[optind - 1]));
  else
    return (NOTHING);
}

t_error					parse_arguments(int ac,
							       char **av,
							       t_config *conf)
{
  t_error				ret;
  int					chara;

  opterr = 0;
  while ((chara = getopt(ac, av, OPTEXPRESSION)) != -1)
    if ((ret = find_response(chara, av, conf)) != NOTHING)
    {
      print_usage(av[0]);
      return (ret);
    }
  return (NOTHING);
}
