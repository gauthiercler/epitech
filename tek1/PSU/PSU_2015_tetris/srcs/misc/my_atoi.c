/*
** my_atoi.c for my_atoi in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/misc
** 
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
** 
** Started on  Thu Feb 25 18:51:10 2016 Anas Buyumad
** Last update Thu Feb 25 18:51:50 2016 Anas Buyumad
*/

#include	"tetris.h"

int             my_atoi(char *str)
{
  int           i;
  int           res;

  if (str[0] == '-')
    return (-my_atoi(str + 1));
  i = 0;
  res = 0;
  while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
      res = res * 10 + str[i] - '0';
      i++;
    }
  return (res);
}
