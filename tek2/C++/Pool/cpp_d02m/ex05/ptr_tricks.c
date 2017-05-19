/*
** ptr_tricks.c for cpp_d02 in /home/gogo/rendu/tek2/cpp_d02m/ex05/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan  5 14:57:46 2017 Gauthier Cler
** Last update Thu Jan  5 16:23:42 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	"ptr_tricks.h"


int	get_array_nb_elem(int *ptr1, int *ptr2)
{
  return (abs(ptr1 - ptr2));
}

t_whatever	*get_struct_ptr(int *member_ptr)
{
  t_whatever	tmp;

  int diff = get_array_nb_elem((int*)&tmp, &tmp.member);
  return ((t_whatever*)(member_ptr - diff));
}
