/*
** func_ptr.h for cpp_d02m in /home/gogo/rendu/tek2/cpp_d02m/ex03/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan  5 11:42:26 2017 Gauthier Cler
** Last update Thu Jan  5 12:12:48 2017 Gauthier Cler
*/

#include	"func_ptr_enum.h"

#ifndef HEADER
# define HEADER

typedef struct		s_ptr
{
  unsigned int		action_enum;
  void			(*action)(char *);
} 			t_ptr;


#endif
