/*
** my_strlen.c for my_strlen in /home/cler_g/rendu/j04
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Thu Oct  1 14:13:05 2015 Gauthier Cler
** Last update Sun Nov 29 16:50:02 2015 Gauthier Cler
*/

int	my_strlen(char *str)
{
  long int	i;

  if (str[0] == 0)
    return (0);
  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}
