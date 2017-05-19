/*
** droits.c for droits in /home/cler_g/rendu/PSU_2015_my_ls
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Wed Nov 25 11:52:43 2015 Gauthier Cler
** Last update Sun Nov 29 17:19:24 2015 Gauthier Cler
*/

#include "info.h"

void	droits_types(t_list *file, int j)
{
  if (S_ISDIR(file[j].rights))
    file[j].droits[0] = 'd';
  else if (S_ISLNK(file[j].rights))
    file[j].droits[0] = 'l';
  else if (S_ISSOCK(file[j].rights))
    file[j].droits[0] = 's';
  else if (S_ISBLK(file[j].rights))
    file[j].droits[0] = 'b';
  else if (S_ISCHR(file[j].rights))
    file[j].droits[0] = 'c';
  else
    file[j].droits[0] = '-';
}

void	droits(t_list *file, int i)
{
  int	j;

  j = 0;
  while (j < i)
    {
      file[j].droits = malloc(sizeof(char) * 11);
      file[j].droits[10] = '\0';
      droits_types(file, j);
      file[j].droits[1] = (file[j].rights & S_IRUSR) ? 'r' : '-';
      file[j].droits[2] = (file[j].rights & S_IWUSR) ? 'w' : '-';
      file[j].droits[3] = (file[j].rights & S_IXUSR) ? 'x' : '-';
      file[j].droits[4] = (file[j].rights & S_IRGRP) ? 'r' : '-';
      file[j].droits[5] = (file[j].rights & S_IWGRP) ? 'w' : '-';
      file[j].droits[6] = (file[j].rights & S_IXGRP) ? 'x' : '-';
      file[j].droits[7] = (file[j].rights & S_IROTH) ? 'r' : '-';
      file[j].droits[8] = (file[j].rights & S_IWOTH) ? 'w' : '-';
      file[j].droits[9] = (file[j].rights & S_IXOTH) ? 'x' : '-';
      j++;
    }
}
