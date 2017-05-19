/*
** my_strlen.c for my_strlen in /home/gauthier/rendu/PSU_2015_minishell1/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 18 14:59:48 2016 Gauthier Cler
** Last update Sun Jan 24 18:15:00 2016 Gauthier Cler
*/

#include	"../include/info.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_strlen_double(char **str)
{
  int	i;

  i = 0;
  while (str[i])
    i+= 1;
  return (i);
}
