/*
** my_putchar.c for my_putchar in /tmp/PSU_2015_minitalk/server/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Sun Feb 21 09:42:39 2016 Gauthier Cler
** Last update Sun Feb 21 09:42:44 2016 Gauthier Cler
*/

#include	<unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
