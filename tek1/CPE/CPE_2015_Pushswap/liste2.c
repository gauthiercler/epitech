/*
** liste2.c for liste2 in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Fri Nov 20 22:59:35 2015 Gauthier Cler
** Last update Sun Nov 22 14:35:47 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

int	check_liste(t_list *p)
{
  int	i;
  int	j;
  int	k;

  j = 0;
  i = p->valeur;
  k = 0;
  while (p != NULL)
    {
      if (p->valeur > i)
	{
	  k = j;
	  i = p->valeur;
	}
      p = p->next;
      j++;
    }
  return (k);
}

int     check_start(t_list *p)
{
  while (p->next != NULL)
    {
      if (p->valeur > p->next->valeur)
	return (1);
      p = p->next;
    }
  return (0);
}
