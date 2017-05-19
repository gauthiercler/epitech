/*
** ex_06.h for cpp_d01 in /home/gogo/rendu/tek2/cpp_d01/ex06/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Jan  4 19:28:29 2017 Gauthier Cler
** Last update Wed Jan  4 20:27:57 2017 Gauthier Cler
*/

#ifndef HEADER_H
# define HEADER_H

typedef union	s_struct2
{
  short int	foo;
  short int	bar;
}		t_struct2;

typedef struct 	s_foo
{
  short int	foo;
  t_struct2	bar;
} 		t_struct_foo;

typedef union	u_foo
{
  unsigned int	bar;
  t_struct_foo	foo;
}		t_foo;


#endif
