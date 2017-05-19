/*
** my_strlen.c for my_strlen in /home/gauthier/rendu/PSU_2015_my_select
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Dec  8 17:50:09 2015 Gauthier Cler
** Last update Tue Dec  8 17:50:10 2015 Gauthier Cler
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
