/*
** cd.c for cd in /home/gogo/rendu/PSU_2015_42sh/includes/class/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat May 28 00:00:08 2016 Gauthier Cler
** Last update Sun Jun  5 13:21:58 2016 Gauthier Cler
*/

#ifndef CD_H_
# define CD_H_

typedef 		struct s_cd t_cd;

# include		"class/env_manager.h"
# include		"class/builtin.h"

# ifndef EMPTY
#  define EMPTY		(0)
# endif /* !EMPTY */

# ifndef PREVIOUS
#  define PREVIOUS	(1)
# endif /* !PREVIOUS */

# ifndef STRING
#  define STRING	(2)
# endif /* !STRING */

struct 			s_cd
{
  int			(*run)(t_builtin_base *self, char **request,
			       t_shell *shell, t_io *io);
  void			(*destruct)(t_builtin_base *self);
  char			*pwd;
  t_env_entry		*old_pwd;
  t_env_entry		*home_path;
  int			request_type;
  int			(*get_type)(char *request);
  t_bool		(*get_pwd)(t_cd *self);
  t_bool		(*get_old_pwd)(t_cd *self, t_env_manager *env);
  t_bool		(*process)(t_cd *self, t_env_manager *env,
				   char *request);
};

t_cd			*new_cd(void);
int			cd_run(t_builtin_base *self, char **request,
			       t_shell *shell, t_io *io);
int			cd_get_request_type(char *request);
t_bool			cd_get_old_pwd(t_cd *self, t_env_manager *env);
t_bool			cd_get_pwd(t_cd *self);
t_bool			cd_process_request(t_cd *self, t_env_manager *env,
					   char *request);
void			cd_destructor(t_builtin_base *self);

#endif /* !CD_H_ */
