/*
** server.h for server in /home/gogo/rendu/PSU_2015_minitalk/server/include
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Sat Feb  6 13:54:49 2016 Gauthier Cler
** Last update Tue Feb  9 15:29:29 2016 Gauthier Cler
*/

#ifndef SERVER_H_
# define SERVER_H_

typedef struct	s_server
{
  int		client;
  int		count;
  int		res;
  int		pid;
}		t_server;

void	my_put_nbr(int nb);
void	my_putchar(char c);
int	my_atoi(char *str);

#endif
