/*
** liste.c for liste in /home/cler_g/rendu/CPE_2015_Pushswap
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Nov 19 18:53:40 2015 Gauthier Cler
** Last update Thu Nov 19 21:22:06 2015 Gauthier Cler
*/

#include <stdlib.h>
#include "liste.h"

void	add_liste(t_list **p, int val)
{
  t_list	*save;

  save = malloc(sizeof(t_list));
  save->valeur = val;
  save->next = *p;
  *p = save;
}

void	add_fin_liste(t_list **p, int val)
{
  t_list	*save;
  t_list	*tmp;

  save = malloc(sizeof(t_list));
  save->valeur = val;
  save->next = NULL;
  if (*p == NULL)
    *p = save;
  else
    {
      tmp = *p;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = save;
    }
}
void	disp_liste(t_list *p)
{
  while (p != NULL)
    {
      my_put_nbr(p->valeur);
      my_putchar(' ');
      p = p->next;
    }
  my_putchar('\n');
}

int	liste_len(t_list *p)
{
  int	i;

  i = 0;
  while (p != NULL)
    {
      i++;
      p = p->next;
    }
  return (i);
}
