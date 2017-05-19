/*
** rrb.c for rrb in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 21:29:34 2015 Gauthier Cler
** Last update Sun Nov 22 20:02:17 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

int	rrb(t_list **pb)
{
  t_list	*tmp1;
  t_list	*tmp2;
  int	val;

  if (*pb == NULL || (*pb)->next == NULL)
    return (0);
  tmp1 = *pb;
  tmp2 = tmp1;
  while (tmp1->next != NULL)
    {
      tmp2 = tmp1;
      tmp1 = tmp1->next;
    }
  val = tmp1->valeur;
  tmp2->next = NULL;
  free(tmp1);
  add_liste(pb, val);
  my_putstr("rrb ");
}
