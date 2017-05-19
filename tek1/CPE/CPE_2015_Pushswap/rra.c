/*
** rra.c for rra in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 21:29:34 2015 Gauthier Cler
** Last update Sun Nov 22 19:59:21 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

int	rra(t_list **pa)
{
  t_list	*tmp1;
  t_list	*tmp2;
  int	val;

  if (*pa == NULL || (*pa)->next == NULL)
    return (0);
  tmp1 = *pa;
  tmp2 = tmp1;
  while (tmp1->next != NULL)
    {
      tmp2 = tmp1;
      tmp1 = tmp1->next;
    }
  val = tmp1->valeur;
  tmp2->next = NULL;
  free(tmp1);
  add_liste(pa, val);
}
