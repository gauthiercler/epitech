/*
** pushswap.c for pushswap in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 18:58:57 2015 Gauthier Cler
** Last update Sun Nov 22 22:10:49 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

int	main(int ac, char **av)
{
  int	i;
  t_list	*l_a;
  t_list	*l_b;

  l_a = NULL;
  l_b = NULL;
  if (ac <= 2)
    {
      my_putchar('\n');
      return (0);
    }
  i = 0;
  while (++i <= ac - 1)
    add_fin_liste(&l_a, my_getnbr(av[i]));
  if (check_start(l_a) == 0)
    {
      my_putchar('\n');
      return (0);
    }
  while (l_a != NULL)
    pb(&l_a, &l_b);
  while (l_b != NULL)
    loop_liste(&l_a, &l_b);
}

t_list	loop_liste(t_list **l_a, t_list **l_b)
{
  int   i;
  int   a;

  a = 0;
  i = check_liste(*l_b);
  if (i > liste_len(*l_b) / 2)
    {
      i = liste_len(*l_b) - i;
      while (a++ != i)
	rrb(l_b);
    }
  else
    while (a++ != i)
      rb(l_b);
  pa(l_b, l_a);
}

t_list	loop_liste_old(t_list **l_a, t_list **l_b)
{
  int   i;
  int   a;

  a = 0;
  i = check_liste(*l_b);
  while (a++ != i)
    ra(l_b);
  pa(l_b, l_a);
}
