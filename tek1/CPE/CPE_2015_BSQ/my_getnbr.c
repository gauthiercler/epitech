/*
** my_getnbr.c for my_getnbr in /home/gauthier/rendu/CPE_2015_BSQ
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Dec  9 00:04:36 2015 Gauthier Cler
** Last update Wed Dec  9 00:04:37 2015 Gauthier Cler
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
