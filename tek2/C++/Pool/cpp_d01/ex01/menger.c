/*
** menger.c for cpp_d01 in /home/gogo/rendu/tek2/cpp_d01/ex01/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Jan  4 13:45:16 2017 Gauthier Cler
** Last update Wed Jan  4 17:43:11 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	<stdio.h>

void		format_number(int nb);

int		menger(int size, int depth, int pos_x, int pos_y)
{
  int		x;
  int		y;
  int		new_size;

  if (depth <= 0)
    return (0);
  new_size = size / 3;
  x = pos_x + new_size;
  y = pos_y + new_size;

  format_number(new_size);
  printf(" ");
  fflush(stdout);
  format_number(y);
  printf(" ");
  fflush(stdout);
  format_number(x);
  printf("\n");
  fflush(stdout);

  menger(new_size, depth - 1, x - new_size, y - new_size);
  menger(new_size, depth - 1, x, y - new_size);
  menger(new_size, depth - 1, x + new_size, y - new_size);
  menger(new_size, depth - 1, x - new_size, y);
  menger(new_size, depth - 1, x + new_size, y);
  menger(new_size, depth - 1, x - new_size, y + new_size);
  menger(new_size, depth - 1, x, y + new_size);
  menger(new_size, depth - 1, x + new_size, y + new_size);
  return (0);
}
