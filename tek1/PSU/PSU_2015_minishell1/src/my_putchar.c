/*
** my_putchar.c for my_putchar in /home/gauthier/rendu/PSU_2015_minishell1/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 18 14:57:46 2016 Gauthier Cler
** Last update Fri Feb 12 15:22:29 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	"../include/info.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
