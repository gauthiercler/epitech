/*
** pa.c for pa in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 19:42:01 2015 Gauthier Cler
** Last update Sat Nov 21 18:09:16 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

int	pa(t_list **pb, t_list **pa)
{
  int	val;
  t_list	*tmp;

  if (*pb == NULL)
    return (0);
  val = (*pb)->valeur;
  tmp = (*pb)->next;
  add_liste(pa, val);
  free(*pb);
  *pb = tmp;
  if (*pb == 0)
    my_putstr("pa\n");
  else
    my_putstr("pa ");
}
