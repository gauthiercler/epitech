/*
** sb.c for sb in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 19:36:23 2015 Gauthier Cler
** Last update Thu Nov 19 21:31:46 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

int	sb(t_list *pb)
{
  int	i;
  int	j;
  t_list	*save;

  save = pb;
  i = pb->valeur;
  pb = pb->next;
  j = pb->valeur;
  if (pb == NULL)
    return (0);
  pb->valeur = i;
  save->valeur = j;
}
