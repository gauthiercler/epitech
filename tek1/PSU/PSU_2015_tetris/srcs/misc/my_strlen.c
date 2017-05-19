/*
** my_strlen.c for my_strlen in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/misc
** 
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
** 
** Started on  Thu Feb 25 17:45:09 2016 Anas Buyumad
** Last update Thu Feb 25 17:45:42 2016 Anas Buyumad
*/

#include  "tetris.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}
