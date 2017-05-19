/*
** my_strlen.c for my_strlen in /home/gauthier/rendu/CPE_2015_BSQ
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Dec  9 00:05:15 2015 Gauthier Cler
** Last update Wed Dec  9 00:05:18 2015 Gauthier Cler
*/

int	my_strlen(char *str)
{
  int	i;

  if (str[0] == 0)
    return (0);
  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}
