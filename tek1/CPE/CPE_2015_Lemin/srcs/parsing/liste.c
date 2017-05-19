/*
** liste.c for liste in /home/cler_g/rendu/CPE_2015_Pushswap
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
**
** Started on  Thu Nov 19 18:53:40 2015 Gauthier Cler
** Last update Sat Apr 23 13:08:01 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"lemin.h"

int		add_liste(t_list **p, char *val)
{
  t_list	*save;

  if ((save = malloc(sizeof(t_list))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  if ((save->valeur = my_strdup(val)) == NULL)
    return (ERROR);
  save->next = *p;
  *p = save;
  return (SUCCESS);
}

int		add_fin_liste(t_list **p, char *val)
{
  t_list	*save;
  t_list	*tmp;

  if ((save = malloc(sizeof(t_list))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  if ((save->valeur = my_strdup(val)) == NULL)
    return (ERROR);
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
  return (SUCCESS);
}

void		disp_liste(t_list *p)
{
  while (p != NULL)
    {
      format(1, "%s\n", p->valeur);
      p = p->next;
    }
}

int		liste_len(t_list *p)
{
  int		i;

  i = 0;
  while (p != NULL)
    {
      i++;
      p = p->next;
    }
  return (i);
}
