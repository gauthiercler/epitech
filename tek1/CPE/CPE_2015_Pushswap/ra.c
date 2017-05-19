/*
** ra.c for ra in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 20:19:36 2015 Gauthier Cler
** Last update Sat Nov 21 18:09:30 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

int	ra(t_list **pa)
{
  t_list	*tmp;
  int	val;

  if (*pa == NULL)
    return (0);
  tmp = (*pa)->next;
  val = (*pa)->valeur;
  add_fin_liste(pa, val);
  free(*pa);
  *pa = tmp;
  my_putstr("ra ");
}
