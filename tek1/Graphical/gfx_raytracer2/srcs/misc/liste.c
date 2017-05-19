/*
** liste.c for liste in /home/cler_g/rendu/CPE_2015_Pushswap
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
**
** Started on  Thu Nov 19 18:53:40 2015 Gauthier Cler
** Last update Thu May 12 14:25:17 2016 montag_v
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"raytracer.h"

int		add_liste(t_list **p, char **tab)
{
  t_list	*save;

  if ((save = bunny_malloc(sizeof(t_list))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  save->tab = tab;
  save->next = *p;
  *p = save;
  return (SUCCESS);
}

int		add_fin_liste(t_list **p, char **tab)
{
  t_list	*save;
  t_list	*tmp;

  if ((save = bunny_malloc(sizeof(t_list))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  save->tab = tab;
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
  int		i;

  while (p != NULL)
    {
      i = 0;
      while (p->tab[i] != NULL)
	{
	  format(1, "%s ", p->tab[i]);
	  i += 1;
	}
      format(1, "\n");
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
