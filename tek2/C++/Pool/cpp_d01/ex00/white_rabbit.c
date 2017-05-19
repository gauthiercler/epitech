/*
** white_rabbit.c for cpp_d01 in /home/gogo/rendu/tek2/cpp_d01/ex00/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Jan  4 10:56:47 2017 Gauthier Cler
** Last update Thu Jan  5 09:07:48 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<stdbool.h>

int		follow_the_white_rabbit(void)
{
  unsigned int	sum;
  bool		finished;
  unsigned int	rolled;

  rolled = 0;
  finished = false;
  sum = 0;
  while (!finished)
    {
      rolled = random() % 37 + 1;
      if (rolled == 37 || rolled == 1)
	{
	  finished = true;
	  printf("LAPIN !!!\n");
	}
      else if (rolled == 26 || rolled % 8 == 0)
	printf("derriere\n");
      else if (rolled == 4 || rolled == 5 || rolled == 6 || rolled == 8
	       || rolled == 28 || (rolled >= 17 && rolled <= 21))
	printf("gauche\n");
      else if (rolled == 13 || rolled >= 34)
	printf("droite\n");
      else if (rolled == 15 || rolled == 10 || rolled == 23)
	printf("devant\n");
      sum += rolled;
      if (!finished && sum >= 397)
	{
	  printf("LAPIN !!!\n");
	  finished = true;
	}
    }
  return (sum);
}
