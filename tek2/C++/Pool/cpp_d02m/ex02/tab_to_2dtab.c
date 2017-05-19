/*
** tab_to_2dtab.c for cpp_d02m in /home/gogo/rendu/tek2/cpp_d02m/ex02/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan  5 10:59:17 2017 Gauthier Cler
** Last update Thu Jan  5 11:39:35 2017 Gauthier Cler
*/

#include	<stdlib.h>

void	tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int k = 0;

  (*res) = malloc(sizeof(int *) * length);
  if ((*res) == NULL)
    return ;

  for (int i = 0; i < length; i++)
    {
      (*res)[i] = malloc(sizeof(int) * width);
      if ((*res)[i] == NULL)
	return ;
      for (int j = 0; j < width; j++)
	{
	  (*res)[i][j] = tab[k];
	  k += 1;
	}
    }
}
