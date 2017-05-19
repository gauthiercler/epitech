/*
** ss.c for ss in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 19:37:24 2015 Gauthier Cler
** Last update Thu Nov 19 20:45:24 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

int	ss(t_list *pa, t_list*pb)
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
  save = pb;
  i = pb->valeur;
  pb = pb->next;
  j = pb->valeur;
  if (pb == NULL)
    return (0);
  pb->valeur = i;
  save->valeur = j;
}
