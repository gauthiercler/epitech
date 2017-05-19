/*
** my_putstr.c for my_putstr in /home/cler_g/rendu/pisicine/Piscine_C_J07/lib/my
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Tue Oct  6 10:50:21 2015 Gauthier Cler
** Last update Sat Nov 21 18:32:04 2015 Gauthier Cler
*/

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
