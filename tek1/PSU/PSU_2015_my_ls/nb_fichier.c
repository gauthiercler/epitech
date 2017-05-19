/*
** nb_fichier.c for nb_fichier in /home/cler_g/rendu/PSU_2015_my_ls
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Tue Nov 24 13:45:45 2015 Gauthier Cler
** Last update Sun Nov 29 16:23:51 2015 Gauthier Cler
*/

#include <dirent.h>
#include <stdlib.h>

int	nb_fichier(char *av)
{
  int	i;
  DIR	*a;
  struct dirent	*b;

  i = 0;
  a = opendir(av);
  if (a == NULL)
    return (-1);
  while ((b = readdir(a)) != NULL)
    i++;
  closedir(a);
  return (i);
}

void	error_name(char *av)
{
  my_putstr("ls: cannot access ");
  my_putstr(av);
  my_putstr(": Aucun fichier ou dossier de ce type\n");
}
