/*
** signal_handler.c for signal_handler in /home/gogo/rendu/PSU_2015_minishell2/src/misc
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Mar 29 12:20:29 2016 Gauthier Cler
** Last update Thu Apr 14 00:00:05 2016 Gauthier Cler
*/

#include	<signal.h>
#include	<unistd.h>
#include	"mysh.h"

void		signal_handler(int sig)
{
  (void)sig;
  format(1, "\n");
  disp_prompt(NULL);
  signal(SIGINT, signal_handler);
  prompt = true;
}
