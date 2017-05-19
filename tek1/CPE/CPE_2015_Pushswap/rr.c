/*
** rr.c for rr in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 20:19:36 2015 Gauthier Cler
** Last update Fri Nov 20 09:21:01 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

int	rr(t_list **pa, t_list **pb)
{
  t_list	*tmp;
  int	val;

  if (*pa == NULL || *pb == NULL)
    return (0);
  tmp = (*pa)->next;
  val = (*pa)->valeur;
  add_fin_liste(pa, val);
  free(*pa);
  *pb = tmp;
  tmp = (*pb)->next;
  val = (*pb)->valeur;
  add_fin_liste(pb, val);
  free(*pb);
  *pb = tmp;
}
