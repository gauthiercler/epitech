/*
** timer.c for time in /tmp/PSU_2015_tetris/srcs/game/timer
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Mar 14 17:08:47 2016 Gauthier Cler
** Last update Thu Mar 17 13:38:04 2016 Gauthier Cler
*/

#include	"tetris.h"

void		sighandler(int sig)
{
  (sig == SIGUSR1) ? tick[0] = 1 : 0;
  if (sig == SIGINT)
    {
      set_term_settings(1);
      curs_set(1);
      putp(tigetstr("clear"));
      exit(0);
    }
  (sig == SIGWINCH) ? tick[1] = 1 : 0;
}

void		fork_timer(int time, pid_t daddy_pid)
{
  pid_t		pid;

  if (time <= 0)
    time = 1;
  pid = fork();
  if (pid == 0)
    {
      usleep(10000 * time);
      if (kill(daddy_pid, SIGUSR1) == -1)
	kill(daddy_pid, SIGUSR1);
      exit(0);
    }
  else
    return ;
}
