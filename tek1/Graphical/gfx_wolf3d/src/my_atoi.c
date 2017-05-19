/*
** my_atoi.c for my_atoi in /home/gauthier/rendu/gfx_wolf3d/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Jan  2 17:55:58 2016 Gauthier Cler
** Last update Sat Jan  2 17:55:59 2016 Gauthier Cler
*/

int	my_atoi(const char *str)
{
  int	i;
  int	res;

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
