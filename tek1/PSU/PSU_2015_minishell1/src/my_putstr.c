/*
** my_putstr.c for my_putstr in /home/gauthier/rendu/PSU_2015_minishell1
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 18 14:14:00 2016 Gauthier Cler
** Last update Fri Feb 12 15:22:46 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	"../include/info.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
