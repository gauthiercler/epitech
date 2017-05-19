/*
** main.c for lemi in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_Lemin
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 22 16:34:04 2016 Anas Buyumad
** Last update Mon Apr 25 23:26:31 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

void		ant_attack(t_lemin *lemin)
{
  while (attack_finished(lemin->graph, lemin->fourmis) != SUCCESS)
    attack(lemin);
}

int		lemin(void)
{
  t_lemin	lemin;

  lemin.list = NULL;
  if (parsing(&lemin) == ERROR)
    return (ERROR);
  if (get_paths(&lemin) == ERROR)
    return (ERROR);
  if (gen_anthill(&lemin) == ERROR)
    return (ERROR);
  ant_attack(&lemin);
  clean_struct(&lemin);
  return (SUCCESS);
}

int		main(void)
{
  if (lemin() == ERROR)
    return (1);
  return (0);
}
