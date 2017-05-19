/*
** mul_div.c for cpp_d02 in /home/gogo/rendu/tek2/cpp_d02/ex00/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan  5 10:06:29 2017 Gauthier Cler
** Last update Thu Jan  5 10:22:34 2017 Gauthier Cler
*/

#include	<stdio.h>

void	add_mul_4param(int first, int second, int *add, int *mul)
{
  *add = first + second;
  *mul = first * second;
}

void	add_mul_2param(int *first, int *second)
{
  int	add;

  add = *first + *second;
  *second = *first * *second;
  *first = add;
}
