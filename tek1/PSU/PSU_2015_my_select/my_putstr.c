/*
** my_putstr.c for my_putstr in /home/gauthier/rendu/PSU_2015_my_select
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Dec  8 17:50:23 2015 Gauthier Cler
** Last update Tue Dec  8 17:50:24 2015 Gauthier Cler
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i ++;
    }
}
