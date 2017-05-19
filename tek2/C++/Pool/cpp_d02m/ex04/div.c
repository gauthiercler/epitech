/*
** div.c for cpp_d02 in /home/gogo/rendu/tek2/cpp_d02m/ex04/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan  5 13:32:51 2017 Gauthier Cler
** Last update Thu Jan  5 14:02:52 2017 Gauthier Cler
*/

#include	"castmania.h"

int	integer_div(int a, int b)
{
  if (b == 0)
    return (0);
  return a / b;
}

float	decimal_div(int a, int b)
{
  if (b == 0)
    return 0;
  return (float)a / (float)b;
}

void	exec_div(t_div *operation)
{
  t_integer_op	*integer;
  t_decimale_op	*decimal;

  if (operation->div_type == INTEGER){
      integer = operation->div_op;
      integer->res = integer_div(integer->a, integer->b);
    }
  else{
      decimal = operation->div_op;
      decimal->res = decimal_div(decimal->a, decimal->b);
    }
}
