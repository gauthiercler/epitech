/*
** main.c for minitalk in /home/gogo/rendu/PSU_2015_minitalk/server/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb  1 12:12:32 2016 Gauthier Cler
** Last update Sun Feb 21 09:41:20 2016 Gauthier Cler
*/

#include		<signal.h>
#include		<unistd.h>
#include		<sys/types.h>
#include		"../include/server.h"

t_server		server;

void			sighandler(int sig)
{
  if (sig == SIGUSR1)
    server.res += (1 << server.count);
  else
    server.res += (0 << server.count);
  server.count += 1;
  if (server.count == 8)
    {
      if (server.res == '\0')
	server.client = 0;
      write(1, &server.res, 1);
      server.count = 0;
      server.res = 0;
    }
  kill(server.pid, SIGUSR1);
}

void	get_pid(int sig)
{
  if (sig == SIGUSR1)
    server.res += (1 << server.count);
  else
    server.res += (0 << server.count);
  server.count += 1;
  if (server.count == 32)
    {
      server.pid = server.res;
      server.count = 0;
      server.res = 0;
      server.client = 1;
    }
}

int             main()
{
  write(1, "PID : ", 6);
  my_put_nbr(getpid());
  write(1, "\n", 1);
  server.client = 0;
  server.count = 0;
  server.res = 0;
  while (1)
    {
      if (server.client == 0)
	{
	  signal(SIGUSR1, get_pid);
	  signal(SIGUSR2, get_pid);
	}
      else
	{
	  signal(SIGUSR1, sighandler);
	  signal(SIGUSR2, sighandler);
	}
      pause();
    }
  return (0);
}
