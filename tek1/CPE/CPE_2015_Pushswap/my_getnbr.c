/*
** my_getnbr.c for my_getnbr in /home/cler_g/rendu/pisicine/Piscine_C_J07/lib/my
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Tue Oct  6 10:52:03 2015 Gauthier Cler
** Last update Fri Nov 20 23:03:24 2015 Gauthier Cler
*/

int	minus(int j, int k)
{
  if (k > 0)
    {
      if (k % 2 != 0)
	{
	  j = -j;
	  k = 0;
	}
    }
  return (j);
}

int	my_getnbr(char *str)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  if ((str[i] < '0' || str[i] > '9') && (str[i] != '-' && str[i] != '+'))
      return (0);
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	k++;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      j = j + (str[i] - '0');
      i ++;
      if (str[i] >= '0' && str[i] <= '9')
	j = j * 10;
    }
  minus(j, k);
}
