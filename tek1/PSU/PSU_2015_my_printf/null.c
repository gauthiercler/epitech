/*
** null.c for null in /home/cler_g/rendu/my_printf
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
** 
** Started on  Mon Nov 16 11:03:42 2015 Gauthier Cler
** Last update Mon Nov 16 11:24:32 2015 Gauthier Cler
*/

#include <stdlib.h>
#include <stdarg.h>

int	null(va_list va)
{
  char	*str;

  str = va_arg(va, char*);
  if (str == NULL)
    my_putstr("(null)");
  else
    my_putstr(str);
}
