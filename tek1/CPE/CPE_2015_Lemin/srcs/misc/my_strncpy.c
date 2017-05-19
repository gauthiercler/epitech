/*
** strncpy.c for my_strcpy in /home/montag_v/rendu/CPE_2015_corewar/asm/srcs/parser
** 
** Made by valentin montagne
** Login   <montag_v@epitech.net>
** 
** Started on  Mon Mar 21 14:39:12 2016 valentin montagne
** Last update Fri Apr 22 11:47:05 2016 montag_v
*/

#include	"lemin.h"

void		my_strncpy(char *src, char *dest, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = '\0';
}

void		my_strcpy(char *src, char *dest)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = '\0';
}
