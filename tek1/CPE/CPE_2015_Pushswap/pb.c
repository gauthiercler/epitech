/*
** pb.c for pb in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 19:42:01 2015 Gauthier Cler
** Last update Sat Nov 21 18:09:24 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

int	pb(t_list **pa, t_list **pb)
{
  int	val;
  t_list	*tmp;

  if (*pa == NULL)
    return (0);
  tmp = (*pa)->next;
  val = (*pa)->valeur;
  add_liste(pb, val);
  free(*pa);
  *pa = tmp;
  my_putstr("pb ");
}
