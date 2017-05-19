/*
** my_strlen.c for my_strlen in /home/gogo/rendu/CPE_2015_Lemin/srcs/misc
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 20 15:04:59 2016 Gauthier Cler
** Last update Wed Apr 20 15:05:20 2016 Gauthier Cler
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}
