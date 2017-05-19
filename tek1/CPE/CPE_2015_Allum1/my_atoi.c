/*
** my_atoi.c for my_atoi in /home/gogo/rendu/CPE_2015_Allum1
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Feb 10 20:28:10 2016 Gauthier Cler
** Last update Fri Feb 12 14:41:00 2016 Gauthier Cler
*/

int		my_atoi(char	*str)
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
