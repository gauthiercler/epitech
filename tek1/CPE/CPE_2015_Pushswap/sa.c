/*
** sa.c for sa in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 19:26:37 2015 Gauthier Cler
** Last update Sat Nov 21 18:34:51 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

int	sa(t_list *pa)
{
  int	i;
  int	j;
  t_list	*save;

  save = pa;
  i = pa->valeur;
  pa = pa->next;
  j = pa->valeur;
  if (pa == NULL)
    return (0);
  pa->valeur = i;
  save->valeur = j;
}
