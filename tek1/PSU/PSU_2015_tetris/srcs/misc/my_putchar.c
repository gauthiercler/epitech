/*
** my_putchar.c for my_putchar in /tmp/PSU_2015_tetris/srcs/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar  1 18:04:39 2016 Gauthier Cler
** Last update Tue Mar  1 18:05:01 2016 Gauthier Cler
*/

#include	"tetris.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
