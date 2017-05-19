/*
** my_putstr.c for my_putstr in /home/cler_g/rendu/pisicine/Piscine_C_J07/lib/my
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Tue Oct  6 10:50:21 2015 Gauthier Cler
** Last update Mon Nov 16 11:16:05 2015 Gauthier Cler
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
