/*
** my_putstr.c for my_putstr in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 25 16:10:11 2016 Gauthier Cler
** Last update Tue Jan 26 21:37:37 2016 Gauthier Cler
*/

#include	"tekpaint.h"

void		my_putstr(char	*str)
{
  write(1, str, my_strlen(str));
}
