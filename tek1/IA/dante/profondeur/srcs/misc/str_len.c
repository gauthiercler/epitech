/*
** str_len.c for solver in /home/gogo/rendu/dante/profondeur/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:10:34 2016 Gauthier Cler
** Last update Wed Apr 27 23:10:36 2016 Gauthier Cler
*/

int		str_len(char *string)
{
  return (*string) ? str_len(++string) + 1 : 0;
}
