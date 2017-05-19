/*
** rrr.c for rrr in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 21:29:34 2015 Gauthier Cler
** Last update Thu Nov 19 22:17:46 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

int	rrr(t_list **pa, t_list **pb)
{
  rra_s(pa);
  rrb_s(pb);
}

int rra_s(t_list **pa)
{
  t_list        *tmp1;
  t_list        *tmp2;

  if (*pa == NULL || (*pa)->next == NULL)
    return (0);
  tmp1 = *pa;
  tmp2 = tmp1;
  while (tmp1->next != NULL)
    {
      tmp2 = tmp1;
      tmp1 = tmp1->next;
    }
  add_liste(pa, tmp1->valeur);
  tmp2->next = NULL;
  free(tmp1);
}

int rrb_s(t_list **pb)
{
  t_list        *tmp1;
  t_list        *tmp2;

  if (*pb == NULL || (*pb)->next == NULL)
    return (0);
  tmp1 = *pb;
  tmp2 = tmp1;
  while (tmp1->next != NULL)
    {
      tmp2 = tmp1;
      tmp1 = tmp1->next;
    }
  add_liste(pb, tmp1->valeur);
  tmp2->next = NULL;
  free(tmp1);
}
