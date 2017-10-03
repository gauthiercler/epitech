/*
** parse_arguments.h.h for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/include/parse_arguments.h.h
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 12:25:56 2017 Montagne Valentin
** Last update Thu Jun 22 12:25:56 2017 Montagne Valentin
*/

#ifndef PSU_2016_ZAPPY_PARSE_ARGUMENTS_H_H
# define PSU_2016_ZAPPY_PARSE_ARGUMENTS_H_H

# define		OPTEXPRESSION	("g:p:x:y:c:f:n:F:L:D:S:M:P:T:h")
# define		RESPONSE_LENGTH	(15)

typedef			struct s_response	t_response;

#include				<unistd.h>
#include				"parser.h"

typedef t_error				(*response)(char **av,
							   t_config *conf);

struct					s_response
{
  char 					chara;
  response 				resp;
};

t_error					parse_port_ai
  					(char **av, t_config *conf);
t_error					parse_port_gfx
  					(char **av, t_config *conf);
t_error					parse_port
  					(unsigned int *port,
					 char *error_msg);
t_error					parse_width
  					(char **av, t_config *conf);
t_error					parse_height
  					(char **av, t_config *conf);
t_error					parse_nb_client
  					(char **av, t_config *conf);
t_error					parse_freq
  					(char **av, t_config *conf);
t_error					parse_team_names
  					(char **av, t_config *conf);
t_error					print_help
  					(char **av, t_config *conf);
t_error					parse_rate
  					(float *rate);
t_error					parse_food_rate
  					(char **av, t_config *config);
t_error					parse_linemate_rate
  					(char **av, t_config *config);
t_error					parse_deraumere_rate
  					(char **av, t_config *config);
t_error					parse_sibur_rate
  					(char **av, t_config *config);
t_error					parse_mendiane_rate
  					(char **av, t_config *config);
t_error					parse_phiras_rate
  					(char **av, t_config *config);
t_error					parse_thystame_rate
  					(char **av, t_config *config);

#endif /* !PSU_2016_ZAPPY_PARSE_ARGUMENTS_H_H */
