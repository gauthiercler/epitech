/*
** disp_prompt.c for disp_prompt in /home/gogo/rendu/PSU_2015_minishell2/src/misc
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Mar 29 12:11:53 2016 Gauthier Cler
** Last update Mon Apr 18 23:42:48 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	"mysh.h"

void		usr_cpy(char *user, char *src)
{
  int		i;

  i = 0;
  while (src[i] && i < 4096)
    {
      user[i] = src[i];
      i += 1;
    }
  user[i] = '\0';
}

void		disp_prompt(char **ae)
{
  int		i;
  static char	user[MAX_LENGTH + 1];
  char		pwd[MAX_LENGTH];

  if (isatty(0))
    {
      getcwd(pwd, MAX_LENGTH);
      if (ae != NULL)
	if ((i = check_env(ae, "USER=")) != -1)
	  usr_cpy(user, ae[i] + 5);
      (my_strlen(user) > 0) ? format(1, "[%s%s%s]", RED, user, WHITE) : 0;
      format(1, "%s%s%s$> ", BLUE, pwd, WHITE);
      signal(SIGINT, signal_handler);
    }
}
