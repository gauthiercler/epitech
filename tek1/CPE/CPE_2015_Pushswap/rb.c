/*
** rb.c for rb in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 20:19:36 2015 Gauthier Cler
** Last update Sat Nov 21 19:01:16 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

int	rb(t_list **pb)
{
  t_list	*tmp;
  int	val;

  if (*pb == NULL)
    return (0);
  tmp = (*pb)->next;
  val = (*pb)->valeur;
  add_fin_liste(pb, val);
  free(*pb);
  *pb = tmp;
  my_putstr("rb ");
}
