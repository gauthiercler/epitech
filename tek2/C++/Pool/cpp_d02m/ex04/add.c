/*
** add.c for cpp_d02 in /home/gogo/rendu/tek2/cpp_d02m/ex04/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan  5 13:57:48 2017 Gauthier Cler
** Last update Thu Jan  5 14:07:21 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	"castmania.h"

int	normal_add(int a, int b)
{
  return a + b;
}

int	absolute_add(int a, int b)
{
  return abs(a) + abs(b);
}

void	exec_add(t_add *operation)
{
  if (operation->add_type == NORMAL)
    operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
  else
    operation->add_op.res = absolute_add(operation->add_op.a, operation->add_op.b);
}
