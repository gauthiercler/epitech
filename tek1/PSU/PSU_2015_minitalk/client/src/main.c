/*
** main.c for main in /home/gogo/rendu/PSU_2015_minitalk/client/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb  1 12:01:09 2016 Gauthier Cler
** Last update Sun Feb 21 09:37:55 2016 Gauthier Cler
*/

#include        <unistd.h>
#include	<stdlib.h>
#include        <signal.h>
#include	"../include/client.h"

void    send_loop(int pid, char c)
{
  int   i;

  i = 0;
  while (i != 8)
    {
      if (((c >> i) & 1) == 1)
	kill(pid, SIGUSR1);
      else
	kill(pid, SIGUSR2);
      usleep(10000);
      i += 1;
    }
}

void	send_pid(int dest, int pid)
{
  int	i;

  i = 0;
  while (i != 32)
    {
      if (((pid >> i) & 1) == 1)
	kill(dest, SIGUSR1);
      else
	kill(dest, SIGUSR2);
      usleep(4000);
      i += 1;
    }
}

void	sig_handler(int sig)
{
  (void)sig;
}

int     main(int ac, char **av)
{
  int   i;

  i = 0;
  signal(SIGUSR1, sig_handler);
  if (ac != 3)
    return (0);
  send_pid(my_atoi(av[1]), getpid());
  while (av[2][i])
    {
      send_loop(my_atoi(av[1]), av[2][i]);
      i += 1;
    }
  send_loop(my_atoi(av[1]), '\0');
}
