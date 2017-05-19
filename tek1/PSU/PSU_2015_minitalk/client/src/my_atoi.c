/*
** my_atoi.c for my_atoi in /tmp/PSU_2015_minitalk/client/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Feb  3 16:14:29 2016 Gauthier Cler
** Last update Sun Feb 21 09:38:05 2016 Gauthier Cler
*/

int		my_atoi(unsigned char	*str)
{
  int		i;
  int		res;

  if (str[0] == '-')
    return (-my_atoi(str + 1));
  i = 0;
  res = 0;
  while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
      res = res * 10 + str[i] - '0';
      i++;
    }
  return (res);
}
